#include "main.h"

// set up DMA descriptors (one for each frame, then repeat)
// small descriptor model, only start address needs to be fetched
tDMA_descriptor DMA_PPI1_first={&DMA_PPI1_second, sFrame16};
tDMA_descriptor DMA_PPI1_second={&DMA_PPI1_third , sFrame16};
tDMA_descriptor DMA_PPI1_third={&DMA_PPI1_fourth, sFrame16};
tDMA_descriptor DMA_PPI1_fourth={&DMA_PPI1_fifth , sFrame16};
tDMA_descriptor DMA_PPI1_fifth ={&DMA_PPI1_sixth, sFrame24};
tDMA_descriptor DMA_PPI1_sixth={&DMA_PPI1_seventh, sFrame24};
tDMA_descriptor DMA_PPI1_seventh={&DMA_PPI1_eigth, sFrame24};
tDMA_descriptor DMA_PPI1_eigth={&DMA_PPI1_nineth, sFrame24};
tDMA_descriptor DMA_PPI1_nineth={&DMA_PPI1_tenth, sFrame24};
tDMA_descriptor DMA_PPI1_tenth={&DMA_PPI1_eleventh, sFrame24};
tDMA_descriptor DMA_PPI1_eleventh={&DMA_PPI1_twelfth, sFrame24};
tDMA_descriptor DMA_PPI1_twelfth={&DMA_PPI1_thirteenth, sFrame24};
tDMA_descriptor DMA_PPI1_thirteenth={&DMA_PPI1_fourteenth, sFrame0};
tDMA_descriptor DMA_PPI1_fourteenth={&DMA_PPI1_fifteenth, sFrame0};
tDMA_descriptor DMA_PPI1_fifteenth={&DMA_PPI1_sixteenth, sFrame0};
tDMA_descriptor DMA_PPI1_sixteenth={&DMA_PPI1_seventeenth, sFrame0};
tDMA_descriptor DMA_PPI1_seventeenth={&DMA_PPI1_eighteenth, sFrame0};
tDMA_descriptor DMA_PPI1_eighteenth={&DMA_PPI1_nineteenth, sFrame0};
tDMA_descriptor DMA_PPI1_nineteenth={&DMA_PPI1_twentieth, sFrame0};
tDMA_descriptor DMA_PPI1_twentieth={&DMA_PPI1_twentyfirst, sFrame0};
tDMA_descriptor DMA_PPI1_twentyfirst={&DMA_PPI1_twentysecond, sFrame8};
tDMA_descriptor DMA_PPI1_twentysecond={&DMA_PPI1_twentythird, sFrame8};
tDMA_descriptor DMA_PPI1_twentythird={&DMA_PPI1_twentyfourth, sFrame8};
tDMA_descriptor DMA_PPI1_twentyfourth={&DMA_PPI1_twentyfifth, sFrame8};
tDMA_descriptor DMA_PPI1_twentyfifth={&DMA_PPI1_twentysixth, sFrame8};
tDMA_descriptor DMA_PPI1_twentysixth={&DMA_PPI1_twentyseventh, sFrame8};
tDMA_descriptor DMA_PPI1_twentyseventh={&DMA_PPI1_twentyeighth, sFrame8};
tDMA_descriptor DMA_PPI1_twentyeighth={&DMA_PPI1_twentyninth, sFrame8};
tDMA_descriptor DMA_PPI1_twentyninth={&DMA_PPI1_thirtiest, sFrame16};
tDMA_descriptor DMA_PPI1_thirtiest={&DMA_PPI1_thirtyfirst, sFrame16};
tDMA_descriptor DMA_PPI1_thirtyfirst={&DMA_PPI1_thirtysecond, sFrame16};
tDMA_descriptor DMA_PPI1_thirtysecond={&DMA_PPI1_first, sFrame16};


volatile int current_out_Frame = -1;		// 0, 1, 2 or 3  ... indicates the last frame that is output COMPLETELY

bool Set_PACK32 = false;



// User program
void main() {

	// set Clocks
	Set_PLL( (short)(CORECLK/CLKIN), (short)(CORECLK/SYSCLK));			// sets Core and System Clocks to the values defined in system.h 

	// initialise PPI0 and associated DMA channel for Video IN
	
	current_out_Frame  = -1;				// no frames transmitted yet
	Set_PACK32 = false;
#ifdef PACK_32
	Set_PACK32 = true;
#endif

	InitPPI1(Set_PACK32, &DMA_PPI1_first, PIXEL_PER_LINE, LINES_PER_FRAME);
	
	// initialise Interrupts
	InitInterrupts_coreB();
	

	// now ready to kick off PPI output stream. 
	// Just wait for core A to indicate that a valid frame has been received
	while (!semaphore_frames_received);				// loop until core A sets the semaphore
	semaphore_frames_received = false;
	
    // start transfers
	EnablePPI1();


	
	
	// main loop, just wait for interrupts
	while(1) {
		idle();				//   do nothing

		// check for core A to reset the video
		if (semaphoreResetVideo)
		{
			semaphoreResetVideo = false;
			
			DisablePPI1();
			
			
			InitPPI1(Set_PACK32, &DMA_PPI1_first, PIXEL_PER_LINE, LINES_PER_FRAME);
			
			while (!semaphore_frames_received);				// loop until core A sets the semaphore
			semaphore_frames_received = false;
			
			EnablePPI1();
			
		}

	}	// while(1)
		
	
}		// main

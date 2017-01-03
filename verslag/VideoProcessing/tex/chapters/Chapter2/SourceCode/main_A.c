#include "main.h"
#include "video.h"


// set up DMA descriptors (one for each frame, then repeat)
// small descriptor model, only start address needs to be fetched

tDMA_descriptor DMA_PPI0_first = {&DMA_PPI0_second, sFrame0};
tDMA_descriptor DMA_PPI0_second = {&DMA_PPI0_third , sFrame1};
tDMA_descriptor DMA_PPI0_third = {&DMA_PPI0_fourth, sFrame2};
tDMA_descriptor DMA_PPI0_fourth = {&DMA_PPI0_fifth , sFrame3};
tDMA_descriptor DMA_PPI0_fifth ={&DMA_PPI0_sixth, sFrame4};
tDMA_descriptor DMA_PPI0_sixth={&DMA_PPI0_seventh, sFrame5};
tDMA_descriptor DMA_PPI0_seventh={&DMA_PPI0_eigth, sFrame6};
tDMA_descriptor DMA_PPI0_eigth={&DMA_PPI0_nineth, sFrame7};
tDMA_descriptor DMA_PPI0_nineth={&DMA_PPI0_tenth, sFrame8};
tDMA_descriptor DMA_PPI0_tenth={&DMA_PPI0_eleventh, sFrame9};
tDMA_descriptor DMA_PPI0_eleventh={&DMA_PPI0_twelfth, sFrame10};
tDMA_descriptor DMA_PPI0_twelfth={&DMA_PPI0_thirteenth, sFrame11};
tDMA_descriptor DMA_PPI0_thirteenth={&DMA_PPI0_fourteenth, sFrame12};
tDMA_descriptor DMA_PPI0_fourteenth={&DMA_PPI0_fifteenth, sFrame13};
tDMA_descriptor DMA_PPI0_fifteenth={&DMA_PPI0_sixteenth, sFrame14};
tDMA_descriptor DMA_PPI0_sixteenth={&DMA_PPI0_seventeenth, sFrame15};
tDMA_descriptor DMA_PPI0_seventeenth={&DMA_PPI0_eighteenth, sFrame16};
tDMA_descriptor DMA_PPI0_eighteenth={&DMA_PPI0_nineteenth, sFrame17};
tDMA_descriptor DMA_PPI0_nineteenth={&DMA_PPI0_twentieth, sFrame18};
tDMA_descriptor DMA_PPI0_twentieth={&DMA_PPI0_twentyfirst, sFrame19};
tDMA_descriptor DMA_PPI0_twentyfirst={&DMA_PPI0_twentysecond, sFrame20};
tDMA_descriptor DMA_PPI0_twentysecond={&DMA_PPI0_twentythird, sFrame21};
tDMA_descriptor DMA_PPI0_twentythird={&DMA_PPI0_twentyfourth, sFrame22};
tDMA_descriptor DMA_PPI0_twentyfourth={&DMA_PPI0_twentyfifth, sFrame23};
tDMA_descriptor DMA_PPI0_twentyfifth={&DMA_PPI0_twentysixth, sFrame24};
tDMA_descriptor DMA_PPI0_twentysixth={&DMA_PPI0_twentyseventh, sFrame25};
tDMA_descriptor DMA_PPI0_twentyseventh={&DMA_PPI0_twentyeighth, sFrame26};
tDMA_descriptor DMA_PPI0_twentyeighth={&DMA_PPI0_twentyninth, sFrame27};
tDMA_descriptor DMA_PPI0_twentyninth={&DMA_PPI0_thirtiest, sFrame28};
tDMA_descriptor DMA_PPI0_thirtiest={&DMA_PPI0_thirtyfirst, sFrame29};
tDMA_descriptor DMA_PPI0_thirtyfirst={&DMA_PPI0_thirtysecond, sFrame30};
tDMA_descriptor DMA_PPI0_thirtysecond={&DMA_PPI0_first, sFrame31};


volatile int current_in_Frame  = -1;		// 0, 1, 2 or 3  ... indicates the last frame that was received COMPLETELY

bool Set_PACK32 = false;
bool Set_Entire_Field = false;


// User program
void main() {

	// unblock Core B if dual core operation is desired	
#ifndef RUN_ON_SINGLE_CORE
	*pSICA_SYSCR &= 0xFFDF; // clear bit 5 to unlock  
#endif

	// set Clocks
	Set_PLL( (short)(CORECLK/CLKIN), (short)(CORECLK/SYSCLK));			// sets Core and System Clocks to the values defined in system.h 

	// initialise SDRAM
	InitSDRAM();
	*pTC_PER = 0x0770;			// set DMA traffic control register to favour unidirectional transfers to SDRAM

	// initialise Video Encoder ADV7179
	Reset_ADV7179();

	// initialise Video Decoder ADV7183
	Reset_ADV7183();
	
	
	// initialise PPI0 and associated DMA channel for Video IN
	current_in_Frame  = -1;				// no frames received yet
	semaphore_frames_received = false;	// do not start output stream yet

	Set_Entire_Field = false;
#ifdef ENTIRE_FIELD_MODE
	Set_Entire_Field = true;
#endif

	Set_PACK32 = false;
#ifdef PACK_32
	Set_PACK32 = true;
#endif
	
	InitPPI0(Set_Entire_Field, Set_PACK32, &DMA_PPI0_first, PIXEL_PER_LINE, LINES_PER_FRAME);
	

		
	// initialise Interrupts
	InitInterrupts_coreA();
	
	
	// enable transfers
	EnablePPI0();


	
	// main loop, just wait for interrupts
	while(1) {
		idle();		//   do nothing
		
		current_in_Frame++;
		current_in_Frame = current_in_Frame % 32;
		if(current_in_Frame > 23)
			current_in_Frame = 0;
		else if(current_in_Frame > 15)
			current_in_Frame = 24;
		else if(current_in_Frame > 7)
			current_in_Frame = 16;
		else
			current_in_Frame = 8;
		
		process();

		if (*pPPI0_STATUS & FT_ERR)
		{
			// error occurred -- clear error and restart video transfer
			*pPPI0_STATUS &= ~FT_ERR;
			semaphoreResetVideo = true;
			
			while(semaphoreResetVideo);     // wait for core B to reset video
			
			DisablePPI0();
			current_in_Frame  = -1;         // no frames received yet
			semaphore_frames_received = false;
			
			InitPPI0(Set_Entire_Field, Set_PACK32, &DMA_PPI0_first, PIXEL_PER_LINE, LINES_PER_FRAME);
			EnablePPI0();
		}

	}	// while(1)
		
	
}		// main


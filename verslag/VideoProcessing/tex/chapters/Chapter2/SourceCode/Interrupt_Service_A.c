#include "main.h"


/********************************************************************************/
/***** Defines the interrupt service routines for CoreA						*****/
/********************************************************************************/


EX_INTERRUPT_HANDLER(PPI0_RxIsr) {

	*pDMA1_0_IRQ_STATUS |= DMA_DONE;		// acknowledge interrupt
	
	semaphore_frames_received = true;		// signal core B that a frame was received
}



EX_EXCEPTION_HANDLER(ex_handler_coreA) {
	while(1);
}


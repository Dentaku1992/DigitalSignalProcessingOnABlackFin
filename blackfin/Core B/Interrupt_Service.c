#include "main.h"
#include "video.h"

/********************************************************************************/
/***** Defines the interrupt service routines for CoreB						*****/
/********************************************************************************/


EX_INTERRUPT_HANDLER(PPI1_TxIsr) {

	*pDMA1_1_IRQ_STATUS |= DMA_DONE;		// acknowledge interrupt

	++current_out_Frame;
	current_out_Frame = current_out_Frame % 32;
}



EX_EXCEPTION_HANDLER(ex_handler_coreB) {
	while(1);
}

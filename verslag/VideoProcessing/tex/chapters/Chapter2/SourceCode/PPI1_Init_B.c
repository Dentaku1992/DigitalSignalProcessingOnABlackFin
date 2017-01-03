#include "main.h"

/********************************************************************************/
/***** InitPPI1()															*****/
/***** PPI1 is configured for video out in GP output 1FS mode				*****/
/***** This routine configures both the PPI and the associated DMA channel	*****/
/***** Supports  8 and 32 bit packing according to the input parameters		*****/
/***** DMA is setup in descriptor list mode, input is pointer to 1st header	*****/
/********************************************************************************/

void InitPPI1(bool pack32, tDMA_descriptor* First_Header, short pixel, short lines)
{ short transfer_length_bytes = ((pack32) ? 4 : 1);

	// configure Timer10 for PPI frame sync - not enabled yet
	*pTMRS4_DISABLE = TIMDIS10;						//disable Timer
	*pTMRS4_STATUS = (TIMIL10 | TOVL_ERR10 | TRUN10);	// clear status

	*pTIMER10_PERIOD = pixel * sizeof(short);
	*pTIMER10_WIDTH = 0x10;		// some small dutycycle
	*pTIMER10_CONFIG   = TIN_SEL | PWM_OUT | PULSE_HI | PERIOD_CNT | CLK_SEL | EMU_RUN;	
	ssync();
	
	// configure PPI1 - not enabled yet
	*pPPI1_CONTROL = PORT_DIR | XFR_TYPE | (pack32 << 7)| (pack32 << 8);
	*pPPI1_COUNT = pixel * sizeof(short);					// 2 bytes for each pixel
	ssync();

	// configure DMA for PPI1 - not enabled yet
	*pDMA1_1_X_COUNT = pixel * sizeof(short) / transfer_length_bytes;	// 2 bytes for each pixel, count divided by four if 32-bit DMA transfers are done
	*pDMA1_1_Y_COUNT = lines;
	*pDMA1_1_X_MODIFY = transfer_length_bytes;		
	*pDMA1_1_Y_MODIFY = transfer_length_bytes;		
	*pDMA1_1_NEXT_DESC_PTR = First_Header;
	*pDMA1_1_CONFIG = 0x7000 |1 << 5| 0x0400 | DI_EN | DMA2D | (pack32 << 3);
	//*pDMA1_1_CONFIG = 0x7000 | 0x0400 | DI_EN | DMA2D | (pack32 << 3);
	ssync();
	
}

void
DisablePPI1()
    {
    // stop transfers
    *pTMRS4_ENABLE &= ~TIMEN10;
    ssync();
    *pPPI1_CONTROL &= ~PORT_EN;
    ssync();
    *pDMA1_1_CONFIG &= ~DMAEN;
    ssync();
    }

void
EnablePPI1()
    {
    // start transfers
    *pDMA1_1_CONFIG |= DMAEN;
    ssync();
    *pPPI1_CONTROL |= PORT_EN;
    ssync();
    *pTMRS4_ENABLE |= TIMEN10;
    ssync();
    }

#include "main.h"

/********************************************************************************/
/***** InitPPI0()															*****/
/***** PPI0 is configured for video in in 656 mode							*****/
/***** This routine configures both the PPI and the associated DMA channel	*****/
/***** Supports Entire Field and active video only, as well as 8 and 32 bit *****/
/***** packing according to the input parameters							*****/
/***** DMA is setup in descriptor list mode, input is pointer to 1st header	*****/
/********************************************************************************/

void InitPPI0(bool entire_field, bool pack32, tDMA_descriptor* First_Header, short pixel, short lines)
{ short transfer_length_bytes = ((pack32) ? 4 : 1);

	// configure PPI0 - not enabled yet
	*pPPI0_CONTROL = (entire_field << 2) | FLD_SEL | (pack32 << 7)| (pack32 << 8);
	*pPPI0_FRAME = lines;
	ssync();

	// configure DMA for PPI0 - not enabled yet
	*pDMA1_0_X_COUNT = pixel * sizeof(short) / transfer_length_bytes;	// 2 bytes for each pixel, count divided by four if 32-bit DMA transfers are done
	*pDMA1_0_Y_COUNT = lines;
	*pDMA1_0_X_MODIFY = transfer_length_bytes;		
	*pDMA1_0_Y_MODIFY = transfer_length_bytes;		
	*pDMA1_0_NEXT_DESC_PTR = First_Header;
	*pDMA1_0_CONFIG = 0x7000 | 0x0400 | DI_EN | DMA2D | (pack32 << 3) | WNR; //0x6000
	
	ssync();
	
}


void DisablePPI0(void)
    {
    // disable transfers
    *pPPI0_CONTROL &= ~PORT_EN;
    ssync();
    *pDMA1_0_CONFIG &= ~DMAEN;
    ssync();
    }


void EnablePPI0(void)
    {
    // enable transfers
    *pDMA1_0_CONFIG |= DMAEN;
    ssync();
    *pPPI0_CONTROL |= PORT_EN;
    ssync();
    }

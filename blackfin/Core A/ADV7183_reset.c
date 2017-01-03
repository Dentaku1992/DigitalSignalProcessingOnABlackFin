#include "main.h"

/********************************************************************************/
/***** Reset_ADV7183()														*****/
/***** Resets the Video decoder through PF2									*****/
/********************************************************************************/


// specific defines for this module. Not used anywhere else
#define ADV7183_OE_bit 2   					// ADV7183 /OE = PF2
#define ADV7183_RESET_bit 13   				// ADV7183 /reset = PF13
#define ADV7183_Reset_Delay   0x04000000   	// For delay after reset



void Reset_ADV7183(void )
{ long delay_time;

	// configure OE and RESET flags as output
	*pFIO0_DIR |= (1 << ADV7183_OE_bit) | (1 << ADV7183_RESET_bit);
	ssync();

	// disable outputs
	*pFIO0_FLAG_S = (1 << ADV7183_OE_bit);	// set bit to disable ADV7183 outputs
	ssync();

	// generate reset pulse
	*pFIO0_FLAG_C = (1 << ADV7183_RESET_bit);	// clear bit to reset ADV7183 
	ssync();

	*pFIO0_FLAG_S = (1 << ADV7183_RESET_bit);	// set bit to re-enable ADV7183 
	ssync();

	for (delay_time = 0; delay_time < ADV7183_Reset_Delay; delay_time++)
			asm("nop;");

	// now enable outputs
	*pFIO0_FLAG_C = (1 << ADV7183_OE_bit);	// clear bit to enable ADV7183 outputs
	ssync();

}



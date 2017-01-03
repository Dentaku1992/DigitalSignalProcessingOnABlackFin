#include "main.h"

/********************************************************************************/
/***** Reset_ADV7179()														*****/
/***** Resets the Video encoder through PF14								*****/
/********************************************************************************/


// specific defines for this module. Not used anywhere else
#define ADV7179_RESET_bit 14   				// ADV7179 /reset = PF14

#define ADV7179_Reset_Delay   0x0000ffff    	// For reset pulse length


void Reset_ADV7179(void )
{ long delay_time;

	// configure RESET flag as output
	*pFIO0_DIR |= (1 << ADV7179_RESET_bit);
	ssync();

	// generate reset pulse
	*pFIO0_FLAG_C = (1 << ADV7179_RESET_bit);	// clear bit to reset ADV7179 
	ssync();

	*pFIO0_FLAG_S = (1 << ADV7179_RESET_bit);	// set bit to re-enable ADV7179 
	ssync();

}



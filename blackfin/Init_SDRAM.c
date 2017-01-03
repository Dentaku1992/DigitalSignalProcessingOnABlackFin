#include "main.h"

/********************************************************************************/
/***** InitSDRAM()															*****/
/********************************************************************************/

void InitSDRAM(void)
{

	// Check if already enabled
	if (*pEBIU_SDSTAT & SDRS) {
		*pEBIU_SDBCTL = 0x00000015;					//SDRAM Memory Bank Control Register
		ssync();
		*pEBIU_SDRRC =  0x000003a9;					//SDRAM Refresh Rate Control Register
		ssync();
		*pEBIU_SDGCTL = 0x0091998f;					//SDRAM Memory Global Control Register
		ssync();
	}

}


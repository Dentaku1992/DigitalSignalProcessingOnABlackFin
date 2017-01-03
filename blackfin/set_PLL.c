/********************************************************************************/
/***** Set_PLL(CoreCLOCK_multiplier, SCLK_divider)							*****/
/***** Sets core and system clock 											*****/
/********************************************************************************/

// only MSEL and SSEL supported at this time
// no checks for invalid or out of range settings

// The routines makes use of Core B's Supplemental Interrupt 0 
// to synchronise entering the idle state

// Link the routine in both cores' L1 memory and call from each core


#include "main.h"


void Set_PLL(short CoreCLOCK_multiplier, short SCLK_divider)
{ short previous_PLL= *pPLL_CTL;
  short previous_SICA_IWR = *pSICA_IWR0;
  short previous_SICB_IWR = *pSICB_IWR0;
  short new_PLL= (previous_PLL & 0x81ff) | ((CoreCLOCK_multiplier & 0x3f) <<9);
   
  if (new_PLL != previous_PLL) {			  // skip if multiplier has not changed
		  	
	 if ((int)(*pSRAM_BASE_ADDRESS) == 0xFF800000 ) {						  // do things for Core A

	 	*pSICB_SYSCR |= 0x0080;				// Raise Core B Supplemental-Int0
		ssync();

	 	while((*pSICB_SYSCR & 0x080)) {		// Wait: Core B Acknowledge SUP-B0
			asm volatile ("nop;nop;nop;nop;"); 
		} 	
	 
	 	*pSICA_IWR0 = (previous_SICA_IWR | 0x1); // enable PLL Wakeup Interrupt
  		*pPLL_CTL = new_PLL;
		ssync();
  		
  		idle();							  // put in idle

  		*pSICA_IWR0 = previous_SICA_IWR;		  // continue here after idle, restore previous IWR content
		ssync();
	  }
	else{							  		  // do things for Core B

		while(!(*pSICB_SYSCR & 0x0080))	{		// Wait: For Core A to raise SUP-B0 
			asm volatile ("nop;nop;nop;nop;"); 
		}
			
		*pSICB_SYSCR = 0x0800;		// Acknowledge Supplemental Interrupt
		ssync();
	
		*pSICB_IWR0 = (previous_SICB_IWR | 0x1); // enable PLL Wakeup Interrupt
		ssync();
  		
  		idle();							  // put in idle

  		*pSICB_IWR0 = previous_SICB_IWR;		  // continue here after idle, restore previous IWR content
		ssync();
	
    }	// if (&_CORE == 0)
		
  }   // if (new_PLL != previous_PLL)

  *pPLL_DIV = (*pPLL_DIV & 0xFFF0) | SCLK_divider;
  ssync();
  
}




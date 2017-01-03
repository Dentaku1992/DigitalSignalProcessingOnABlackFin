#ifndef  __MAIN_DEFINED
#define __MAIN_DEFINED

#include "..\system.h"


/********************************************************************************/
/***** Global variables	and types											*****/
/***** All global variables are defined in main.c							*****/
/********************************************************************************/

// scalars
extern volatile int current_out_Frame;


// DMA descriptor lists 

struct sDMA_descriptor {struct sDMA_descriptor* next_descriptor;
					    volatile short *start_address;
};
typedef struct sDMA_descriptor tDMA_descriptor;


extern tDMA_descriptor DMA_PPI1_first ;
extern tDMA_descriptor DMA_PPI1_second ;
extern tDMA_descriptor DMA_PPI1_third ;
extern tDMA_descriptor DMA_PPI1_fourth ;
extern tDMA_descriptor DMA_PPI1_fifth ;
extern tDMA_descriptor DMA_PPI1_sixth;
extern tDMA_descriptor DMA_PPI1_seventh;
extern tDMA_descriptor DMA_PPI1_eigth;
extern tDMA_descriptor DMA_PPI1_nineth;
extern tDMA_descriptor DMA_PPI1_tenth;
extern tDMA_descriptor DMA_PPI1_eleventh;
extern tDMA_descriptor DMA_PPI1_twelfth;
extern tDMA_descriptor DMA_PPI1_thirteenth;
extern tDMA_descriptor DMA_PPI1_fourteenth;
extern tDMA_descriptor DMA_PPI1_fifteenth;
extern tDMA_descriptor DMA_PPI1_sixteenth;
extern tDMA_descriptor DMA_PPI1_seventeenth;
extern tDMA_descriptor DMA_PPI1_eighteenth;
extern tDMA_descriptor DMA_PPI1_nineteenth;
extern tDMA_descriptor DMA_PPI1_twentieth;
extern tDMA_descriptor DMA_PPI1_twentyfirst;
extern tDMA_descriptor DMA_PPI1_twentysecond;
extern tDMA_descriptor DMA_PPI1_twentythird;
extern tDMA_descriptor DMA_PPI1_twentyfourth;
extern tDMA_descriptor DMA_PPI1_twentyfifth;
extern tDMA_descriptor DMA_PPI1_twentysixth;
extern tDMA_descriptor DMA_PPI1_twentyseventh;
extern tDMA_descriptor DMA_PPI1_twentyeighth;
extern tDMA_descriptor DMA_PPI1_twentyninth;
extern tDMA_descriptor DMA_PPI1_thirtiest;
extern tDMA_descriptor DMA_PPI1_thirtyfirst;
extern tDMA_descriptor DMA_PPI1_thirtysecond;


/********************************************************************************/
/***** Prototypes functions													*****/
/********************************************************************************/


void InitPPI1(bool pack32, tDMA_descriptor* First_Header, short pixel, short lines);
void EnablePPI1(void);
void DisablePPI1(void);

void Set_PLL(short CoreCLOCK_multiplier, short SCLK_divider);


/********************************************************************************/
/***** Prototypes interrupts												*****/
/********************************************************************************/

void InitInterrupts_coreB(void);

EX_INTERRUPT_HANDLER(PPI1_TxIsr);

EX_EXCEPTION_HANDLER(ex_handler_coreB);


#endif


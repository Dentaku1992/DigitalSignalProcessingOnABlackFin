#ifndef  __MAIN_DEFINED
#define __MAIN_DEFINED

#include "..\system.h"

/********************************************************************************/
/***** Current Global variables	and types									*****/
/***** All global variables are defined in main.c							*****/
/********************************************************************************/

// scalars
extern volatile int current_in_Frame;
extern volatile int current_out_Frame;

// DMA descriptor lists 

struct sDMA_descriptor {struct sDMA_descriptor* next_descriptor;
					    volatile short *start_address;
};
typedef struct sDMA_descriptor tDMA_descriptor;


extern tDMA_descriptor DMA_PPI0_first ;
extern tDMA_descriptor DMA_PPI0_second ;
extern tDMA_descriptor DMA_PPI0_third ;
extern tDMA_descriptor DMA_PPI0_fourth ;
extern tDMA_descriptor DMA_PPI0_fifth ;
extern tDMA_descriptor DMA_PPI0_sixth;
extern tDMA_descriptor DMA_PPI0_seventh;
extern tDMA_descriptor DMA_PPI0_eigth;
extern tDMA_descriptor DMA_PPI0_nineth;
extern tDMA_descriptor DMA_PPI0_tenth;
extern tDMA_descriptor DMA_PPI0_eleventh;
extern tDMA_descriptor DMA_PPI0_twelfth;
extern tDMA_descriptor DMA_PPI0_thirteenth;
extern tDMA_descriptor DMA_PPI0_fourteenth;
extern tDMA_descriptor DMA_PPI0_fifteenth;
extern tDMA_descriptor DMA_PPI0_sixteenth;
extern tDMA_descriptor DMA_PPI0_seventeenth;
extern tDMA_descriptor DMA_PPI0_eighteenth;
extern tDMA_descriptor DMA_PPI0_nineteenth;
extern tDMA_descriptor DMA_PPI0_twentieth;
extern tDMA_descriptor DMA_PPI0_twentyfirst;
extern tDMA_descriptor DMA_PPI0_twentysecond;
extern tDMA_descriptor DMA_PPI0_twentythird;
extern tDMA_descriptor DMA_PPI0_twentyfourth;
extern tDMA_descriptor DMA_PPI0_twentyfifth;
extern tDMA_descriptor DMA_PPI0_twentysixth;
extern tDMA_descriptor DMA_PPI0_twentyseventh;
extern tDMA_descriptor DMA_PPI0_twentyeighth;
extern tDMA_descriptor DMA_PPI0_twentyninth;
extern tDMA_descriptor DMA_PPI0_thirtiest;
extern tDMA_descriptor DMA_PPI0_thirtyfirst;
extern tDMA_descriptor DMA_PPI0_thirtysecond;


/********************************************************************************/
/***** Prototypes functions													*****/
/********************************************************************************/


void InitPPI0(bool entire_field, bool pack32, tDMA_descriptor* First_Header, short pixel, short lines);
void DisablePPI0(void);
void EnablePPI0(void);
void Reset_ADV7183(void );
void Reset_ADV7179(void );

void InitSDRAM(void);
void Set_PLL(short CoreCLOCK_multiplier, short SCLK_divider);


/********************************************************************************/
/***** Prototypes interrupts												*****/
/********************************************************************************/

void InitInterrupts_coreA(void);

EX_INTERRUPT_HANDLER(PPI0_RxIsr);

EX_EXCEPTION_HANDLER(ex_handler_coreA);



#endif


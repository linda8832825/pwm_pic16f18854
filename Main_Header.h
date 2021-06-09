#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> 

#include "pic16f18854.h"

#define INTERRUPT_GlobalInterruptEnable() (INTCONbits.GIE = 1)
#define INTERRUPT_PeripheralInterruptEnable() (INTCONbits.PEIE = 1)

#define TRIS_LED        TRISAbits.TRISA0
#define TRIS_SW         TRISAbits.TRISA1 //±Ò°Ê¶s
#define TRIS_CHARGE1    TRISAbits.TRISA2
#define TRIS_CHARGE2    TRISAbits.TRISA3
#define TRIS_SCL        TRISCbits.TRISC3
#define TRIS_SDA        TRISCbits.TRISC4
#define TRIS_TX         TRISCbits.TRISC7
#define TRIS_RX         TRISCbits.TRISC6
#define TRIS_Voltage    TRISBbits.TRISB0 //°»´ú¹q¦À¹qÀ£

#define duty0dot5       0x00FC
#define duty0dot7       0x0161
#define duty1           0x01F8

#define OUTPUT 0
#define INPUT  1

void initial(void) ;
void PWM_Initialize();
void PIN_Initialize();
void OSCILLATOR_Initialize(void);

#endif

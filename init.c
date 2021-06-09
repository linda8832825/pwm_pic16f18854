#include "Main_Header.h"

void initial(void) {
    OSCILLATOR_Initialize();
    PIN_Initialize();
    PWM_Initialize();
    

}

void PWM_Initialize(){//1K hz
    PMD3bits.PWM6MD=0; //�ҥ� PWM6 �Ҷ�
    T2CONbits.ON=1; //�}��timer2
    T2CONbits.CKPS=0b001; //1:2�w���W��
    PR2=0x7D; //125
    PWM6CONbits.EN=1;//����pwm6
    PWM6CONbits.OUT=1;//���T�w�o�ӬO���O�o�˵� //�Pı�O�]1�����q��
    PWM6CONbits.POL=0;//��X�����q�즳��
//    PWM6DC=0x0000; //���T�w�ण��o�˳] �]���o�Ӧ�m�������a��
    
    
    
}

void PIN_Initialize(){
    TRIS_LED = OUTPUT;
    TRIS_SW  = INPUT;
    TRIS_CHARGE1 = OUTPUT;
    TRIS_CHARGE2 = OUTPUT;
    TRIS_SCL     = OUTPUT;
    TRIS_SDA     = OUTPUT;
    TRIS_TX      = OUTPUT;
    TRIS_RX      = INPUT;

            
    RA2PPS = 0x0E;//��RA2���V��PWM6OUT
    RA3PPS = 0x0E;//��RA3���V��PWM6OUT
    
            
    SSP1CLKPPS = 0x13;   //RC3->MSSP1:SCL1;    
    RC3PPS = 0x14;   //RC3->MSSP1:SCL1;    
    RC4PPS = 0x15;   //RC4->MSSP1:SDA1;    
    SSP1DATPPS = 0x14;   //RC4->MSSP1:SDA1;     
}
void OSCILLATOR_Initialize(void)
{
    // NOSC HFINTOSC; NDIV 4; 
    OSCCON1 = 0x62;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 4_MHz; 
    OSCFRQ = 0x02;
    // HFTUN 0; 
    OSCTUNE = 0x00;
}
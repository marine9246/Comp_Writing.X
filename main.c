/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16F1509
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */
/******************************************************************************
 *$B%3%s%W=q$-9~$_!!<B83MQ(B $B=i4|8!F$MQ(B
 * 2048Hz$B!!!J(BO1,O3$B!K$H(B(O2,O4)$B$r8r8_$K8!=P$7!"(BVrs$B8!=P$7$?$i!"%]!<%H$h$j(B"H"$B$r(B100usec$B=PNO(B
 * SPK$BF14|MQ?.9f$H$7$F(BSINC$B!J(BRC7$B!K$r=PNO(B
 ******************************************************************************/
/*******************************************************************************
 @brief     TMR2$B3d$j9~$_$G%b!<%?$r6nF0$5$;$k(B
 @note      MOTOR$B%]!<%H3dEv(B
    VDD:1 VSS:20
    RAx
    |bit7   |bit6   |bit5   |bit4   |bit3   |bit2   |bit1   |bit0   |
    |-      |-      |RA5    |RA4    |RA3    |RA2    |RA1    |RA0    |
    |-      |-      |-      |SWA    |-      |C1OUT  |M0_1   |RCIV1  |
PIN |-      |-      |2      |3      |4      |17     |18     |19     |
    RBx
    |bit7   |bit6   |bit5   |bit4   |bit3   |bit2   |bit1   |bit0   |
    |RB7    |RB6    |RB5    |RB4    |-      |-      |-      |-      |
    |OP4    |OP3    |OP2    |OP1    |-      |-      |-      |-      |
PIN |10     |11     |12     |13     |       |       |       |       |

    RCx
    |bit7   |bit6   |bit5   |bit4   |bit3   |bit2   |bit1   |bit0   |
    |RC7    |RC6    |RC5    |RC4    |RC3    |RC2    |RC1    |RC0    |
    |SINC   |M1_VD  |M0_VD  |C2OUT  |M0_4   |M0_3   |M0_2   |RCV2   |
PIN |9      |8      |5      |6      |7      |14     |15     |16     |
 @author
 @date
*******************************************************************************/
#include "mcc_generated_files/mcc.h"

/*  $B4X?t%W%m%H%?%$%T%s%0(B */
/******************************************************************************/
void TMR2_Interrupt(void);
void TMR0_Interrupt(void);
void ConparatorOff(void);
void ConparatorOn(void);
void Comparator_Interrupt(void);
/******************************************************************************/
/* TRISX$BCM!!Dj5A(B */
/******************************************************************************/
//TRISA
#define TRISA_DRV   0b00110000    //$B6nF06h4VCf$NF~=PNO@_Dj(B
#define TRISA_VD    0b00110000    //$B8!=P6h4V$N(Bshort$B6h4VF~=PNO@_Dj(B
#define M0_O1_IN    0b00000010    //$B8!=P6h4V$N(BHiz$B6h4VF~=PNO@_Dj(B
//TRISB
#define TRISB_DRV   0b11110000    //$B6nF06h4VCf$NF~=PNO@_Dj(B
#define TRISB_VD    0b11110000    //$B8!=P6h4V$N(Bshort$B6h4VF~=PNO@_Dj(B
//TRISC
#define TRISC_DRV   0b01100000    //$B6nF06h4VCf$NF~=PNO@_Dj(B
#define TRISC_VD    0b00000000    //$B8!=P6h4V$N(Bshort$B6h4VF~=PNO@_Dj(B
#define M0_O2_IN    0b00000010    //$B8!=P6h4V$N(BHiz$B6h4VF~=PNO@_Dj(B
#define M0_O3_IN    0b00000100    //$B8!=P6h4V$N(BHiz$B6h4VF~=PNO@_Dj(B
#define M0_O4_IN    0b00001000    //$B8!=P6h4V$N(BHiz$B6h4VF~=PNO@_Dj(B
/******************************************************************************/
/* $B=PNOCM!!Dj5A(B */
/******************************************************************************/
#define DRV_MODE    0x00    //$BA4$F(B0$B=PNO(B
//PORTA
#define M0_O1_ON    0x02
#define RCV1_ON     0x01    //CMP1$B$r<u$1$F(B1$B=PNO(B
//PORTB
//PORTC
#define RCV2_ON     0x01    //CMP2$B$r<u$1$F(B1$B=PNO(B
#define M0_O2_ON    0x02
#define M0_O3_ON    0x04
#define M0_O4_ON    0x08

/* $B%3%s%Q%l!<%?@_DjCM(B */
//Comparator1
#define     CMP1_BASE           0b00110100
#define     CMP1_ON             0b10000000
#define     CMP1_VCOMP_BASE     0b10010000
#define     M0_O1_CMP           0b00000000
#define     M0_O2_CMP           0b00000001
//Comparator2
#define     CMP2_BASE           0b00110100
#define     CMP2_ON             0b10000000
#define     CMP2_VCOMP_BASE     0b10010000
#define     M0_O3_CMP           0b00000010
#define     M0_O4_CMP           0b00000011

/*$B!!%m%C%/%Q%k%9I}(B */
#define RockTime    10000
//
/******************************************************************************/
/* $B%0%m!<%P%kJQ?tDj5A(B */
/******************************************************************************/
int POL = 0;        //$B%b!<%?6K@-(B
int TMR0_COUNT;     //$B:GBg8!=P;~4V%+%&%s%?(B
int CMP_term = 0;   //CMP$B8r8_;HMQ%U%i%0(B
int OPSW;           //bitSW$B$G$N%*%W%7%g%sJ]B8CM(B
int OPM;            //$B%m%C%/Ne<'$N%*%W%7%g%s(B 0:$B0BDj@E;_Ne<'(B

static void (*fpRockPulse)(void) = NULL;
/******************************************************************************/
/*
                         Main application
 */
//------------------------------------------------------------------------------

/*******************************************************************************
 *  $B%3%s%Q%l!<%?(BOFF$B$H=i4|2=(B
 *  
 ******************************************************************************/
void ComparatorOff(void)
{
    /*$B%3%s%Q%l!<%?$N@_Dj(B*/
    CM1CON0 = CMP1_BASE; //CMP1 OFF$B!"30It=PNO!"H?E>!"(B $B9bB.(B
    CM1CON1 = CMP1_VCOMP_BASE; //DAC$B=PNO(B Vcomp=VDD

    CM2CON0 = CMP2_BASE; //CMP2 OFF$B!"30It=PNO!"H?E>!"(B $B9bB.(B
    CM2CON1 = CMP2_VCOMP_BASE; //IFPOS,DAC$B=PNO(B Vcomp=VDD
}

/*******************************************************************************
 *  $B%3%s%Q%l!<%?(BON
 *  $B%?%$%_%s%0(B1$B$G(B(O1,O3)$B$NAH$H%?%$%_%s%0(B2$B$G(B(O2,O4)$B$NAH$r8r8_$K%5%s%W%j%s%0(B
 ******************************************************************************/
void ComparatorOn(void)
{
    CM1CON0 = (CMP1_BASE | CMP1_ON); //CMP1 ON$B!"30It=PNO!"H?E>!"(B $B9bB.(B
    CM2CON0 = (CMP2_BASE | CMP2_ON); //CMP2 ON$B!"30It=PNO!"H?E>!"(B $B9bB.(B
    if (!CMP_term) {
        CM1CON1 = (CMP1_VCOMP_BASE | M0_O1_CMP); //M0_O1$BB&A*Br(B
        CM2CON1 = (CMP2_VCOMP_BASE | M0_O3_CMP); //M0_O3$BB&A*Br(B
    } else {
        CM1CON1 = (CMP1_VCOMP_BASE | M0_O2_CMP); //M0_O2$BB&A*Br(B
        CM2CON1 = (CMP2_VCOMP_BASE | M0_O4_CMP); //M0_O4$BB&A*Br(B
    }
}

/*******************************************************************************  
 *  Main
 * $B%Z%j%U%'%i%k$N=i4|@_Dj$O!"<+F0@_Dj$7$F$$$k$,!"%^%K%e%"%k$GE,;~JQ99$9$k(B
 ******************************************************************************/
void main(void)
{

    // initialize the device
    SYSTEM_Initialize();
    /*  $B$H$j$"$($:!"(BSYSTEM_Initialize()$B$G(BGPIO$B$r=PNO@_Dj$7!"I,MW$K1~$8$F$r@Z$jBX$($k(B*/

    /* $B8!=P%?%$%_%s%0$K$J$k$^$G(BTMR0,TMR2,Comparator$B$O6X;_(B */
    /************************************************/
    ComparatorOff(); //$B@_Dj$N$_$G(BOFF
    TMR2_StopTimer();
    INTCONbits.TMR0IE = 0; //TMR0_INT$B6X;_(B
    PIE1bits.TMR2IE = 0; //TMR2_INT$B6X;_(B
    PIE2bits.C1IE = 0;
    PIE2bits.C2IE = 0;
    /***********************************************/

    /*$B3d$j9~$_%O%s%I%i!<%;%C%H(B*/
    TMR0_SetInterruptHandler(TMR0_Interrupt);
    TMR2_SetInterruptHandler(TMR2_Interrupt);
    //IOCAF4_SetInterruptHandler(IOCAF4_Interrupt);


    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //Set_Rock_Pulse(); //OPSW$B$K$h$j%m%C%/%Q%k%9A*Br(B    

    // $B2sO)F0:n3NG'MQ$KF0$+$9(B
    //Drive_Pulse(360);
    //__delay_ms(20); //20msec Waite

    //  $B8!=P3+;O(B
    ComparatorOn();
    IOCAFbits.IOCAF4 = 0;
    INTCONbits.TMR0IF = 0;
    PIR2bits.C1IF = 0;
    PIR2bits.C2IF = 0;
    INTCONbits.TMR0IE = 1; //TMR0_INT$B5v2D(B
    PIE2bits.C1IE = 1; //CMP_INT$B5v2D(B
    PIE2bits.C2IE = 1;
    
    SINC_SIG_SetLow();  //SINC$B?.9f!!=i4|CM(B0

    while (1) {
        // Add your application code
    }
}

/*******************************************************************************
 *  Timer0$B=hM}(B
 * $B!&%5%s%W%j%s%0<~4|=hM}(B(2048Hz)$B!!(BCMP1$B$H(BCMP2$B$r8r8_$K%5%s%W%j%s%0$9$k$N$G!"(B1$B%A%c%s%M%k$O(B1024Hz
 * $B!&8!=PDq93%7%g!<%H$N2r=|!J8!=PF0:n!K(B
 * $B!&%5%s%W%j%s%0%Q%k%9MQ(BTMR2$B3d$j9~$_5v2D(B
 * $B!&(BSINC_SIG$B?.9f$N=PNO(B
 *******************************************************************************/
void TMR0_Interrupt(void)
{
    SINC_SIG_Toggle();      //SPK$BF14|?.9f=PNO(B
    //  $B8!=PC<;R(BOPEN    
    if (!CMP_term) {//M0_O1,O3 OPEN
        TRISA = (TRISA_VD | M0_O1_IN); //M0_O1$BC<;R$rF~NO%b!<%I$X(B
        TRISB = TRISB_VD;
        TRISC = (TRISC_VD | M0_O3_IN); //M0_O3$BC<;R$rF~NO%b!<%I$X(B

    } else {//M0_O2,O4 OPEN
        TRISA = TRISA_VD;
        TRISB = TRISB_VD;
        TRISC = (TRISC_VD | M0_O2_IN | M0_O4_IN); //M0_O2,O4$BC<;R$rF~NO%b!<%I$X(B
    }
    //    TRISA = (TRISA_VD | M0_O1_IN); //M0_O1$BC<;R$rF~NO%b!<%I$X(B
    //    TRISB = TRISB_VD;
    //    TRISC = (TRISC_VD | M0_O2_IN | M0_O3_IN | M0_O4_IN); //M0_O2,O3,O4$BC<;R$rF~NO%b!<%I$X(B


    /*************** T2$B%9%?!<%H(B *********************/
    TMR2_StartTimer();
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1; //TMR2_INT$B5v2D(B
    /***********************************************/

}

/*******************************************************************************
 *  Timer2$B=hM}(B
 * $B!&%5%s%W%j%s%0%Q%k%9(BOFF$B=hM}$N=*N;(B(244usec)
 * $B!&8!=PDq93%7%g!<%H(B
 *******************************************************************************/
void TMR2_Interrupt(void)
{
    TMR2_StopTimer();
    PIE1bits.TMR2IE = 0; //TMR2_INT$B6X;_(B
    //
    /*O1,O2$BB&$G$N8!=P(Bshort$B6h4V$K@_Dj(B*/
    TRISA = TRISA_VD; //short$B$J$N$G!"(BO1$BB&$O=PNO%b!<%I(B
    TRISB = TRISB_VD;
    TRISC = TRISC_VD; //RS$BDq93$,(BON$B$@$,!"%7%g!<%H$5$l$F$$$k(B
    
    CMP_term ^= 0x01;
    ComparatorOn();
    
}
/*******************************************************************************
 * Comparator $B3d$j9~$_=hM}(B
 * CMP1$B$r<u$1$F(BRA0$B$K(B1$B=PNO!"(BCMP2$B$r<u$1$F(BRC0$B$K(B1$B=PNO(B
 ******************************************************************************/
void Comparator_Interrupt(void)
{
    INTCONbits.T0IE = 0;
    PIE1bits.TMR2IE = 0;
    PIE2bits.C1IE = 0;
    PIE2bits.C2IE = 0;

    /*$BF~=PNO%l%8%9%?(BTRISX$B$r6nF0;~$N>uBV$K$9$k(B*/
    TRISA = TRISA_DRV;
    TRISB = TRISB_DRV;
    TRISC = TRISC_DRV;
    /*$B=PNO%G!<%?$r6nF0;~$N>uBV$K$9$k(B*/
    LATA = DRV_MODE;
    LATB = DRV_MODE;
    LATC = DRV_MODE;

    /*  CMP1,2$B$r<u$1$F(BRA0,RC0$B$h$j(B1$B$r=PNO(B */
    if (PIR2bits.C1IF == 1) {
        PIR2bits.C1IF = 0;
        LATA = (DRV_MODE | RCV1_ON);
        __delay_us(244);
        LATA = DRV_MODE;
    } else if (PIR2bits.C2IF == 1) {
        PIR2bits.C2IF = 0;
        LATC = (DRV_MODE | RCV2_ON);
        __delay_us(244);
        LATC = DRV_MODE;

    }

    /*
    if (!(OPSW == 0 | OPSW == 1)) {
        if (fpRockPulse) {
            fpRockPulse(); //OPSW$B$K$h$jA*Br$5$l$?%m%C%/%Q%k%9=PNO(B
            __delay_ms(20);
        }
    }
     */
    //$B8!=P:F3+;O(B
    TRISA = TRISA_VD;
    TRISB = TRISB_VD;
    TRISC = TRISC_VD; //$B8!=PDq93(BON
    /*$B=PNO%G!<%?$r6nF0;~$N>uBV$K$9$k(B = $B8!=PDq93$r(Bshort*/
    LATA = DRV_MODE;
    LATB = DRV_MODE;
    LATC = DRV_MODE;
    //$B8!=P7O(BINT$B5v2D(B
    //CMP_term = 0;
    //ComparatorOn();
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    PIE2bits.C1IE = 1;
    PIE2bits.C2IE = 1;


}

/**
 End of File
 */

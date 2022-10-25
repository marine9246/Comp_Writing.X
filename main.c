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
 *コンプ書き込み　実験用 初期検討用
 * 2048Hz　（O1,O3）と(O2,O4)を交互に検出し、Vrs検出したら、ポートより"H"を100usec出力
 * SPK同期用信号としてSINC（RC7）を出力
 ******************************************************************************/
/*******************************************************************************
 @brief     TMR2割り込みでモータを駆動させる
 @note      MOTORポート割当
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

/*  関数プロトタイピング */
/******************************************************************************/
void TMR2_Interrupt(void);
void TMR0_Interrupt(void);
void ConparatorOff(void);
void ConparatorOn(void);
void Comparator_Interrupt(void);
/******************************************************************************/
/* TRISX値　定義 */
/******************************************************************************/
//TRISA
#define TRISA_DRV   0b00110000    //駆動区間中の入出力設定
#define TRISA_VD    0b00110000    //検出区間のshort区間入出力設定
#define M0_O1_IN    0b00000010    //検出区間のHiz区間入出力設定
//TRISB
#define TRISB_DRV   0b11110000    //駆動区間中の入出力設定
#define TRISB_VD    0b11110000    //検出区間のshort区間入出力設定
//TRISC
#define TRISC_DRV   0b01100000    //駆動区間中の入出力設定
#define TRISC_VD    0b00000000    //検出区間のshort区間入出力設定
#define M0_O2_IN    0b00000010    //検出区間のHiz区間入出力設定
#define M0_O3_IN    0b00000100    //検出区間のHiz区間入出力設定
#define M0_O4_IN    0b00001000    //検出区間のHiz区間入出力設定
/******************************************************************************/
/* 出力値　定義 */
/******************************************************************************/
#define DRV_MODE    0x00    //全て0出力
//PORTA
#define M0_O1_ON    0x02
#define RCV1_ON     0x01    //CMP1を受けて1出力
//PORTB
//PORTC
#define RCV2_ON     0x01    //CMP2を受けて1出力
#define M0_O2_ON    0x02
#define M0_O3_ON    0x04
#define M0_O4_ON    0x08

/* コンパレータ設定値 */
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

/*　ロックパルス幅 */
#define RockTime    10000
//
/******************************************************************************/
/* グローバル変数定義 */
/******************************************************************************/
int POL = 0;        //モータ極性
int TMR0_COUNT;     //最大検出時間カウンタ
int CMP_term = 0;   //CMP交互使用フラグ
int OPSW;           //bitSWでのオプション保存値
int OPM;            //ロック励磁のオプション 0:安定静止励磁

static void (*fpRockPulse)(void) = NULL;
/******************************************************************************/
/*
                         Main application
 */
//------------------------------------------------------------------------------

/*******************************************************************************
 *  コンパレータOFFと初期化
 *  
 ******************************************************************************/
void ComparatorOff(void)
{
    /*コンパレータの設定*/
    CM1CON0 = CMP1_BASE; //CMP1 OFF、外部出力、反転、 高速
    CM1CON1 = CMP1_VCOMP_BASE; //DAC出力 Vcomp=VDD

    CM2CON0 = CMP2_BASE; //CMP2 OFF、外部出力、反転、 高速
    CM2CON1 = CMP2_VCOMP_BASE; //IFPOS,DAC出力 Vcomp=VDD
}

/*******************************************************************************
 *  コンパレータON
 *  タイミング1で(O1,O3)の組とタイミング2で(O2,O4)の組を交互にサンプリング
 ******************************************************************************/
void ComparatorOn(void)
{
    CM1CON0 = (CMP1_BASE | CMP1_ON); //CMP1 ON、外部出力、反転、 高速
    CM2CON0 = (CMP2_BASE | CMP2_ON); //CMP2 ON、外部出力、反転、 高速
    if (!CMP_term) {
        CM1CON1 = (CMP1_VCOMP_BASE | M0_O1_CMP); //M0_O1側選択
        CM2CON1 = (CMP2_VCOMP_BASE | M0_O3_CMP); //M0_O3側選択
    } else {
        CM1CON1 = (CMP1_VCOMP_BASE | M0_O2_CMP); //M0_O2側選択
        CM2CON1 = (CMP2_VCOMP_BASE | M0_O4_CMP); //M0_O4側選択
    }
}

/*******************************************************************************  
 *  Main
 * ペリフェラルの初期設定は、自動設定しているが、マニュアルで適時変更する
 ******************************************************************************/
void main(void)
{

    // initialize the device
    SYSTEM_Initialize();
    /*  とりあえず、SYSTEM_Initialize()でGPIOを出力設定し、必要に応じてを切り替える*/

    /* 検出タイミングになるまでTMR0,TMR2,Comparatorは禁止 */
    /************************************************/
    ComparatorOff(); //設定のみでOFF
    TMR2_StopTimer();
    INTCONbits.TMR0IE = 0; //TMR0_INT禁止
    PIE1bits.TMR2IE = 0; //TMR2_INT禁止
    PIE2bits.C1IE = 0;
    PIE2bits.C2IE = 0;
    /***********************************************/

    /*割り込みハンドラーセット*/
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

    //Set_Rock_Pulse(); //OPSWによりロックパルス選択    

    // 回路動作確認用に動かす
    //Drive_Pulse(360);
    //__delay_ms(20); //20msec Waite

    //  検出開始
    ComparatorOn();
    IOCAFbits.IOCAF4 = 0;
    INTCONbits.TMR0IF = 0;
    PIR2bits.C1IF = 0;
    PIR2bits.C2IF = 0;
    INTCONbits.TMR0IE = 1; //TMR0_INT許可
    PIE2bits.C1IE = 1; //CMP_INT許可
    PIE2bits.C2IE = 1;
    
    SINC_SIG_SetLow();  //SINC信号　初期値0

    while (1) {
        // Add your application code
    }
}

/*******************************************************************************
 *  Timer0処理
 * ・サンプリング周期処理(2048Hz)　CMP1とCMP2を交互にサンプリングするので、1チャンネルは1024Hz
 * ・検出抵抗ショートの解除（検出動作）
 * ・サンプリングパルス用TMR2割り込み許可
 * ・SINC_SIG信号の出力
 *******************************************************************************/
void TMR0_Interrupt(void)
{
    SINC_SIG_Toggle();      //SPK同期信号出力
    //  検出端子OPEN    
    if (!CMP_term) {//M0_O1,O3 OPEN
        TRISA = (TRISA_VD | M0_O1_IN); //M0_O1端子を入力モードへ
        TRISB = TRISB_VD;
        TRISC = (TRISC_VD | M0_O3_IN); //M0_O3端子を入力モードへ

    } else {//M0_O2,O4 OPEN
        TRISA = TRISA_VD;
        TRISB = TRISB_VD;
        TRISC = (TRISC_VD | M0_O2_IN | M0_O4_IN); //M0_O2,O4端子を入力モードへ
    }
    //    TRISA = (TRISA_VD | M0_O1_IN); //M0_O1端子を入力モードへ
    //    TRISB = TRISB_VD;
    //    TRISC = (TRISC_VD | M0_O2_IN | M0_O3_IN | M0_O4_IN); //M0_O2,O3,O4端子を入力モードへ


    /*************** T2スタート *********************/
    TMR2_StartTimer();
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1; //TMR2_INT許可
    /***********************************************/

}

/*******************************************************************************
 *  Timer2処理
 * ・サンプリングパルスOFF処理の終了(244usec)
 * ・検出抵抗ショート
 *******************************************************************************/
void TMR2_Interrupt(void)
{
    TMR2_StopTimer();
    PIE1bits.TMR2IE = 0; //TMR2_INT禁止
    //
    /*O1,O2側での検出short区間に設定*/
    TRISA = TRISA_VD; //shortなので、O1側は出力モード
    TRISB = TRISB_VD;
    TRISC = TRISC_VD; //RS抵抗がONだが、ショートされている
    
    CMP_term ^= 0x01;
    ComparatorOn();
    
}
/*******************************************************************************
 * Comparator 割り込み処理
 * CMP1を受けてRA0に1出力、CMP2を受けてRC0に1出力
 ******************************************************************************/
void Comparator_Interrupt(void)
{
    INTCONbits.T0IE = 0;
    PIE1bits.TMR2IE = 0;
    PIE2bits.C1IE = 0;
    PIE2bits.C2IE = 0;

    /*入出力レジスタTRISXを駆動時の状態にする*/
    TRISA = TRISA_DRV;
    TRISB = TRISB_DRV;
    TRISC = TRISC_DRV;
    /*出力データを駆動時の状態にする*/
    LATA = DRV_MODE;
    LATB = DRV_MODE;
    LATC = DRV_MODE;

    /*  CMP1,2を受けてRA0,RC0より1を出力 */
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
            fpRockPulse(); //OPSWにより選択されたロックパルス出力
            __delay_ms(20);
        }
    }
     */
    //検出再開始
    TRISA = TRISA_VD;
    TRISB = TRISB_VD;
    TRISC = TRISC_VD; //検出抵抗ON
    /*出力データを駆動時の状態にする = 検出抵抗をshort*/
    LATA = DRV_MODE;
    LATB = DRV_MODE;
    LATC = DRV_MODE;
    //検出系INT許可
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

/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC16LF1509
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set M0_O1 aliases
#define M0_O1_TRIS                 TRISAbits.TRISA1
#define M0_O1_LAT                  LATAbits.LATA1
#define M0_O1_PORT                 PORTAbits.RA1
#define M0_O1_WPU                  WPUAbits.WPUA1
#define M0_O1_ANS                  ANSELAbits.ANSA1
#define M0_O1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define M0_O1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define M0_O1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define M0_O1_GetValue()           PORTAbits.RA1
#define M0_O1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define M0_O1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define M0_O1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define M0_O1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define M0_O1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define M0_O1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set C1_OUT aliases
#define C1_OUT_TRIS                 TRISAbits.TRISA2
#define C1_OUT_LAT                  LATAbits.LATA2
#define C1_OUT_PORT                 PORTAbits.RA2
#define C1_OUT_WPU                  WPUAbits.WPUA2
#define C1_OUT_ANS                  ANSELAbits.ANSA2
#define C1_OUT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define C1_OUT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define C1_OUT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define C1_OUT_GetValue()           PORTAbits.RA2
#define C1_OUT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define C1_OUT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define C1_OUT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define C1_OUT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define C1_OUT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define C1_OUT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SWA aliases
#define SWA_TRIS                 TRISAbits.TRISA4
#define SWA_LAT                  LATAbits.LATA4
#define SWA_PORT                 PORTAbits.RA4
#define SWA_WPU                  WPUAbits.WPUA4
#define SWA_ANS                  ANSELAbits.ANSA4
#define SWA_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SWA_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SWA_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SWA_GetValue()           PORTAbits.RA4
#define SWA_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SWA_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SWA_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SWA_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SWA_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SWA_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set OP1 aliases
#define OP1_TRIS                 TRISBbits.TRISB4
#define OP1_LAT                  LATBbits.LATB4
#define OP1_PORT                 PORTBbits.RB4
#define OP1_WPU                  WPUBbits.WPUB4
#define OP1_ANS                  ANSELBbits.ANSB4
#define OP1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define OP1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define OP1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define OP1_GetValue()           PORTBbits.RB4
#define OP1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define OP1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define OP1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define OP1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define OP1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define OP1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set OP2 aliases
#define OP2_TRIS                 TRISBbits.TRISB5
#define OP2_LAT                  LATBbits.LATB5
#define OP2_PORT                 PORTBbits.RB5
#define OP2_WPU                  WPUBbits.WPUB5
#define OP2_ANS                  ANSELBbits.ANSB5
#define OP2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define OP2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define OP2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define OP2_GetValue()           PORTBbits.RB5
#define OP2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define OP2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define OP2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define OP2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define OP2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define OP2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set OP3 aliases
#define OP3_TRIS                 TRISBbits.TRISB6
#define OP3_LAT                  LATBbits.LATB6
#define OP3_PORT                 PORTBbits.RB6
#define OP3_WPU                  WPUBbits.WPUB6
#define OP3_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define OP3_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define OP3_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define OP3_GetValue()           PORTBbits.RB6
#define OP3_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define OP3_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define OP3_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define OP3_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)

// get/set OP4 aliases
#define OP4_TRIS                 TRISBbits.TRISB7
#define OP4_LAT                  LATBbits.LATB7
#define OP4_PORT                 PORTBbits.RB7
#define OP4_WPU                  WPUBbits.WPUB7
#define OP4_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define OP4_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define OP4_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define OP4_GetValue()           PORTBbits.RB7
#define OP4_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define OP4_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define OP4_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define OP4_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set M0_O2 aliases
#define M0_O2_TRIS                 TRISCbits.TRISC1
#define M0_O2_LAT                  LATCbits.LATC1
#define M0_O2_PORT                 PORTCbits.RC1
#define M0_O2_ANS                  ANSELCbits.ANSC1
#define M0_O2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define M0_O2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define M0_O2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define M0_O2_GetValue()           PORTCbits.RC1
#define M0_O2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define M0_O2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define M0_O2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define M0_O2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set M0_O3 aliases
#define M0_O3_TRIS                 TRISCbits.TRISC2
#define M0_O3_LAT                  LATCbits.LATC2
#define M0_O3_PORT                 PORTCbits.RC2
#define M0_O3_ANS                  ANSELCbits.ANSC2
#define M0_O3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define M0_O3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define M0_O3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define M0_O3_GetValue()           PORTCbits.RC2
#define M0_O3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define M0_O3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define M0_O3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define M0_O3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set M0_O4 aliases
#define M0_O4_TRIS                 TRISCbits.TRISC3
#define M0_O4_LAT                  LATCbits.LATC3
#define M0_O4_PORT                 PORTCbits.RC3
#define M0_O4_ANS                  ANSELCbits.ANSC3
#define M0_O4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define M0_O4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define M0_O4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define M0_O4_GetValue()           PORTCbits.RC3
#define M0_O4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define M0_O4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define M0_O4_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define M0_O4_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set C2_OUT aliases
#define C2_OUT_TRIS                 TRISCbits.TRISC4
#define C2_OUT_LAT                  LATCbits.LATC4
#define C2_OUT_PORT                 PORTCbits.RC4
#define C2_OUT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define C2_OUT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define C2_OUT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define C2_OUT_GetValue()           PORTCbits.RC4
#define C2_OUT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define C2_OUT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set M0_VD aliases
#define M0_VD_TRIS                 TRISCbits.TRISC5
#define M0_VD_LAT                  LATCbits.LATC5
#define M0_VD_PORT                 PORTCbits.RC5
#define M0_VD_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define M0_VD_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define M0_VD_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define M0_VD_GetValue()           PORTCbits.RC5
#define M0_VD_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define M0_VD_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set M1_VD aliases
#define M1_VD_TRIS                 TRISCbits.TRISC6
#define M1_VD_LAT                  LATCbits.LATC6
#define M1_VD_PORT                 PORTCbits.RC6
#define M1_VD_ANS                  ANSELCbits.ANSC6
#define M1_VD_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define M1_VD_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define M1_VD_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define M1_VD_GetValue()           PORTCbits.RC6
#define M1_VD_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define M1_VD_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define M1_VD_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define M1_VD_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set SINC_SIG aliases
#define SINC_SIG_TRIS                 TRISCbits.TRISC7
#define SINC_SIG_LAT                  LATCbits.LATC7
#define SINC_SIG_PORT                 PORTCbits.RC7
#define SINC_SIG_ANS                  ANSELCbits.ANSC7
#define SINC_SIG_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SINC_SIG_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SINC_SIG_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SINC_SIG_GetValue()           PORTCbits.RC7
#define SINC_SIG_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SINC_SIG_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SINC_SIG_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SINC_SIG_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
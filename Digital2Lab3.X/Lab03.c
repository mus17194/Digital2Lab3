/*
 * File:   Lab03.c
 * Author: Vincenzo
 *
 *  LCD , USART y ADC
 * Created on February 5, 2020, 4:05 PM
 */


// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include <stdint.h>


#define _XTAL_FREQ 4000000


void main(void) {
    PORTA = 0;
    TRISA = 1;
    PORTB = 0;
    TRISB = 0;
    PORTC = 0;
    TRISC = 0;
    PORTD = 0;
    TRISD = 0;
    PORTE = 0;
    TRISE = 0;
    
    ANSEL = 0b00001111;
    ANSELH = 0;
    
    int dat1;
    int dat2;
    float dat3;
    float dat4;
    char savechain[16];
    
    startLCD();
    limpiarLCD();
    setLCD(1,1);
    escribirLCD("S1     S2     S3");

    while(1) {
        
        init_ADC(0x01);
        PIR1bits.ADIF = 0;
        dat4 = (5.0*ADRESH)/254.0;
        dat2 = ADRESH;
        
        __delay_us(500);
        
        init_ADC(0x00);
        PIR1bits.ADIF = 0;
        dat3 = (5.0*ADRESH)/254.0;
        dat1 = ADRESH;
        
        __delay_us(500);
        
        sprintf(savechain, "%1.2f  %1.2f", dat3, dat4);
        setLCD(2,1);
        escribirLCD(savechain);
    
    }
    
    
    return;
}

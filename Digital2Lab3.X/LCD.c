/*
 * File:   LCD.c
 * Author: Vincenzo
 *
 * Created on February 9, 2020, 7:29 PM
 */



#include "LCD.h"
#define _XTAL_FREQ 4000000
#include <xc.h>

//Pines del LCD

//PUERTO LCD        //PUERTO PIC
#define LCD0     PORTDbits.RD0       //ESPECIFICANDO LOS PUERTOS DEL LCD Y EL PIC
#define LCD1     PORTDbits.RD1
#define LCD2     PORTDbits.RD2
#define LCD3     PORTDbits.RD3
#define LCD4     PORTDbits.RD4
#define LCD5     PORTDbits.RD5
#define LCD6     PORTDbits.RD6
#define LCD7     PORTDbits.RD7
#define LCDRS    PORTEbits.RE0
#define LCDE     PORTEbits.RE1
#define hola     PORTD     //agarra todo el puerto



void startLCD(void) {
    __delay_ms(20);
    enviardatos(0x30);
    __delay_ms(5);
    enviardatos(0x30);
    __delay_us(100);
    enviardatos(0x30);
    __delay_us(100);
    enviardatos(0x38);
    __delay_us(60);   
    enviardatos(0x08);
    __delay_us(60);  
    enviardatos(0x01);
    __delay_ms(5);
    enviardatos(0x06);
    __delay_us(60);
    enviardatos(0x0C);
    __delay_us(60); 
}

void enviardatos(int crack) {
    LCDRS = 0;      // 0 envia comandos 1 manda datos
    __delay_ms(5);
    LCDE = 1;       //enable se debe dar un pulso para guardar los comandos
    hola = crack;
    __delay_ms(5);
    LCDE = 0;
    __delay_ms(5);
}

void limpiarLCD(void) {
    enviardatos(0x00);
    enviardatos(0x01);
    __delay_ms(5);
}

void setLCD(int V, int M) {
    int Z;
    if(V == 1) {
        Z = 0x80 + M - 1;
                enviardatos(Z);
    }
    else if(V == 2) {
        Z = 0xC0 + M - 1;
        enviardatos(Z);
    }
}

void charLCD(char V) {
   LCDRS = 1;     //deja de enviar comandos para mandar datos
   hola = V;
   LCDE = 1;     //activar enable
   __delay_us(40);
   LCDE = 0;     //desactivar enable
}

void escribirLCD(char *V) {
    int X;
    for(X = 0; V[X] != '\0'; X++) {
        charLCD(V[X]);
    }
}

/* 
 * File:   Libreria LCD
 * Author: Vincenzo Musella 
 * Comments: 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#define _XTAL_FREQ 4000000
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>


void init_ADC(uint8_t channel);

void startLCD(void);
void enviardatos(int crack);   //variable se llama crack
void limpiarLCD(void);   //limpiar todo LCD
void setLCD(int V, int M);
void charLCD(char V);
void escribirLCD(char *V);



#endif	/* XC_HEADER_TEMPLATE_H */
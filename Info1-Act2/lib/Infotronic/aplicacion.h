#ifndef __APLICACION_H
#define __APLICACION_H

#define LED_PIN0 15
#define LED_PIN1 4
#define LED_PIN2 16
#define LED_PIN3 17
#define LED_PIN4 5
#define LED_PIN5 18
#define LED_PIN6 19
#define LED_PIN7 21


void iniciar_leds();
void SetPin(int led);
void ClrPin(int led);
void inicializarInfotronic();

#endif
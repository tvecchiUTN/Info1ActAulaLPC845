#ifndef __APLICACION_H
#define __APLICACION_H

#define LED_PIN0 4
#define LED_PIN1 16
#define LED_PIN2 17
#define LED_PIN3 18
#define LED_PIN4 19
#define LED_PIN5 21
#define LED_PIN6 22
#define LED_PIN7 23

#define PULSADOR_PIN0 33

void iniciar_pines();
void SetPin(int led);
void ClrPin(int led);

#endif

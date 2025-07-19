#include <Arduino.h>
#include "aplicacion.h"

void iniciar_pines()
{
    pinMode(LED_PIN0, OUTPUT);
    pinMode(LED_PIN1, OUTPUT);
    pinMode(LED_PIN2, OUTPUT);
    pinMode(LED_PIN3, OUTPUT);
    pinMode(LED_PIN4, OUTPUT);
    pinMode(LED_PIN5, OUTPUT);
    pinMode(LED_PIN6, OUTPUT);
    pinMode(LED_PIN7, OUTPUT);

    pinMode(PULSADOR_PIN0, INPUT);
}
void SetPin(int led)
{
    digitalWrite(led, HIGH);
}
void ClrPin(int led)
{
    digitalWrite(led, LOW);
}
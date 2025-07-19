#include <Arduino.h>
#include "inicializarInfotronic.h"
#include "aplicacion.h"

void inicializarInfotronic()
{
    iniciar_leds();

    ClrPin(LED_PIN0);
    ClrPin(LED_PIN1);
    ClrPin(LED_PIN2);
    ClrPin(LED_PIN3);
    ClrPin(LED_PIN4);
    ClrPin(LED_PIN5);
    ClrPin(LED_PIN6);
    ClrPin(LED_PIN7);
}
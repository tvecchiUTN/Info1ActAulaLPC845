#include <Arduino.h>
#include <aplicacion.h>
#include <inicializarInfotronic.h>
#include <timers.h>

void setup() {
  inicializarInfotronic();
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate
  Serial.println("Hello, World!"); // Print a message to the serial monitor
  delay(3000);
}

void loop() 
{
  const static int leds[8] = {LED_PIN0, LED_PIN1, LED_PIN2, LED_PIN3, LED_PIN4, LED_PIN5, LED_PIN6, LED_PIN7};

  static int pulsadorState;
  pulsadorState = digitalRead(PULSADOR_PIN0);

  //Debouncing
  static int antPuls = 0;

  static int cuentaPulsador = 0;
  static int isASC = 1;

  if (pulsadorState != antPuls) {
  
    if (pulsadorState) { // flanco ascendente
      if (isASC && cuentaPulsador < 7) {
        cuentaPulsador++;
      } else if (!isASC && cuentaPulsador > 0) {
        cuentaPulsador--;
      }

      if (isASC && cuentaPulsador == 7) {
        isASC = 0;
      } else if (!isASC && cuentaPulsador == 0) {
        isASC = 1;
      }
    }

    antPuls = pulsadorState; // siempre se actualiza
  }

  

  for (int i = 0; i < 8; i++) {
  digitalWrite(leds[i], i == cuentaPulsador ? HIGH : LOW);
  }
  
}

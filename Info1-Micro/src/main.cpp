#include <Arduino.h>
#include <stdint.h>
#include <timers.h>
#include <aplicacion.h>
#include <inicializarInfotronic.h>

#define LEDS_MAX 8

void prtBinario(uint8_t val, int *bin);

void setup() {
  // put your setup code here, to run once:
  inicializarInfotronic();
  delay(1000); 
}

void prtBinario(uint8_t val, int *bin)
{
  uint8_t mask = 0x01;
  for(int i = 0; i < LEDS_MAX; i++)
  {
    bin[i] = (val & mask) ? 1 : 0;
    mask <<= 1;
  }
}

void loop() 
{
  const static int pines[LEDS_MAX] = {LED_PIN0, LED_PIN1, LED_PIN2, LED_PIN3, LED_PIN4, LED_PIN5, LED_PIN6, LED_PIN7};
  static int bin[LEDS_MAX];
  static uint8_t valores[] = {0x23, 160, 255, 0x55, 0xaa, 240, 0, 1, 2, 4, 8, 16, 32, 64, 128, 0};

  static int sec = 0;
  if(!getTime())
  {
    prtBinario(valores[sec], bin);
    sec++;
    if(sec == 16)
    {
      sec = 0;
    }
    setTime(1000);
  }

  for(int i = 0; i < LEDS_MAX; i++)
  {
    if(bin[i])
    {
      //Para que con 1 se apage, cambiarlo por ClrPin
      SetPin(pines[i]);
    }
    else
    {
      //Para que con 0 se prenda, cambiarlo por SetPin
      ClrPin(pines[i]);
    }
  }
  
}

//Actividad 1.1. Barrido alternado--------------------------------------------------------------------------------------------------------------
/*
  const static int pines[8] = {LED_PIN0, LED_PIN1, LED_PIN2, LED_PIN3, LED_PIN4, LED_PIN5, LED_PIN6, LED_PIN7};
  static int i = 0;
  static int isON = 1;
  static int isASC = 1;  

  if(!getTime())
  {

    //Secuencia de encendido y apagado de LEDs
    if(isON && isASC && (i != 8))
    {
      SetPin(pines[i]);
      i++;
    }

    if (!isON && isASC && (i != 8))
    {
      ClrPin(pines[i]);
      i++;
    }

    //Verificacion para leds previmente encendidos y en modo ascendente
    if(!isON && isASC && (i == 8))
    {
      isON = 1;
      isASC = 0;
    }

    if((i == 8) && isASC) 
    {
      i = 0;
      isON = 0;
      
    }

    if((i == -1) && !isASC && isON) 
    {
      i = 7;
      isON = 0;
      
    }

    if(isON && !isASC && (i != -1))
    {
      SetPin(pines[i]);
      i--;
    }

    if (!isON && !isASC && (i != -1))
    {
      ClrPin(pines[i]);
      i--;
    }
    if (!isON && !isASC && (i == -1))
    {
      isON = 1;
      isASC = 1;
      i = 0;
    }
    
    
    setTime(400);
  }
  
*/
//Actividad 1.1. Barrido alternado--------------------------------------------------------------------------------------------------------------

//Actividad 1.2. Barrido alternado con retardo diferente--------------------------------------------------------------------------------------------------------------
/*

  #define RETARDO_INIT 100
  #define RETARDO_SUM 100
  #define RETARDO_MAX 700

  static int i = 0;
  static int isON = 1;
  static int isASC = 1;
  static int isTempASC = 1;
  static int retardo = RETARDO_INIT;

  

  //Estructura importante
  //Nivel && sentido && igualdad
  if(!getTime())
  {
    //Inicio de secuencia de encendido y apagado de forma ascendente
    if(isON && isASC && (i != 8))
    {
      SetPin(pines[i]);
      i++;
    }
    else if(!isON && isASC && (i != 8))
    {
      ClrPin(pines[i]);
      i++;
    }

    if(isON && isASC && (i == 8)) 
    {
      i = 0;
      isON = 0;
      
    }
    else if(!isON && isASC && (i == 8))
    {
      isON = 1;
      isASC = 0;
      if(isTempASC && retardo <= RETARDO_MAX)
      {
        retardo += RETARDO_SUM;
        
      }else if(!isTempASC && retardo >= RETARDO_INIT)
      {
        retardo -= RETARDO_SUM;
        
      }
      
    }
    //Fin de secuencia de encendido y apagado de forma ascendente
    
    //Inicio de secuencia de encendido y apagado de forma descendente
    if(isON && !isASC && (i != -1))
    {
      SetPin(pines[i]);
      i--;
    }
    else if(!isON && !isASC && (i != -1))
    {
      ClrPin(pines[i]);
      i--;
    }

    if(isON && !isASC && (i == -1)) 
    {
      i = 7;
      isON = 0;
      
    }
    else if(!isON && !isASC && (i == -1))
    {
      isON = 1;
      isASC = 1;
      if(isTempASC && retardo != RETARDO_MAX)
      {
        retardo += RETARDO_SUM;
        
      }else if(!isTempASC && retardo != RETARDO_INIT)
      {
        retardo -= RETARDO_SUM;
        
      }
    }
    //Fin de secuencia de encendido y apagado de forma descendente

    if(isTempASC && retardo == RETARDO_MAX)
    {
      isTempASC = 0;
      
    }else if(!isTempASC && retardo == RETARDO_INIT)
    {
      isTempASC = 1;
      
    }

    //Control de tiempo
    setTime(retardo);
  }
*/
//Actividad 1.2. Barrido alternado con retardo diferente--------------------------------------------------------------------------------------------------------------
#include <Arduino.h>
#include "timers.h"

static unsigned long timer_start = 0;
static unsigned long timer_duration = 0;

void setTime(unsigned long ms) 
{
    timer_start = millis();
    timer_duration = ms;
}

unsigned long getTime() 
{
    unsigned long now = millis();
    unsigned long elapsed = now - timer_start;

    if (elapsed >= timer_duration) {
        return 0;
    } else {
        return timer_duration - elapsed;
    }
}
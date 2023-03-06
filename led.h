// led.h
// Module to manage LED
#ifndef LED_H_
#define LED_H_

// LED Id for each LED
typedef enum {
    LED0 = 0,
    LED1,
    LED2,
    LED3,
    LED_COUNT
} LedId;

// Initialize/cleanup the module's data structures.
void Led_intialize(void);
void Led_cleanUp(void);

// Turn on / off LED 
void Led_turnOn(LedId ledId);
void Led_turnOff(LedId ledId);

// Flash/Unflash LEDS with hertz
void Led_flashAll(int hz);
void Led_unflashAll(void);

#endif
#ifndef LED_H_
#define LED_H_

typedef enum {
    LED0 = 0,
    LED1,
    LED2,
    LED3,
    LED_COUNT
} LedId;

void Led_intialize(void);

void Led_cleanUp(void);

void Led_turnOn(LedId ledId);

void Led_turnOff(LedId ledId);

#endif
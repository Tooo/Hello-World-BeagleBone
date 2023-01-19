#include "led.h"

#include "stdio.h"

#include "system.h"

static char* brightnessFile = "/sys/class/leds/beaglebone:green:usr%d/brightness";
static char* triggerFile = "/sys/class/leds/beaglebone:green:usr%d/trigger";

void Led_intialize(void)
{
    // Set LED triggers to None
    for (int i = 0; i < LED_COUNT; i++) {
        char filePath[BUFFER_MAX_LENGTH];
        snprintf(filePath, BUFFER_MAX_LENGTH, triggerFile, i);
        System_writeFile(filePath, "none");
    }
}

void Led_cleanUp(void)
{
    for (int i = 0; i < LED_COUNT; i++) {
        Led_turnOff(i);
    } 
}

void Led_turnOn(LedId ledId)
{
    char command[BUFFER_MAX_LENGTH];
    snprintf(command, BUFFER_MAX_LENGTH, brightnessFile, ledId);
    System_writeFile(command, "1");
}

void Led_turnOff(LedId ledId)
{
    char command[BUFFER_MAX_LENGTH];
    snprintf(command, BUFFER_MAX_LENGTH, brightnessFile, ledId);
    System_writeFile(command, "0");   
}
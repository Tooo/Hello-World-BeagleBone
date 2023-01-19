#include "led.h"

#include "stdio.h"

#include "system.h"
#include "timer.h"

static char* brightnessFile = "/sys/class/leds/beaglebone:green:usr%d/brightness";
static char* triggerFile = "/sys/class/leds/beaglebone:green:usr%d/trigger";
static char* delayOnFile = "/sys/class/leds/beaglebone:green:usr%d/delay_on";
static char* delayOffFile = "/sys/class/leds/beaglebone:green:usr%d/delay_off";

static const int TIMER_WAIT_TIME_MS = 300;

void Led_intialize(void)
{
    // Set LED triggers to None
    Led_unflashAll();
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

void Led_flashAll(int hz)
{
    for (int i = 0; i < LED_COUNT; i++) {
        char filePath[BUFFER_MAX_LENGTH];
        snprintf(filePath, BUFFER_MAX_LENGTH, triggerFile, i);
        System_writeFile(filePath, "timer");
    }

    int duration = 1000 / hz;
    char durationString[5];
    snprintf(durationString, 5, "%d", duration);
    Timer_sleepForMs(TIMER_WAIT_TIME_MS);

    for (int i = 0; i < LED_COUNT; i++) {
        char filePath[BUFFER_MAX_LENGTH];
        snprintf(filePath, BUFFER_MAX_LENGTH, delayOnFile, i);
        System_writeFile(filePath, durationString);
    }

    for (int i = 0; i < LED_COUNT; i++) {
        char filePath[BUFFER_MAX_LENGTH];
        snprintf(filePath, BUFFER_MAX_LENGTH, delayOffFile, i);
        System_writeFile(filePath, durationString);
    }

}

void Led_unflashAll(void)
{
    for (int i = 0; i < LED_COUNT; i++) {
        char filePath[BUFFER_MAX_LENGTH];
        snprintf(filePath, BUFFER_MAX_LENGTH, triggerFile, i);
        System_writeFile(filePath, "none");
    }
}
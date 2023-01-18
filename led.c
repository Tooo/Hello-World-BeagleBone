#include "led.h"

#include "stdio.h"

#include "system.h"

void Led_intialize(void)
{
    // Set LED triggers to None
    System_writeFile("/sys/class/leds/beaglebone:green:usr0/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr1/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr2/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr3/trigger", "none");
}

void Led_turnOn(int ledNumber)
{
    char command[BUFFER_MAX_LENGTH];
    snprintf(command, BUFFER_MAX_LENGTH, "/sys/class/leds/beaglebone:green:usr%d/brightness", ledNumber);
    System_writeFile(command, "1");
}

void Led_turnOff(int ledNumber)
{
    char command[BUFFER_MAX_LENGTH];
    snprintf(command, BUFFER_MAX_LENGTH, "/sys/class/leds/beaglebone:green:usr%d/brightness", ledNumber);
    System_writeFile(command, "0");   
}
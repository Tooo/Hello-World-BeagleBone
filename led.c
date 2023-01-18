#include "led.h"

#include "system.h"

void Led_intialize(void)
{
    // Set LED triggers to None
    System_writeFile("/sys/class/leds/beaglebone:green:usr0/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr1/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr2/trigger", "none");
    System_writeFile("/sys/class/leds/beaglebone:green:usr3/trigger", "none");
}
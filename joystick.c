#include "joystick.h"

#include <string.h>
#include <stdio.h>

#include "system.h"
#include "timer.h"

void Joystick_intialize(void)
{
    // Configure pin's functions
    System_runCommand("config-pin p8.14 gpio");
    System_runCommand("config-pin p8.15 gpio");
    System_runCommand("config-pin p8.16 gpio");
    System_runCommand("config-pin p8.18 gpio");

    // Configure pin to GPIO
    System_writeFile("/sys/class/gpio/export", "26");
    Timer_sleepForMs(300);
    System_writeFile("/sys/class/gpio/export", "46");
    Timer_sleepForMs(300);
    System_writeFile("/sys/class/gpio/export", "65");
    Timer_sleepForMs(300);
    System_writeFile("/sys/class/gpio/export", "47");
    Timer_sleepForMs(300);

    // Configure pin to GPIO
    System_writeFile("/sys/class/gpio/gpio26/direction", "in");
    System_writeFile("/sys/class/gpio/gpio46/direction", "in");
    System_writeFile("/sys/class/gpio/gpio65/direction", "in");
    System_writeFile("/sys/class/gpio/gpio47/direction", "in");
}

JoystickDirection Joystick_getDirection(void)
{
    char buffer[BUFFER_MAX_LENGTH];
    System_readFile("/sys/class/gpio/gpio26/value", buffer);
    if (strncmp(buffer, "0", 1) == 0) {
        return JOYSTICK_UP;
    }

    char buffer2[BUFFER_MAX_LENGTH];
    System_readFile("/sys/class/gpio/gpio46/value", buffer2);
    if (strncmp(buffer2, "0", 1) == 0) {
        return JOYSTICK_DOWN;
    }

    char buffer3[BUFFER_MAX_LENGTH];
    System_readFile("/sys/class/gpio/gpio65/value", buffer3);
    if (strncmp(buffer3, "0", 1) == 0) {
        return JOYSTICK_LEFT;
    }

    char buffer4[BUFFER_MAX_LENGTH];
    System_readFile("/sys/class/gpio/gpio47/value", buffer4);
    if (strncmp(buffer4, "0", 1) == 0) {
        return JOYSTICK_RIGHT;
    }

    return JOYSTICK_NO_DIRECTION;
}
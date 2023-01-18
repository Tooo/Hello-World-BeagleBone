#include "joystick.h"

#include "system.h"

void Joystick_intialize(void)
{
    // Configure pin's functions
    System_runCommand("config-pin p8.14 gpio");
    System_runCommand("config-pin p8.15 gpio");
    System_runCommand("config-pin p8.16 gpio");
    System_runCommand("config-pin p8.18 gpio");

    // Configure pin to GPIO
    System_writeFile(EXPORT_GPIO_FILE, "26");
    System_writeFile(EXPORT_GPIO_FILE, "47");
    System_writeFile(EXPORT_GPIO_FILE, "46");
    System_writeFile(EXPORT_GPIO_FILE, "26");
}
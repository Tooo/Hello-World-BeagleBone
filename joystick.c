#include "joystick.h"

#include "system.h"

void Joystick_intialize(void)
{
    // Configure pin's functions
    System_runCommand("config-pin p8.14 gpio");
    System_runCommand("config-pin p8.15 gpio");
    System_runCommand("config-pin p8.16 gpio");
    System_runCommand("config-pin p8.18 gpio");
}
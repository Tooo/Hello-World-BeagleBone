#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "output.h"
#include "led.h"
#include "joystick.h"
#include "timer.h"

int main () {
    Output_printWelcome();

    Output_printInstructions();

    Led_intialize();
    Joystick_intialize();

    bool isGameOver = false;
    while (!isGameOver) {
        Output_printStart();
        Led_turnOn(1);
        Led_turnOn(2);

        Timer_sleepForMs(1000);

        int val = Joystick_getDirection();
        printf("Direction: %d\n", val);
        if (val == JOYSTICK_UP) {
            isGameOver = true;
        }

    }

    Led_turnOff(1);
    Led_turnOff(2);

    

    return 0;
}
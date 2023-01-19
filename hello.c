#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "output.h"
#include "led.h"
#include "joystick.h"
#include "timer.h"

static void intializeHello(void);
static void cleanUpHello(void);

int main () {
    Output_printWelcome();

    intializeHello();

    bool isGameOver = false;
    long long bestTime = 5000;
    while (!isGameOver) {
        Output_printStart();
        Led_turnOn(1);
        Led_turnOn(2);

        int sleepAmount = Timer_getRandomNumberBetween(500, 3000);
        Timer_sleepForMs(sleepAmount);
        
        JoystickDirection direction = Joystick_getDirection();
        if (direction == JOYSTICK_UP || direction == JOYSTICK_DOWN) {
            Output_printFalseStart();
            continue;
        }

        JoystickDirection randomDirection = (JoystickDirection) Timer_flipCoin();
        Output_printDirection(randomDirection);
        Led_turnOff(1);
        Led_turnOff(2);
        if (randomDirection == JOYSTICK_UP) {
            Led_turnOn(0);
        } else {
            Led_turnOn(3);
        }

        long long startTime = Timer_getTimeInMs();
        long long timeDiff = 0;
        long long currentTime = 0;
        direction = Joystick_getDirection();
        while (direction == JOYSTICK_NO_DIRECTION && timeDiff < 5000) {
            direction = Joystick_getDirection();
            currentTime = Timer_getTimeInMs();
            timeDiff = currentTime - startTime;
        }

        Led_turnOff(0);
        Led_turnOff(3);
        
        if (timeDiff >= 5000) {
            Output_printTimeoutQuit();
            isGameOver = true;
            continue;
        }

        if (direction == JOYSTICK_LEFT || direction == JOYSTICK_RIGHT) {
            Output_printUserQuit();
            isGameOver = true;
            continue;
        }

        if (direction == randomDirection) {
            Output_printResult(true);

            if (timeDiff < bestTime) {
                bestTime = timeDiff;
                Output_printBestTime();
            }

            Output_printReactionTime(timeDiff, bestTime);
            Led_flashAll(4);
            Timer_sleepForMs(500);
            Led_unflashAll();

        } else {
            Output_printResult(false);
            Led_flashAll(10);
            Timer_sleepForMs(1000);
            Led_unflashAll();
        }

    }

    cleanUpHello();

    return 0;
}

static void intializeHello(void)
{
    Output_printInstructions();

    Led_intialize();
    Joystick_intialize();

    Timer_intializeRandom();
}

static void cleanUpHello(void)
{
    Led_cleanUp();
    Joystick_cleanUp();
}
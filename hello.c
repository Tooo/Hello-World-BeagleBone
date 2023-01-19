#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "output.h"
#include "led.h"
#include "joystick.h"
#include "timer.h"

#define TIMEOUT_TIME_MS 5000
#define MIN_WAIT_TIME_MS 500
#define MAX_WAIT_TIME_MS 3000

#define WIN_FLASH_HZ 4
#define WIN_FLASH_TIME_MS 500
#define LOSE_FLASH_HZ 10
#define LOSE_FLASH_TIME_MS 1000

static void intializeHello(void);
static void cleanUpHello(void);

int main () {
    Output_printWelcome();

    intializeHello();

    bool isGameOver = false;
    long long bestTime = TIMEOUT_TIME_MS;
    while (!isGameOver) {
        Output_printStart();
        Led_turnOn(LED1);
        Led_turnOn(LED2);

        long long sleepAmount = Timer_getRandomNumberBetween(MIN_WAIT_TIME_MS, MAX_WAIT_TIME_MS);
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
            Led_turnOn(LED0);
        } else {
            Led_turnOn(LED3);
        }

        long long startTime = Timer_getTimeInMs();
        long long timeDiff = 0;
        long long currentTime = 0;
        direction = Joystick_getDirection();
        while (direction == JOYSTICK_NO_DIRECTION && timeDiff < TIMEOUT_TIME_MS) {
            direction = Joystick_getDirection();
            currentTime = Timer_getTimeInMs();
            timeDiff = currentTime - startTime;
        }

        Led_turnOff(LED0);
        Led_turnOff(LED3);
        
        if (timeDiff >= TIMEOUT_TIME_MS) {
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
            Led_flashAll(WIN_FLASH_HZ);
            Timer_sleepForMs(WIN_FLASH_TIME_MS);
            Led_unflashAll();
        } else {
            Output_printResult(false);
            Led_flashAll(LOSE_FLASH_HZ);
            Timer_sleepForMs(LOSE_FLASH_TIME_MS);
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
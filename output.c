#include "output.h"
#include <stdio.h>
#include <stdbool.h>

void Output_printWelcome(void)
{
    printf("Hello embedded world, from Travis!\n");
}

void Output_printInstructions(void)
{
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n");
    printf("(Press left or right to exit)\n");
}

void Output_printStart(void)
{
    printf("Get ready...\n");
}

void Output_printFalseStart(void)
{
    printf("Too Soon!\n");
}

void Output_printDirection(bool up)
{
    if (up) {
        printf("Press UP now!\n");
    } else {
        printf("Press DOWN now!\n");
    }
}

void Output_printResult(bool correct)
{
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }
}

void Output_printBestTime(void)
{
    printf("New best time!\n");
}

void Output_printReactionTime(long long current, long long best)
{
    printf("Your reaction time was %lld; best so far in game is %lld", current, best);
}

void Output_printUserQuit(void)
{
    printf("User selected to quit.\n");
}

void Output_printTimeoutQuit(void)
{
    printf("No input within 5000ms; quitting!");
}
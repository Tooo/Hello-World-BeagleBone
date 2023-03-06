#include <stdio.h>
#include <stdbool.h>

#include "output.h"

void Output_printWelcome(void)
{
    printf("Hello embedded world, from Travis!\n");
}

void Output_printInstructions(void)
{
    printf("\nWhen the LEDs light up, press the joystick in that direction!\n");
    printf("(Press left or right to exit)\n");
}

void Output_printReady(void)
{
    printf("Get ready...\n");
}

void Output_printFalseStart(void)
{
    printf("Too soon!\n");
}

void Output_printUp(void)
{
    printf("Press UP now!\n");
}

void Output_printDown(void)
{
    printf("Press DOWN now!\n");
}

void Output_printWin(void)
{
    printf("Correct!\n");
}

void Output_printLose(void)
{
    printf("Incorrect.\n");
}

void Output_printBestTime(void)
{
    printf("New best time!\n");
}

void Output_printReactionTime(long long current, long long best)
{
    printf("Your reaction time was %lldms; best so far in game is %lldms.\n", current, best);
}

void Output_printUserQuit(void)
{
    printf("User selected to quit.\n");
}

void Output_printTimeoutQuit(void)
{
    printf("No input within 5000ms; quitting!\n");
}
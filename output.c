#include <stdio.h>

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

void Output_printDirection()
{

}

void Output_printResult()
{

}

void Output_printBestTime(void)
{
    printf("New best time!\n");
}

void Output_printReactionTime(long long current, long long best)
{
    printf("Your reaction time was %ld; best so far in game is %ld", current, best);
}

void Output_printUserQuit(void)
{
    printf("User selected to quit.\n");
}

void Output_printTimeoutQuit(void)
{
    printf("No input within 5000ms; quitting!");
}
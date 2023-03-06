// output.h
// Module to manage output
#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdbool.h>

// Welcome and Introduction print
void Output_printWelcome(void);
void Output_printInstructions(void);

// Ready and False Start print
void Output_printReady(void);
void Output_printFalseStart(void);

// Print up/down
void Output_printUp(void);
void Output_printDown(void);

// Print win/lose
void Output_printWin(void);
void Output_printLose(void);

// Print timing of result
void Output_printBestTime(void);
void Output_printReactionTime(long long current, long long best);

// Print when quitting
void Output_printUserQuit(void);
void Output_printTimeoutQuit(void);

#endif
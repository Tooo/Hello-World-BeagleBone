#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdbool.h>

void Output_printWelcome(void);

void Output_printInstructions(void);

void Output_printReady(void);

void Output_printFalseStart(void);

void Output_printUp(void);

void Output_printDown(void);

void Output_printWin(void);

void Output_printLose(void);

void Output_printBestTime(void);

void Output_printReactionTime(long long current, long long best);

void Output_printUserQuit(void);

void Output_printTimeoutQuit(void);

#endif
#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdbool.h>

void Output_printWelcome(void);

void Output_printInstructions(void);

void Output_printStart(void);

void Output_printFalseStart(void);

void Output_printDirection(bool up);

void Output_printResult(bool correct);

void Output_printBestTime(void);

void Output_printReactionTime(long long current, long long best);

void Output_printUserQuit(void);

void Output_printTimeoutQuit(void);

#endif
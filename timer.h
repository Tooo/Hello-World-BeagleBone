#ifndef TIMER_H_
#define TIMER_H_

#include <stdbool.h>

long long Timer_getTimeInMs(void);

void Timer_sleepForMs(long long delayInMs);

void Timer_intializeRandom(void);

int Timer_getRandomNumberBetween(int a, int b);

bool Timer_flipCoin();

#endif
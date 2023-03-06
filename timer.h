// time.h
// Module to manage time and randomizer
#ifndef TIMER_H_
#define TIMER_H_

#include <stdbool.h>

// Get current time in Ms
long long Timer_getTimeInMs(void);

// Sleep for Ms amount of time
void Timer_sleepForMs(long long delayInMs);

// intialize randomizer
void Timer_intializeRandom(void);

// Get random number between a to b
long long Timer_getRandomNumberBetween(long long a, long long b);

// Flip coin of true/false
bool Timer_flipCoin();

#endif
#ifndef TIMER_H_
#define TIMER_H_

long long Timer_getTimeInMs(void);

void Timer_sleepForMs(long long delayInMs);

static const long long NS_PER_MS = 1000 * 1000;

static const long long NS_PER_SECOND = 1000000000;

#endif
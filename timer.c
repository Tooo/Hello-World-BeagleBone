#include "timer.h"

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static const long long NS_PER_MS = 1000 * 1000;
static const long long NS_PER_SECOND = 1000000000;

long long Timer_getTimeInMs(void)
{
    struct timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    long long seconds = spec.tv_sec;
    long long nanoSeconds = spec.tv_nsec;
    long long milliSeconds = seconds * 1000 + nanoSeconds / 1000000;
    return milliSeconds; 
}

void Timer_sleepForMs(long long delayInMs)
{
    long long delayNs = delayInMs * NS_PER_MS;
    int seconds = delayNs / NS_PER_SECOND;
    int nanoseconds = delayNs % NS_PER_SECOND;

    struct timespec reqDelay = {seconds, nanoseconds};
    nanosleep(&reqDelay, (struct timespec *) NULL);
}

void Timer_intializeRandom(void)
{
    time_t t;
    srand(time(&t));
}

long long Timer_getRandomNumberBetween(long long a, long long b)
{
    int diff = b - a + 1;
    int value = rand() % diff;
    return a + value;
}

bool Timer_flipCoin()
{
    return (bool) ((rand() % 2) - 1);
}
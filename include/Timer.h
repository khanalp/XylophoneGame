#ifndef TIMER_H
#define TIMER_H

#include <Windows.h>
class XTimer
{
	long int beginTime;
	long int previousTime;
	long int currentTime;

public:
	
	XTimer(){beginTime = GetTickCount(); previousTime = 0;}
	long int getTimeElapsed();
	void setPreviousTime(long int);
	long int getCurrentTime();
	long int getBeginTime();
	long int getPreviousTime();
	long int getTimeElapsedSince(long int time);
	void resetBeginTime();
};

#endif
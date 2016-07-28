#include "Timer.h"

long int XTimer::getBeginTime()
{
	return beginTime;
}

void XTimer::resetBeginTime()
{
	beginTime = getCurrentTime();
}

void XTimer::setPreviousTime(long int a)
{
	previousTime = a;
}

long int XTimer::getPreviousTime()
{
	//setPreviousTime(getCurrentTime());
	return previousTime ;
}

long int XTimer::getTimeElapsed()
{
	long int curTime = GetTickCount();
	long int timeElapsed = getBeginTime() - curTime;
	return timeElapsed;
}

long int XTimer::getTimeElapsedSince(long int time)
{
	long int curTime = GetTickCount();
	setPreviousTime(curTime);
	long int timeElapsed = curTime - time;
	return timeElapsed;
}

long int XTimer::getCurrentTime()
{
	currentTime = GetTickCount();
	return currentTime;
}
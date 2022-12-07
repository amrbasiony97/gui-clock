#pragma once
#include <chrono>
#include <time.h>

class Time {
private:
	int hour;
	float minute;
	float second;
	float millisecond;

public:
	Time();
	void setHour(int _hour);
	void setMinute(float _minute);
	void setSecond(float _second);
	void setMillisecond(float _millisecond);
	int getHour();
	float getMinute();
	float getSecond();
	float getMillisecond();
	void update_now();
};


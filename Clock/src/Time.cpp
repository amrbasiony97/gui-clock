#include "../include/Time.h"

Time::Time() {
	hour = 0;
	minute = 0;
	second = 0;
	millisecond = 0;
}

void Time::setHour(int _hour) {
	hour = _hour;
}

void Time::setMinute(float _minute) {
	minute = _minute;
}

void Time::setSecond(float _second) {
	second = _second;
}

void Time::setMillisecond(float _millisecond) {
	millisecond = _millisecond;
}

int Time::getHour() {
	return hour;
}

float Time::getMinute() {
	return minute;
}

float Time::getSecond() {
	return second;
}

float Time::getMillisecond() {
	using namespace std::chrono;
	return (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count()) % 1000;
}

void Time::update_now() {
	time_t now = time(0);
	tm* ptm = localtime(&now);

	hour = ptm->tm_hour;
	minute = ptm->tm_min;
	second = ptm->tm_sec;
	millisecond = getMillisecond();
}
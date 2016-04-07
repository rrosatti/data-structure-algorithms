#include "Time.h"

Time::Time(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

int Time::getHour() const {
	return hour;
}

void Time::setHour(int h) {
	hour = h;
}

int Time::getMinute() const {
	return minute;
}

void Time::setMinute(int m) {
	minute = m;
}

int Time::getSecond() const {
	return second;
}

void Time::setSecond(int s) {
	second = s;
} 

void Time::setTime(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}

void Time::nextSecond() {
	if (second == 59)
		second = 0;
	else
		second++;
}
#pragma once

#include "Measure.h"
#include <chrono>
#include <Windows.h>

struct Time {
	long double millennia;
	long double centuries;
	long double decades;
	long double years;
	long double days;
	long double hours;
	long double minutes;
	long double seconds;
	long double milliseconds;
	long double microseconds;
	long double nanoseconds;

	Time(void);
	~Time(void);

	char* toString(void); // make static with time parameter
	void toTime(char* str); // make static and return time

	void only(char* str);
	void only(Time_Measure measure); // create
	void simplify(void);

	bool isNull(void) const;//fix == warning
	void reset(void);

	Time& operator =(const Time& time); // create
	Time& operator =(const std::chrono::high_resolution_clock::duration& duration);
	Time& operator =(const char* str); // create

	const Time operator +(const Time& time) const; // create
	const Time operator -(const Time& time) const; // create
	const Time operator *(const Time& time) const; // create
	const Time operator /(const Time& time) const; // create
	const Time operator %(const Time& time) const; // create

	Time& operator +=(const Time& time); // create
	Time& operator -=(const Time& time); // create
	Time& operator *=(const Time& time); // create
	Time& operator /=(const Time& time); // create
	Time& operator %=(const Time& time); // create

	bool operator >(const Time& time) const; // create
	bool operator <(const Time& time) const; // create
	bool operator >=(const Time& time) const;
	bool operator <=(const Time& time) const;

	bool operator ||(const Time& time) const;
	bool operator ||(const bool& boolean) const;
	bool operator &&(const Time& time) const;
	bool operator &&(const bool& boolean) const;

	 bool operator ==(const Time& time) const; // create
	 bool operator !=(const Time& time) const; // create
	//!(unary) -(unary) +(unary)
};

class Clock {
private:
	std::chrono::high_resolution_clock::time_point t_start, t_end;
public:
	Time t_elapsed;

	Clock(void);
	~Clock(void);

	void start(void);
	void stop(void);
};
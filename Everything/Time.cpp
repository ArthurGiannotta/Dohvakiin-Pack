#include "Time.h"
#include "Util.h"
using namespace util;

Time::Time(void)
{
	this->reset();
}

Time::~Time(void)
{
}

char* Time::toString(void)
{
	this->simplify();
	static char buff[512] = {0};
	sprintf_s(buff, "%.0lfmil %.0lfcen %.0lfdec %.0lfy %.0lfd %.0lfh %.0lfmin %.0lfs %.0lfmi %.0lfus %.0lfns\0", millennia, centuries, decades, years, days, hours, minutes, seconds, milliseconds, microseconds, nanoseconds);
	return buff;
}

void Time::toTime(char* str)
{
	if(str == 0) return;
	sscanf_s(str, "%lfmil %lfcen %lfdec %lfy %lfd %lfh %lfmin %lfs %lfmi %lfus %lfns\0", &millennia, &centuries, &decades, &years, &days, &hours, &minutes, &seconds, &milliseconds, &microseconds, &nanoseconds);
}

void Time::only(char* str)
{
	long double temp = 31536000000000000000.0 * millennia + 3153600000000000000.0 * centuries + 315360000000000000.0 * decades + 31536000000000000.0 * years + 86400000000000.0 * days + 3600000000000.0 * hours + 60000000000.0 * minutes + 1000000000.0 * seconds + 1000000.0 * milliseconds + 1000.0 * microseconds + nanoseconds;
	this->reset();

	switch(util::djb3(str)) {
		case 249787732165023820: millennia = temp / 31536000000000000000.0; break;
		case 249790543320030721: centuries = temp / 3153600000000000000.0; break;
		case 229362479281396: decades = temp / 315360000000000000.0; break;
		case 210651482361: years = temp / 31536000000000000.0; break;
		case 6382345578: days = temp / 86400000000000.0; break;
		case 210631132022: hours = temp / 3600000000000.0; break;
		case 229373499281336: minutes = temp / 60000000000.0; break;
		case 229396723379654: seconds = temp / 1000000000.0; break;
		case 11504111176947165643: milliseconds = temp / 1000000.0; break;
		case 11503552871005171772: microseconds = temp / 1000.0; break;
		case 13772419556497463688: nanoseconds = temp; break;
		default: break;
	}
}

void Time::simplify(void)
{
	nanoseconds = 31536000000000000000.0 * millennia + 3153600000000000000.0 * centuries + 315360000000000000.0 * decades + 31536000000000000.0 * years + 86400000000000.0 * days + 3600000000000.0 * hours + 60000000000.0 * minutes + 1000000000.0 * seconds + 1000000.0 * milliseconds + 1000.0 * microseconds + nanoseconds;
	millennia = centuries = decades = years = days = hours = minutes = seconds = milliseconds = microseconds = 0.0;

	long long temp;

	temp = (long long)(nanoseconds / 1000.0);
	nanoseconds -= temp * 1000;
	microseconds += temp;

	temp = (long long)(microseconds / 1000.0);
	microseconds -= temp * 1000;
	milliseconds += temp;

	temp = (long long)(milliseconds / 1000.0);
	milliseconds -= temp * 1000;
	seconds += temp;

	temp = (long long)(seconds / 60.0);
	seconds -= temp * 60;
	minutes += temp;

	temp = (long long)(minutes / 60.0);
	minutes -= temp * 60;
	hours += temp;

	temp = (long long)(hours / 24.0);
	hours -= temp * 24;
	days += temp;

	temp = (long long)(days / 365.0);
	days -= temp * 365;
	years += temp;

	temp = (long long)(years / 10.0);
	years -= temp * 10;
	decades += temp;

	temp = (long long)(decades / 10.0);
	decades -= temp * 10;
	centuries += temp;

	temp = (long long)(centuries / 10.0);
	centuries -= temp * 10;
	millennia += temp;
}

bool Time::isNull(void) const
{
	return (millennia == centuries == decades == years == days == hours == minutes == seconds == milliseconds == microseconds == nanoseconds == 0.0);
}

void Time::reset(void)
{
	millennia = centuries = decades = years = days = hours = minutes = seconds = milliseconds = microseconds = nanoseconds = 0.0;
}

Time& Time::operator =(const std::chrono::high_resolution_clock::duration& duration)
{
	this->reset();
	nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
	this->simplify();

	return *this;
}

bool Time::operator >=(const Time& time) const
{
	Time left = *this, right = time;

	left.simplify();
	right.simplify();

	if(left.millennia < right.millennia) return false;
	else if(left.millennia > right.millennia) return true;
	else if(left.centuries < right.centuries) return false;
	else if(left.centuries > right.centuries) return true;
	else if(left.decades < right.decades) return false;
	else if(left.decades > right.decades) return true;
	else if(left.years < right.years) return false;
	else if(left.years > right.years) return true;
	else if(left.days < right.days) return false;
	else if(left.days > right.days) return true;
	else if(left.hours < right.hours) return false;
	else if(left.hours > right.hours) return true;
	else if(left.minutes < right.minutes) return false;
	else if(left.minutes > right.minutes) return true;
	else if(left.seconds < right.seconds) return false;
	else if(left.seconds > right.seconds) return true;
	else if(left.milliseconds < right.milliseconds) return false;
	else if(left.milliseconds > right.milliseconds) return true;
	else if(left.microseconds < right.microseconds) return false;
	else if(left.microseconds > left.microseconds) return true;
	else if(left.nanoseconds < right.nanoseconds) return false;
	else return true;
}

bool Time::operator <=(const Time& time) const
{
	Time left  = *this, right = time;

	left.simplify();
	right.simplify();

	if(left.millennia > right.millennia) return false;
	else if(left.millennia < right.millennia) return true;
	else if(left.centuries > right.centuries) return false;
	else if(left.centuries < right.centuries) return true;
	else if(left.decades > right.decades) return false;
	else if(left.decades < right.decades) return true;
	else if(left.years > right.years) return false;
	else if(left.years < right.years) return true;
	else if(left.days > right.days) return false;
	else if(left.days < right.days) return true;
	else if(left.hours > right.hours) return false;
	else if(left.hours < right.hours) return true;
	else if(left.minutes > right.minutes) return false;
	else if(left.minutes < right.minutes) return true;
	else if(left.seconds > right.seconds) return false;
	else if(left.seconds < right.seconds) return true;
	else if(left.milliseconds > right.milliseconds) return false;
	else if(left.milliseconds < right.milliseconds) return true;
	else if(left.microseconds > right.microseconds) return false;
	else if(left.microseconds < left.microseconds) return true;
	else if(left.nanoseconds > right.nanoseconds) return false;
	else return true;
}

bool Time::operator ||(const Time& time) const
{
	return this->isNull() || time.isNull();
}

bool Time::operator ||(const bool& boolean) const
{
	return this->isNull() || boolean;
}

bool Time::operator &&(const Time& time) const
{
	return this->isNull() && time.isNull();
}

bool Time::operator &&(const bool& boolean) const
{
	return this->isNull() && boolean;
}

Clock::Clock(void)
{
}

Clock::~Clock(void)
{
}

void Clock::start(void)
{
	t_start = std::chrono::high_resolution_clock::now();
}

void Clock::stop(void)
{
	t_end = std::chrono::high_resolution_clock::now();
	t_elapsed = t_end - t_start;
}

bool operator ||(const bool& boolean, const Time& time)
{
	return boolean || time.isNull();
}

bool operator &&(const bool& boolean, const Time& time)
{
	return boolean && time.isNull();
}
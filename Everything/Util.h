#pragma once
#include "Time.h"

/** Macros **/

#define GLUE(X,Y) X ## Y
#define MAX(X,Y) X > Y ? : X : Y
#define MIN(X,Y) X < Y ? : X : Y

/** Functions **/

namespace util {
	// Delete n characters in console
	void backspace(unsigned int n = 1);

	// Hash a string into an int with djb2 algorithm
	unsigned long long djb2(char* str);
	unsigned long long djb2(unsigned char* str);

	// Hash a string into an int with djb3 algorithm
	unsigned long long djb3(char* str);
	unsigned long long djb3(unsigned char* str);

	// Get user input within time
	bool timed_input(char* buffer, size_t size, Time timeout);
};
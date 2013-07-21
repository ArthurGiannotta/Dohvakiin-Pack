#include "Util.h"
#include <conio.h>
#include <iostream>
using namespace std;

void util::backspace(unsigned int n)
{
	for(unsigned int i = 0; i < n; i++)
		cout << '\b' << '\0' << '\b';
}

unsigned long long util::djb2(char* str)
{
	return djb2(reinterpret_cast<unsigned char*>(str));
}

unsigned long long util::djb2(unsigned char* str)
{
	unsigned long long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) + c;
	return hash;
}

unsigned long long util::djb3(char* str)
{
	return djb3(reinterpret_cast<unsigned char*>(str));
}

unsigned long long util::djb3(unsigned char* str)
{
	unsigned long long hash = 5381;
	int c;
	while (c = *str++)
		hash = ((hash << 5) + hash) ^ c;
	return hash;
}

bool util::timed_input(char* buffer, size_t size, Time timeout)
{
	size_t n = 0;
	Clock clock;
	clock.start();

	while(n < size) {
		clock.stop();

		if(clock.t_elapsed >= timeout) {
			buffer[n] = '\0';
			return false;
		}

		if(_kbhit()) {
			char c = (n == size - 1) ? '\r' : static_cast<char>(_getch());
			switch(c) {
				case '\b': if(n > 0) {n--; util::backspace();} break;
				case '\r': buffer[n] = '\0'; cout << '\n'; return true; break;
				default: buffer[n++] = c; cout << c; break; // support for changing cursor position and delete button and insert button esc(27) 
			}
		}
	}

	buffer[n] = '\0';
	return true;
}
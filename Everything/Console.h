#pragma once

#include "Singleton.h"

class Console {
private:
	char* input;
	unsigned int inputN;

	void resetInput(void);
public:
	Console(void);
	~Console(void);

	void tick(void);
	void onCommand(void);
};

#define CONSOLE Singleton<Console>::instance()
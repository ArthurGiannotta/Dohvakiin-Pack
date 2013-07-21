#pragma once

#include "Console.h"
#include "Debugger.h"
#include "SDL_Manager.h"

#define EVERYTHING_CONSOLE_MODE 0
#define EVERYTHING_SDL_MODE 1
#define EVERYTHING_DIRECTX_MODE 2

class Everything {
private:
	bool quit;

	void initConsoleMode(void);
	void initSDLMode(void);
	void initDirectXMode(void);

	void runConsoleMode(void);
	void runSDLMode(void);
	void runDirectXMode(void);
public:
	Everything(void);
	~Everything(void);

	bool getQuit(void);
	void toggleQuit(void);

	void init(int mode);
	void (Everything::*run)(void);
};

#define EVERYTHING Singleton<Everything>::instance()
#include "Everything.h"

Everything::Everything(void) :
	quit(false)
{
	DEBUGGER.openDEBUG("everything.dbg");
	DEBUGGER.openLOG("everything.log");

	DEBUGGER.debug(CLASS_INIT, "Main class initialized successfully");
}

Everything::~Everything(void)
{
	DEBUGGER.debug(CLASS_DESTRUCT, "Main class destructed successfully");

	DEBUGGER.closeDEBUG();
	DEBUGGER.closeLOG();
}

bool Everything::getQuit(void)
{
	return quit;
}

void Everything::toggleQuit(void)
{
	quit = !quit;
}

void Everything::init(int mode)
{
	switch(mode) {
		case EVERYTHING_CONSOLE_MODE: initConsoleMode(); this->run = &Everything::runConsoleMode; break;
		case EVERYTHING_SDL_MODE: initSDLMode(); this->run = &Everything::runSDLMode; break;
		case EVERYTHING_DIRECTX_MODE: initDirectXMode(); this->run = &Everything::runDirectXMode; break;
	}
}

void Everything::initConsoleMode(void)
{
}

void Everything::initSDLMode(void)
{
}

void Everything::initDirectXMode(void)
{
}

void Everything::runConsoleMode(void)
{
	CONSOLE.tick();
}

void Everything::runSDLMode(void)
{
}

void Everything::runDirectXMode(void)
{
}
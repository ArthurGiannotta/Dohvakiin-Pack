#pragma once

#include "Global.h"
#include "Module.h"
#include "Singleton.h"
#include <fstream>
using namespace std;

namespace module {
	
}

class Debugger {
private:
	fstream f_debug;
	fstream f_log;

	char* Debugger::toString(Debug_Module module);
	char* Debugger::toString(Log_Module module);
public:
	Debugger(void);
	~Debugger(void);

	void openDEBUG(char* debugName = DEFAULT_DEBUG_FILE);
	void closeDEBUG(void);
	void debug(const char* format, ...);
	void debug(Debug_Module module, const char* format, ...);

	void openLOG(char* logName = DEFAULT_LOG_FILE);
	void closeLOG(void);
	void log(const char* format, ...);
	void log(Log_Module module, const char* format, ...);
};

#define DEBUGGER Singleton<Debugger>::instance()
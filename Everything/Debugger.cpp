#include "Debugger.h"
#include <cstdarg>
#include <tchar.h>

Debugger::Debugger(void)
{
}

Debugger::~Debugger(void)
{
#ifdef DEBUGGER_DEBUG
	closeDEBUG();
#endif
#ifdef DEBUGGER_LOG
	closeLOG();
#endif
}

void Debugger::openDEBUG(char* debugName)
{
#ifdef DEBUGGER_DEBUG
	closeDEBUG();
	f_debug.open(debugName, fstream::in | fstream::out | fstream::trunc);
#endif
}

void Debugger::closeDEBUG(void)
{
#ifdef DEBUGGER_DEBUG
	if(f_debug.is_open()) {
		f_debug.close();
	}
#endif
}

void Debugger::debug(const char* format, ...)
{
	
#ifdef DEBUGGER_DEBUG
	char buff[1024] = {0};
	va_list list;
	va_start(list, format);
	_vstprintf_s(buff, 1024, format, list);
	va_end(list);
	f_debug << toString(DEBUG) << buff << endl;
#endif
}

void Debugger::debug(Debug_Module module, const char* format, ...)
{
#ifdef DEBUGGER_DEBUG
	char buff[1024] = {0};
	va_list list;
	va_start(list, format);
	_vstprintf_s(buff, 1024, format, list);
	va_end(list);
	f_debug << toString(module) << buff << endl;
#endif
}

char* Debugger::toString(Debug_Module module)
{
	char* str = 0;
	switch(module) {
		case CLASS_INIT: str = "Class Initialization : "; break;
		case CLASS_DESTRUCT: str = "Class Destruction    : "; break;
		case KEYBOARD_INPUT: str = "Keyboard Input       : "; break;
		case DEBUG: str = "Debug                : "; break;
		default: str = "Debug                : "; break;
	}
	return str;
}

void Debugger::openLOG(char* logName)
{
#ifdef DEBUGGER_LOG
	closeLOG();
	f_log.open(logName, fstream::in | fstream::out | fstream::app);
#endif
}

void Debugger::closeLOG(void)
{
#ifdef DEBUGGER_LOG
	if(f_log.is_open()) {
		f_log.close();
	}
#endif
}

void Debugger::log(const char* format, ...)
{
#ifdef DEBUGGER_LOG
	char buff[1024] = {0};
	va_list list;
	va_start(list, format);
	_vstprintf_s(buff, 1024, format, list);
	va_end(list);
	f_log << toString(LOG) << buff << endl;
#endif
}

void Debugger::log(Log_Module module, const char* format, ...)
{
#ifdef DEBUGGER_LOG
	char buff[1024] = {0};
	va_list list;
	va_start(list, format);
	_vstprintf_s(buff, 1024, format, list);
	va_end(list);
	f_log << toString(module) << buff << endl;
#endif
}

char* Debugger::toString(Log_Module module)
{
	char* str = 0;
	switch(module) {
		case LOG: str = "Log : "; break;
		default: str = "Log : "; break;
	}
	return str;
}
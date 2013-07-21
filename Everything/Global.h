#pragma once

#include "Util.h"

/* Console.h */

#define MAX_COMMAND_SIZE 128

/* Debugger.h */

#define DEBUGGER_DEBUG
#define DEBUGGER_LOG

#define DEFAULT_DEBUG_FILE "debug.dbg"
#define DEFAULT_LOG_FILE "log.log"

/* Util.h */

#define HASH(str) util::djb3(str)
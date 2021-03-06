/*
** LuaProfiler 2.0
** Copyright Kepler Project 2005 (http://www.keplerproject.org/luaprofiler)
** $Id: core_profiler.h,v 1.4 2005/06/13 19:34:58 mascarenhas Exp $
*/

/*****************************************************************************
core_profiler.h:
   Lua version independent profiler interface.
   Responsible for handling the "enter function" and "leave function" events
   and for writing the log file.

Design (using the Lua callhook mechanism) :
   'lprofP_init_core_profiler' set up the profile service
   'lprofP_callhookIN'         called whenever Lua enters a function
   'lprofP_callhookOUT'        called whenever Lua leaves a function
*****************************************************************************/

#include "stack.h"

#ifndef LUAPROFILER_API
#define LUAPROFILER_API extern
#endif

/* computes new stack and new timer */
void lprofP_callhookIN(lprofP_STATE* S, char *source, char *func_name, char *file, int linedefined, int currentline);

/* pauses all timers to write a log line and computes the new stack */
/* returns if there is another function in the stack */
int  lprofP_callhookOUT(lprofP_STATE* S);

/* opens the log file */
/* returns true if the file could be opened */
lprofP_STATE* lprofP_init_core_profiler(const char *_out_filename, int isto_printheader, float _function_call_time);


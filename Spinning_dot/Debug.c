#include "Debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void func_DBG_MSG(const char* file, int line, const char* function, const char* msg, ...) {
	char strTime[9];
	strftime(
		strTime,
		sizeof(strTime),
		"%T",
		localtime(&(time_t) { time(NULL) })
	);
	printf_s("[%s][%s:%d, %s] ", strTime, file, line, function);

	va_list argList;
	va_start(argList, msg);
	vprintf_s(msg, argList);
	va_end(argList);

	putchar('\n');
}
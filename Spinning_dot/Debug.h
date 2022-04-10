#ifndef DEBUG_H
#define DEBUG_H

#define DBG_MSG(...) func_DBG_MSG(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
void func_DBG_MSG(const char* file, int line, const char* function, const char* msg, ...);

#endif // !DEBUG_H
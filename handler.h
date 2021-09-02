#ifndef ARGS_HANDLER
#define ARGS_HANDLER

#include "headers.h"

int getRealArgc(char **);
char **getPassedArguments(int, char **);
char **getProgramOptions(int, char **);
char ***parseArgs(int, char **);

#endif
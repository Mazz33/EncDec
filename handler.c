#include "handler.h"

//Get the argument count of passed values without program arguments
int getRealArgc(char** argv)
{
    int realArgc = 0;
    for (size_t i = 0; argv[i]; i++) {
        if (argv[i][0] == '-')
            continue;
        realArgc++;
    }
    return realArgc;
}

char** getPassedArguments(int argc, char** argv)
{
    char** args = malloc(sizeof(char*) * (argc - 1)); //TODO: pass arguments count into here somehow
    unsigned counter = 0;
    for (size_t i = 0; argv[i]; i++) {
        if (argv[i][0] == '-') {
            strcpy(args[counter], argv[i]);
            counter++;
        }
    }
    return args;
}
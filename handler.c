#include "handler.h"

//Get the argument count of passed values without program arguments
int getRealArgc(char **argv)
{
    int realArgc = 0;
    for (size_t i = 0; argv[i]; i++)
    {
        if (argv[i][0] == '-')
            continue;
        realArgc++;
    }
    return realArgc;
}

char ***parseArgs(int argc, char **argv)
{
    if (argc == 0)
    {
        return NULL;
    }
    size_t arraySize = sizeof(char *) * argc;
    char ***arrOfArgvs = malloc(arraySize * 2); //a 2d array containing 2 arrays, first is the command line options, second is values passed to give to the verifier
    char **options = malloc(arraySize);
    char **values = malloc(arraySize);
    unsigned optionsCounter = 0, valuesCounter = 0;
    size_t i;
    for (i = 1; argv[i]; i++)
    {
        if (argv[i][0] == '-')
        {
            values[valuesCounter] = argv[i];
            optionsCounter++;
        }
        else
        {
            values[valuesCounter] = argv[i];
            valuesCounter++;
        }
    }
    values[i] = '\0';
    options[i] = '\0';
    memcpy(&arrOfArgvs[0], options, optionsCounter);
    memcpy(&arrOfArgvs[1], values, valuesCounter);
    free(options);
    free(values);
    return arrOfArgvs;
}
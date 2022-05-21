#include "../headers/headers.h"

// Get the argument count of passed values without program arguments
int getRealArgc(char **argv)
{
    int realArgc = 0;
    for (size_t i = 0; argv[i] != '\0'; i++)
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
        return '\0';
    }
    size_t arraySize = sizeof(char *) * argc;
    char ***arrOfArgvs = malloc(arraySize * 2); // a 2d array containing 2 arrays, first is the command line options, second is values passed to give to the verifier
    arrOfArgvs[0] = malloc(arraySize);
    arrOfArgvs[1] = malloc(arraySize);
    if (!arrOfArgvs)
    {
        puts("Error, Can't assign memory");
        free(arrOfArgvs);
        return '\0';
    }
    unsigned optionsCounter = 0, valuesCounter = 0;
    size_t i;
    for (i = 1; argv[i] != '\0'; i++)
    {
        if (argv[i][0] == '-')
        {
            arrOfArgvs[0][optionsCounter] = malloc(strlen(argv[i]) + 1);
            strcpy(arrOfArgvs[0][optionsCounter], argv[i]);
            optionsCounter++;
        }
        else
        {
            arrOfArgvs[1][valuesCounter] = malloc(strlen(argv[i]) + 1);
            strcpy(arrOfArgvs[1][valuesCounter], argv[i]);
            valuesCounter++;
        }
    }
    arrOfArgvs[0][optionsCounter] = '\0';
    arrOfArgvs[1][valuesCounter] = '\0';

    return arrOfArgvs;
}

int getCipher(char **argv)
{
    size_t i;
    for (i = 0; argv[i] != '\0'; i++)
    {
        if (!strcmp(argv[i], "-ceaser"))
        {
            return CEASER_CIPHER;
        }
        if (!strcmp(argv[i], "-atbash"))
        {
            return ATBASH_CIPHER;
        }
    }
    return UNKNOWN_CIPHER;
}
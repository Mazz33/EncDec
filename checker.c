#include "checker.h"
#include "ciphers.h"

int verifyArg(int argc, char **argv, int cipher)
{
    if (argc <= 1)
    {
        return INVALID_NUMBER_OF_ARGUMENTS;
    }

    switch (cipher)
    {
    case CEASER_CIPHER:
        ASSERT_ARGC(argc, 3);
        ASSERT_NUM(argv[2]);
        ASSERT_SIGN(atoi(argv[2]), 1);
        ASSERT_SIZE(argv[1], 1023);
        return GOOD;
        break;
    default:
        return UNKNOWN_CIPHER;
    }
}
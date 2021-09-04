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
        ASSERT_ARGC(argc, 2);
        ASSERT_NUM(argv[1]);
        ASSERT_SIGN(atoi(argv[1]), 1);
        return GOOD;
        break;
    case ATBASH_CIPHER:
        ASSERT_ARGC(argc, 1);
        return GOOD;
    default:
        return UNKNOWN_CIPHER;
    }
}
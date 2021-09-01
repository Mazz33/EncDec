#ifndef BIG_CHECKER
#define BIG_CHECKER

#include "headers.h"

//Argument types return types
#define GOOD 1
#define UKNOWN 0
#define INVALID_NUMBER_OF_ARGUMENTS -1
#define WRONG_ARGUMENTS_TYPE -2
#define LARGE_INPUT -3
#define UNKNOWN_CIPHER -4
#define UNSUPPORTED_KEY -5
//Assert number of passed arguments is enough
#define ASSERT_ARGC(ARGC, B) \
    if (ARGC < B)            \
        return INVALID_NUMBER_OF_ARGUMENTS;
//Assert the string is only numbers for atoi()
#define ASSERT_NUM(A)                               \
    for (int Iter_ = 0; Iter_ < strlen(A); Iter_++) \
    {                                               \
        if (!isdigit(A[Iter_]))                     \
            return WRONG_ARGUMENTS_TYPE;            \
    }
//Assert number is negative/positive
#define ASSERT_SIGN(NUM, SIGN)  \
    if (SIGN > 0 && NUM < 0)    \
        return UNSUPPORTED_KEY; \
    if (SIGN < 0 && NUM > 0)    \
        return UNSUPPORTED_KEY;
//Confirm size
#define ASSERT_SIZE(STR, SIZE)   \
    if (strlen(STR) >= SIZE - 1) \
        return LARGE_INPUT;

int verifyArg(int, char **, int);
#endif
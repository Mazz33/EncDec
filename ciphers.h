#ifndef MANY_CIPHERS
#define MANY_CIPHERS

#include "headers.h"

enum Ciphers
{
	UNKNOWN_CIPHER,
	CEASER_CIPHER,
	ATBASH_CIPHER
};

//returns a new string, does not alter the passed string. This is due to changing memory size incase replacement was bigger.
char *replace_str(char *, char *, char *);
char *ceaserEnc(char *, int);
char *ceaserDec(char *, int);
char *atbash(char *);
char *rot13(char *);

#endif
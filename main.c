#include "headers.h"
#include "ciphers.h"
#include "checker.h"

int main(int argc, char **argv)
{
	int verifier = verifyArg(argc, argv, CEASER_CIPHER);
	switch (verifier)
	{
	case GOOD:
		break;
	case INVALID_NUMBER_OF_ARGUMENTS:
		puts("Invalid number of arguments provided");
		return verifier;
	case WRONG_ARGUMENTS_TYPE:
		puts("Wrong argument type given!");
		return verifier;
	case LARGE_INPUT:
		puts("Very large input, sorry");
		return verifier;
	case UNKNOWN_CIPHER:
		puts("This cipher is unknown or unsupported..");
		return verifier;
	case UNSUPPORTED_KEY:
		puts("The key given is incorrect or not supported.");
		return verifier;
	default:
		return UKNOWN;
	}
	char *inp = malloc(1024);
	strcpy(inp, argv[1]);
	int key = atoi(argv[2]);
	char *ciph = atbash(inp);
	puts(ciph);

	free(inp);
	free(ciph);
	return 0;
}

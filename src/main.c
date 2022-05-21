#include "../headers/headers.h"
#include "../headers/ciphers.h"
#include "../headers/checker.h"
#include "../headers/handler.h"

void freeMemory();

int main(int argc, char **argv)
{
	int realArgc = getRealArgc(argv);
	char ***splitArgs = parseArgs(argc, argv);
	if (!splitArgs)
		return INVALID_NUMBER_OF_ARGUMENTS;
	char **optionsArgv = splitArgs[0];
	char **valuesArgv = splitArgs[1];
	int cipher = getCipher(optionsArgv);
	if (!cipher)
	{
		return INVALID_NUMBER_OF_ARGUMENTS;
	}
	int verifier = verifyArg(realArgc, valuesArgv, cipher);
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
	strcpy(inp, valuesArgv[0]);
	char *ciph = NULL;
	if (verifier == CEASER_CIPHER)
	{
		int key = atoi(valuesArgv[1]);
		ciph = ceaser(inp, key);
	}
	else if (verifier == ATBASH_CIPHER)
	{
		ciph = atbash(inp);
	}
	puts(ciph);

	free(optionsArgv);
	free(valuesArgv);
	free(splitArgs);
	free(inp);
	free(ciph);
	return 0;
}
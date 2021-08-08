#include <stdio.h>

char* ceaser(char*, int);

int main(int argc, char** argv)
{
	if (argc <= 1) {
		puts("No arguments were input, exititng!");
		return -1;
	} else if (argc == 2) {
		puts("Must enter the key after the the plain text");
	}

	
	char* inp = malloc(1024);
	if (strlen(argv[1]) > 1023) {
		puts("Sorry, Very large input");
	}

	inp = argv[1];
	char* ciph = ceaser(inp, 
	return 0;
}

char* ceaser(char* plain, int key)
{
	if (key == 0)
		return plain;
	char* cipher = malloc(strlen(plain) + 1);
	for (int i = 0; i < strlen(plain); i++) {
		cipher[i] = plain[i] + key;
	}
	return cipher;
}

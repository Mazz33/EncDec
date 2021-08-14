#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ceaser(char*, int);

int main(int argc, char** argv)
{
	if (argc <= 1) {
		puts("No arguments were input, exititng!");
		return -1;
	} else if (argc == 2) {
		puts("Must enter the key after the the plain text");
		return -1;
	}
	
	if (strlen(argv[1]) > 1023) {
		puts("Sorry, Very large input");
		return -2;
	}

	char* inp = malloc(1024);
	strcpy(inp, argv[1]);
	//verify argv[2] is an int
	int key = atoi(argv[2]);
	char* ciph = ceaser(inp, key); 

	puts(ciph);

	free(inp); free(ciph);
	return 0;
}

char* ceaser(char* plain, int key)
{
	char* cipher = malloc(strlen(plain) + 1);
	if (key == 0) {
		strcpy(cipher, plain);
		return cipher;
	}
	for (int i = 0; i < strlen(plain) + 1; i++) {
		cipher[i] = plain[i] + key;
	}
	return cipher;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum Ciphers {
	CEASER_CIPHER
};

char* ceaser(char*, int);
int verifyArg(int, char*, int);

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
	for (int i = 0; i < strlen(argv[2]); i++) {
		if (!isdigit(argv[2][i])) {
			puts("Key must be a positive int!");
			return -2;
		}
	}
	char* inp = malloc(1024);
	strcpy(inp, argv[1]);
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
		if (!isalpha(plain[i])) {
			cipher[i] = plain[i];
			continue;
		}
		if(isupper(plain[i])) {
			cipher[i] = (plain[i] - 'A' + key) % 26 + 'A'; 
		}
		else {
			cipher[i] = (plain[i] - 'a' + key) % 26 + 'a';
		}
	}
	return cipher;
}


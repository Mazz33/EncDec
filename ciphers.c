#include "ciphers.h"

char *ceaser(char *plain, int key)
{
    char *cipher = malloc(strlen(plain) + 1);
    if (key == 0)
    {
        strcpy(cipher, plain);
        return cipher;
    }

    for (int i = 0; i < strlen(plain) + 1; i++)
    {
        if (!isalpha(plain[i]))
        {
            cipher[i] = plain[i];
            continue;
        }
        if (isupper(plain[i]))
        {
            cipher[i] = (plain[i] - 'A' + key) % 26 + 'A';
        }
        else
        {
            cipher[i] = (plain[i] - 'a' + key) % 26 + 'a';
        }
    }
    return cipher;
}

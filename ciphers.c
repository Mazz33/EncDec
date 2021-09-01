#include "ciphers.h"

char *replace_str(char *baseStr, char *pattern, char *replacement)
{
    if (!baseStr || !pattern)
        return NULL;
    if (!strlen(baseStr) || !strlen(pattern))
        return NULL;

    char *result;
    size_t lenPattern = strlen(pattern);
    if (!replacement)
        replacement = "";
    size_t lenReplacement = strlen(replacement);
}

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

char *atbash(char *plain)
{
    char *decKey = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *encKey = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    char *cipherText = malloc(strlen(plain) + 1);
    for (size_t i = 0; !(*plain); i++)
    {
        for (size_t j = 0; !(*decKey); j++)
        {
            if (plain[i] == decKey[j])
            {
                cipherText += encKey[j];
                break;
            }
        }
    }

    return cipherText;
}
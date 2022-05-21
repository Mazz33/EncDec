#include "../headers/ciphers.h"

char *replace_str(char *baseStr, char *pattern, char *replacement)
{
    if (!baseStr || !pattern)
        return '\0';
    if (!strlen(baseStr) || !strlen(pattern))
        return '\0';

    char *result = malloc(1024); // TODO: calculate result size needed.
    if (!replacement)
        replacement = "";
    int shouldReplace = FALSE;
    size_t lenReplacement = strlen(replacement);
    for (size_t i = 0; baseStr[i]; i++)
    {
        if (baseStr[i] == pattern[i])
        {
            shouldReplace = TRUE;
            for (size_t j = 0, k = i; pattern[j]; j++, k++)
            {
                if (baseStr[k] != pattern[j])
                {
                    shouldReplace = FALSE;
                    break;
                }
            }
            if (shouldReplace)
            {
                for (size_t j = 0; replacement[j]; j++)
                {
                    result[i] = replacement[j];
                }
                i += lenReplacement;
                continue;
            }
        }
        result[i] = baseStr[i];
    }
    size_t finalLen = strlen(result);
    char *finalResult = malloc(finalLen);
    strcpy(finalResult, result);
    free(result);

    return finalResult;
}

char *ceaserEnc(char *plain, int key)
{
    char *cipher = malloc(strlen(plain) + 1);
    if (key == 0)
    {
        strcpy(cipher, plain);
        return cipher;
    }

    for (size_t i = 0; plain[i]; i++)
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

char *ceaserDec(char *plain, int key)
{
    char *cipher = malloc(strlen(plain) + 1);
    if (key == 0)
    {
        strcpy(cipher, plain);
        return cipher;
    }

    for (size_t i = 0; plain[i]; i++)
    {
        if (!isalpha(plain[i]))
        {
            cipher[i] = plain[i];
            continue;
        }
        if (isupper(plain[i]))
        {
            cipher[i] = (plain[i] - 'A' - key) % 26 + 'A';
        }
        else
        {
            cipher[i] = (plain[i] - 'a' - key) % 26 + 'a';
        }
    }
    return cipher;
}

char *atbashEnc(char *plain)
{
    char *decKey = "abcdefghijklmnopqrstuvwxyz";
    char *encKey = "zyxwvutsrqponmlkjihgfedcba";

    char *cipherText = malloc(strlen(plain) + 1);
    size_t i;
    for (i = 0; plain[i]; i++)
    {
        if (isupper(plain[i]))
            plain[i] += 32;
        for (size_t j = 0; decKey[j]; j++)
        {
            if (plain[i] == decKey[j])
            {
                cipherText[i] = encKey[j];
                break;
            }
        }
    }
    cipherText[i] = '\0';
    return cipherText;
}

char *atbashDec(char *plain)
{
    char *decKey = "abcdefghijklmnopqrstuvwxyz";
    char *encKey = "zyxwvutsrqponmlkjihgfedcba";

    char *cipherText = malloc(strlen(plain) + 1);
    size_t i;
    for (i = 0; plain[i]; i++)
    {
        if (isupper(plain[i]))
            plain[i] += 32;
        for (size_t j = 0; encKey[j]; j++)
        {
            if (plain[i] == encKey[j])
            {
                cipherText[i] = decKey[j];
                break;
            }
        }
    }
    cipherText[i] = '\0';
    return cipherText;
}

char *rot13Enc(char *plain)
{
    char *decKey = "abcdefghijklmnopqrstuvwxyz";
    char *encKey = "nopqrstuvwxyzabcdefghijklm";

    char *cipherText = malloc(strlen(plain) + 1);
    size_t i;
    for (i = 0; plain[i]; i++)
    {
        if (isupper(plain[i]))
            plain[i] += 32;
        for (size_t j = 0; decKey[j]; j++)
        {
            if (plain[i] == decKey[j])
            {
                cipherText[i] = encKey[j];
                break;
            }
        }
    }
    cipherText[i] = '\0';
    return cipherText;
}

char *rot13Dec(char *plain)
{
    char *decKey = "abcdefghijklmnopqrstuvwxyz";
    char *encKey = "nopqrstuvwxyzabcdefghijklm";

    char *cipherText = malloc(strlen(plain) + 1);
    size_t i;
    for (i = 0; plain[i]; i++)
    {
        if (isupper(plain[i]))
            plain[i] += 32;
        for (size_t j = 0; encKey[j]; j++)
        {
            if (plain[i] == encKey[j])
            {
                cipherText[i] = decKey[j];
                break;
            }
        }
    }
    cipherText[i] = '\0';
    return cipherText;
}

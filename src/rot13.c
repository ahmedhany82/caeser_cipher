#include <stdlib.h>
#include <string.h>

/*
ROT13 ("rotate by 13 places") is a substitution cipher that
replaces a letter with the 13th letter after it in the alphabet.
 */
char *decode_rot13(const char *src)
{
    if(src == NULL){
        return NULL;
    }

    char* result = malloc(strlen(src) + 1);
    if(result == NULL) {
        return NULL;
    }

    int i = 0;
    while(src[i] != '\0'){
        if((src[i] >= 'a' && src[i] <='m') || (src[i] >= 'A' && src[i] <= 'M'))
            result[i] = (char)(src[i] + 13);
        else if((src[i] > 'm' && src[i] <= 'z') || (src[i] > 'M' && src[i] <= 'Z'))
            result[i] = (char)(src[i] - 13);
        else
            result[i] = src[i];

        i++;
    }
    result[i] = '\0';
    return result;
}
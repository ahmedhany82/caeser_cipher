#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Decrypt a message using Caeser cipher (Caeser shift) with given key */
char *caeser_cipher(const char *src, char key)
{
    if(src == NULL || key < 0 || key > 25){
        return NULL;
    }

    char* result = malloc(strlen(src) + 1);
    if(result == NULL) {
        return NULL;
    }

    int i = 0;
    while(src[i] != '\0'){
        if(src[i] >= 'a' && src[i] <='z') {
            result[i] =  (char)('a' + ((src[i] - 'a' - key + 26) % 26));
        }
        else if(src[i] >= 'A' && src[i] <='Z') {
            result[i] = (char)('A' + ((src[i] - 'A' - key + 26) % 26));
        } else {
            result[i] = src[i];
        }
        i++;
    }
    result[i] = '\0';
    return result;
}

/* Brute force all possible keys */
void find_key(const char *src) {

    if(src == NULL) {
        printf("The provided string is NULL/n");
        return;
    }
    for(int key = 0; key <= 25; ++key) {
        char *result = caeser_cipher(src, (char)key);
        if(result == NULL) {
            printf("An error occurred in caeser_cipher for key %d\n", key);
            continue;
        }
        printf("%d\t%s\n", key, result);
        free(result);
    }
}

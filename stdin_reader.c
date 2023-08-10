#include "stdin_reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rot13.h"


// Free allocated memory
void cleanup(char **input, int num_lines) {
    for (int i = 0; i < num_lines; ++i) {
        free(input[i]);
    }
    free(input);
}

void decode_rot13_from_stdin() {
    int num_lines;
    char num_lines_c[100];
    char **input;

    printf("\n\nEnter the number of lines you want to enter: ");

    if (fgets(num_lines_c, sizeof(num_lines_c), stdin) != NULL) {
        long int result = strtol(num_lines_c, NULL, 10);
        if (result <= 0 || result > MAX_LINES) {
            printf("Invalid number of lines.\n");
            return;
        }
        num_lines = (int)result;

    } else {
        printf("Error occurred while reading input.\n");
        return;
    }

    input = (char **)malloc(num_lines * sizeof(char *));
    if (input == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter text to decode using ROT13:\n");
    for (int i = 0; i < num_lines; i++) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), stdin) != NULL) {
            // Remove the trailing newline character, if present
            line[strcspn(line, "\n")] = '\0';
            input[i] = (char *)malloc((strlen(line) + 1) * sizeof(char));
            if (input[i] != NULL) {
                strcpy(input[i], line);
            } else {
                printf("Memory allocation error.\n");
                cleanup(input, i);
                return;
            }
        } else {
            printf("Error occurred while reading input.\n");
            cleanup(input, i);
            return;
        }
    }

    printf("\n\nEntered text after ROT13 encoding:\n");
    for (int i = 0; i < num_lines; i++) {
        char *encoded_line = decode_rot13(input[i]);
        if (encoded_line != NULL) {
            printf("%s\n", encoded_line);
            free(encoded_line);
            free(input[i]);
        } else {
            printf("Error occurred during ROT13 encoding.\n");
            break;
        }
    }
    free(input);
}

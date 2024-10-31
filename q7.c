#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateArray(char arr[6][5], int idDigits[4]) {
    int i = 0, j = 0;
    // Filling with random letter
    for (i = 0; i < 6 - 1; i++) {
        for (j = 0; j < 5; j++) {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
    // Placing my student ID's last four digits in the last row
    for (j = 0; j < 4; j++) {
        arr[6 - 1][j] = '0' + idDigits[j];
    }
    arr[6 - 1][4]='A';
}

// Displaying the 2D array
void printArray(char arr[6][5]){
    int i = 0, j = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

// Comparing the string with the letter in the grid
int searchString(char arr[6][5], char *str) {
    int strLen = strlen(str);
    int i = 0, j = 0, k = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j <= 5 - strLen; j++) {
            int found = 1;
            for (k = 0; k < strLen; k++) {
                if (arr[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1; 
        }
    }
    return 0; 
}

int main() {
    char arr[6][5];
    int idDigits[4] = {0, 5, 3, 5}; 
    int score = 0;
    char input[20];

    srand(time(0));

    while (1) {
        generateArray(arr, idDigits);
        printArray(arr);

        printf("Enter search string (or 'END' to stop): ");
        scanf("%s", input);

        // Convert input to uppercase
        int i = 0;
        while (input[i]) {
            input[i] = toupper(input[i]);
            i++;
        }

        if (strcmp(input, "END") == 0) {
            break;
        }

        if (searchString(arr, input)) {
            score++;
            printf("%s is present. Score: %d\n", input, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", input, score);
        }
    }

    printf("Final Score: %d\n", score);
    return 0;
}


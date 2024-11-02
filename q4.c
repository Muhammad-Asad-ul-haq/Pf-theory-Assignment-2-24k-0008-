#include <stdio.h>
#include <string.h>

// Function to sort the letters in a word in ascending order
void sortLetters(char word[]) {
    int length = strlen(word);  
    char temp;
    int i, j;
    for (i = 0; i < length - 1; i++) {  
        for (j = 0; j < length - i - 1; j++) {  
            if (word[j] > word[j + 1]) {  
                temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);  
    
    char str_arr[n][20];  
    char sort_arr[n][20];  
    int used[n];  
    
    memset(used, 0, sizeof(used));  // Initialize the 'used' array to 0 for all elements
    
    printf("Enter the words:\n");
    int i, j;
    for (i = 0; i < n; i++) {
        scanf("%s", str_arr[i]);  
        strcpy(sort_arr[i], str_arr[i]); 
        sortLetters(sort_arr[i]);  // Sort the letters of the copied word
    }
    
    printf("\nGrouped anagrams:\n");
    for (i = 0; i < n; i++) {
        if (used[i]) continue;  // Skip if the word has already been grouped
        
        printf("[ %s", str_arr[i]);  // Print the first word in the current group
        used[i] = 1;  // Mark the word as used
        
        for (j = i + 1; j < n; j++) {
            // Check if the word is unused and is an anagram of the current word
            if (!used[j] && strcmp(sort_arr[i], sort_arr[j]) == 0) {
                printf(" %s", str_arr[j]);  // Print the anagram word in the same group
                used[j] = 1;  // Mark this word as used
            }
        }
        printf(" ]\n");  // Close the current group
    }

    return 0;
}


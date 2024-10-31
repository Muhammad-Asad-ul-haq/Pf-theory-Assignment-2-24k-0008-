#include <stdio.h>
#include <string.h>


void compress(const char *original, char *compressed) {
    int j = 0; 
    int i;
	for (i = 0; original[i] != '\0'; i++) {
        if (original[i] != original[i - 1]) {
            compressed[j++] = original[i];
        }
    }
    compressed[j] = '\0';
}

int main() {
    char word[10], compressed[10];
    
    
    printf("Enter a word: ");
    scanf("%s",word);

   
    compress(word,compressed);
    
    
    int original_length = strlen(word);
    int compressed_length = strlen(compressed);
    int removed_letters = original_length - compressed_length;

    
    printf("Original word: %s\n", word);
    printf("Compressed word: %s\n", compressed);
    printf("Total characters removed: %d\n", removed_letters);

    return 0;
}

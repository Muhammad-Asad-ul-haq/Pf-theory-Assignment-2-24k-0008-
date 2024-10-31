#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i, x;
    int count[26] = {0};
    char alphabet[26];
    char strings[100];
    int c = 0;

    printf("Enter slogan: ");
    fgets(strings, sizeof(strings), stdin);
    strings[strcspn(strings, "\n")] = 0;

    int length = strlen(strings);

    for (i = 0; i < length; i++) {
        char ch = tolower(strings[i]);
        if (ch >= 'a' && ch <= 'z') {
            int found = 0;
            for (x = 0; x < c; x++) {
                if (alphabet[x] == ch) {
                    count[x]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                alphabet[c] = ch;
                count[c] = 1;
                c++;
            }
        }
    }

    for (i = 0; i < c; i++) {
        printf("%c: %d\n", alphabet[i], count[i]);
    }

    return 0;
}

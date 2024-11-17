#include <stdio.h>

void TopSection(int n) {
    // Print the top section of the pattern
    int row, col, gap;
    for (row = 0; row < n; row++) {
        if (row < n - 1) {
            for (col = 0; col < 2 * (n - 1) - row; col++) {
                printf(" ");
            }
            printf("*");
            if (row > 0) {
                gap = (2 * row) - 1;
                for (col = 0; col < gap; col++) {
                    printf(" ");
                }
                printf("*");
            }
        } else {
            for (col = 0; col < n; col++) {
                printf("*");
            }
            gap = (2 * row) - 1;
            for (col = 0; col < gap; col++) {
                printf(" ");
            }
            for (col = 0; col < n; col++) {
                printf("*");
            }
        }
        printf("\n");
    }
}

void MiddleSection(int n) {
    // Print the middle part of the pattern
    int row, col, spaces, midGap;
    midGap = 4 * n - 7;
    for (row = 0; row < n - 1; row++) {
        for (spaces = 0; spaces < row + 1; spaces++) {
            printf(" ");
        }
        printf("*");

        for (col = 0; col < midGap; col++) {
            printf(" ");
        }
        midGap -= 2;
        printf("*\n");
    }
}

void BottomSection(int n) {
    // Print the bottom part of the pattern
    int totalRows = 2 * n - 2;
    int row, col, outerSpaces, innerGap = 1;

    for (row = n - 1; row < totalRows; row++) {
        outerSpaces = 2 * n - 3 - row;
        for (col = 0; col < outerSpaces; col++) {
            printf(" ");
        }

        printf("*");
        for (col = 0; col < outerSpaces; col++) {
            printf(" ");
        }
        if (row < totalRows - 1) {
            printf("*");
        }

        for (col = 0; col < innerGap; col++) {
            printf(" ");
        }
        innerGap += 4;

        if (row < totalRows - 1) {
            printf("*");
        }
        for (col = 0; col < outerSpaces; col++) {
            printf(" ");
        }
        printf("*\n");
    }
}

int main() {
    int n;
    printf("Enter n (an odd number): ");
    scanf("%d", &n);

    TopSection(n);      // Top section
    MiddleSection(n);   // Middle section
    BottomSection(n);   // Bottom section

    return 0;
}

#include <stdio.h>

// Function to print the horizontal histogram
void horizontal_histogram(int array[], int No_of_values) {
    printf("\nHorizontal Histogram:\n");
    int i, j;
    for (i = 0; i < No_of_values; i++) {
        printf("Value %d: ", i + 1);
        for (j = 0; j < array[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the vertical histogram
void vertical_histogram(int array[], int No_of_values) {
    printf("\nVertical Histogram:\n");
    int maximum_height = 0;

    // Finding the maximum value to determine the height of the histogram
    int i;
    for (i = 0; i < No_of_values; i++) {
        if (array[i] > maximum_height) {
            maximum_height = array[i];
        }
    }

    // Print the histogram from top to bottom
    int height;
    for (height = maximum_height; height > 0; height--) {
        for (i = 0; i < No_of_values; i++) {
            if (array[i] >= height) {
                printf("* ");
            } else {
                printf("  "); // Space for empty positions
            }
        }
        printf("\n");
    }

    // Printing the values at the bottom
    for (i = 0; i < No_of_values; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[100]; 
    int No_of_values; 

    // Input handling
    printf("Enter the number of values: ");
    scanf("%d", &No_of_values);

    // take the values from the user
    printf("Enter the values:\n");
    int i;
    for (i = 0; i < No_of_values; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &array[i]); 
    }

    // Print the horizontal histogram
    horizontal_histogram(array, No_of_values);
    
    // Print the vertical histogram
    vertical_histogram(array, No_of_values);

    return 0;
}

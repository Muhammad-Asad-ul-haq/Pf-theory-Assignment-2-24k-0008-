#include <stdio.h>


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


void vertical_histogram(int array[], int No_of_values) {
    printf("\nVertical Histogram:\n");
    int maximum_height = 0;

    
    int i;
    for (i = 0; i < No_of_values; i++) {
        if (array[i] > maximum_height) {
            maximum_height = array[i];
        }
    }

    
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

   
    for (i = 0; i < No_of_values; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[100]; 
    int No_of_values; 

    
    printf("Enter the number of values: ");
    scanf("%d", &No_of_values);

    // take the values from the user
    printf("Enter the values:\n");
    int i;
    for (i = 0; i < No_of_values; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &array[i]); 
    }

    
    horizontal_histogram(array, No_of_values);
    
    
    vertical_histogram(array, No_of_values);

    return 0;
}

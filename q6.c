#include <stdio.h>

// Function to determine the number of matchsticks A should pick
int matchsticks(int n) {
    if (n % 5 == 0) {
        return -1; 
    } else {
        return n % 5; 
    }
}

int main() {
    int n,result;

    // taking the no of matchstickes on the table
    printf("Enter the number of matchsticks on the table: ");
    scanf("%d", &n);

    // Determining the result
    result= matchsticks(n);

    // Displaying the result
    if (result == -1) {
        printf("it is impossible for A to win the game");
    } else {
        printf("Player A should pick %d matchsticks on the first turn to guarantee a win\n", result);
    }

    return 0;
}

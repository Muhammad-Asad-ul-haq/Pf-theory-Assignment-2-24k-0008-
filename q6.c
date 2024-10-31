#include <stdio.h>


int matchsticks(int n) {
    if (n % 5 == 0) {
        return -1; 
    } else {
        return n % 5; 
    }
}

int main() {
    int n,result;

    
    printf("Enter the number of matchsticks on the table: ");
    scanf("%d", &n);

    
    result= matchsticks(n);

   
    if (result == -1) {
        printf("it is impossible for A to win the game");
    } else {
        printf("Player A should pick %d matchsticks on the first turn to guarantee a win\n", result);
    }

    return 0;
}

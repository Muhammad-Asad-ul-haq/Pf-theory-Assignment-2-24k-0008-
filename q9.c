#include <stdio.h>

void displayingGrid(char grid[5][5]);
void moves(char grid[5][5], char direction, int *playersRow, int *playerColumn, int *score, int Items);

int main() {
    // The main grid
	char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playersRow = 4, playerCol = 4;  // Initial position of player
    int score = 0;

    
    int Items = 0;
    int i,j;
	for (i=0;i<5;i++) {
        for (j= 0;j<5;j++) {
            if (grid[i][j] == 'I') {
                Items=Items+1;
            }
        }
    }

    char move;

    printf("Welcome to the Grid-based adventure Game!\n");
    printf("Enter \n W = Up \n S = Down \n A = Left \n D = Right \n E = Quit\n\n");

    while (1) {
        displayingGrid(grid);
        printf("Score: %d\n", score);
        printf("Enter your move: ");
        scanf(" %c", &move);

        
        if (move == 'E' || move == 'e') {
            printf("Thanks for playing! \nFinal score: %d\n", score);
            break;
        }

        
        moves(grid, move, &playersRow, &playerCol, &score, Items);

        
        if (score == Items) {
            printf("\n");
            printf("\n");
			printf("Congratulations!\nYou have collected all items present in the game!\nFinal score: %d\n", score);
            break;
        }
    }

    return 0;
}


void displayingGrid(char grid[5][5]) {
    int i,j;
	for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void moves(char grid[5][5], char direction, int *playersRow, int *playerColumn, int *score, int Items) {
    int newRow = *playersRow;
    int newColumn = *playerColumn;
    
	switch (direction) {
    case 'W':
    case 'w':
        newRow--;  
        break;
        
    case 'S':
    case 's':
        newRow++;  
        break;
        
    case 'A':
    case 'a':
        newColumn--;  
        break;
        
    case 'D':
    case 'd':
        newColumn++;  
        break;
        
    default:
        printf("Invalid input! Use W, A, S, D, or E to quit.\n");
        return;
}


  
    if (newRow < 0 || newRow >= 5 || newColumn < 0 || newColumn >= 5) {
        printf("\n");
        printf("\n");
		printf("You hit the boundary!\nTry a different move.\n");
        printf("\n");
        printf("\n");
		return;
    }

    
    if (grid[newRow][newColumn] == 'X') {
        printf("\n");
        printf("\n");
		printf("You hit an obstacle!\nTry a different move.\n");
        printf("\n");
        printf("\n");
		return;
    }

   
    if (grid[newRow][newColumn] == 'I') {
        (*score)++;
        printf("Item collected! Score: %d\n",*score);
    }

    
    grid[*playersRow][*playerColumn] = ' ';

    
    grid[newRow][newColumn]='P';
    *playersRow=newRow;
    *playerColumn=newColumn;
}

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

        // Check for quit condition
        if (move == 'E' || move == 'e') {
            printf("Thanks for playing! \nFinal score: %d\n", score);
            break;
        }

        // Move the player
        moves(grid, move, &playersRow, &playerCol, &score, Items);

        // Checking if the player has collected all items present in the grid
        if (score == Items) {
            printf("\n");
            printf("\n");
			printf("Congratulations!\nYou have collected all items present in the game!\nFinal score: %d\n", score);
            break;
        }
    }

    return 0;
}

// Function to display the current grid
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

// Function to move the player
void moves(char grid[5][5], char direction, int *playersRow, int *playerColumn, int *score, int Items) {
    int newRow = *playersRow;
    int newColumn = *playerColumn;
    // Using switch case to determine the direction the player want to move
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


    // Checking if the new position is within the grid
    if (newRow < 0 || newRow >= 5 || newColumn < 0 || newColumn >= 5) {
        printf("\n");
        printf("\n");
		printf("You hit the boundary!\nTry a different move.\n");
        printf("\n");
        printf("\n");
		return;
    }

    // Check if the new position is an obstacle
    if (grid[newRow][newColumn] == 'X') {
        printf("\n");
        printf("\n");
		printf("You hit an obstacle!\nTry a different move.\n");
        printf("\n");
        printf("\n");
		return;
    }

    // Check if the new position has an item
    if (grid[newRow][newColumn] == 'I') {
        (*score)++;
        printf("Item collected! Score: %d\n",*score);
    }

    // Updating the grid
    grid[*playersRow][*playerColumn] = ' ';

    // Moving the player to the new position
    grid[newRow][newColumn]='P';
    *playersRow=newRow;
    *playerColumn=newColumn;
}

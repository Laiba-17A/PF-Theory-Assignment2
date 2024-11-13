#include <stdio.h>


char grid[5][5] = {
    {' ', ' ', 'I', 'X', ' '},
    {' ', 'X', ' ', ' ', ' '},
    {'I', ' ', 'X', 'X', ' '},
    {' ', ' ', ' ', 'I', 'X'},
    {' ', 'X', ' ', ' ', 'P'}
};

int playerRow = 4, playerCol = 4;

void displayGrid() {
    printf("Current Grid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(int newRow, int newCol) {
    if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5) {
        return 0;
    }
    
    if (grid[newRow][newCol] == 'X') {
        return 0;
    }
    
    return 1;
}

void movePlayer(char direction) {
    int newRow = playerRow, newCol = playerCol;
    
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
            newCol--;
            break;
        case 'D':
        case 'd':
            newCol++;
            break;
        default:
            printf("Invalid input. Please try again.\n");
            return;
    }
    
    if (!isValidMove(newRow, newCol)) {
        printf("Cannot move in that direction. There's an obstacle.\n");
        return;
    }
    
    grid[playerRow][playerCol] = ' ';
    playerRow = newRow;
    playerCol = newCol;
    
    if (grid[playerRow][playerCol] == 'I') {
        printf("Collected an item!\n");
        grid[playerRow][playerCol] = ' ';
    }
    
    grid[playerRow][playerCol] = 'P';
}

int main() {
    char input;
    
    while (1) {
        displayGrid();
        printf("Enter move (W/A/S/D) or Q to quit: ");
        
        scanf(" %c", &input);
        
        if (input == 'Q' || input == 'q') {
            printf("Goodbye!\n");
            break;
        }
        
        movePlayer(input);
    }
    
    return 0;
}
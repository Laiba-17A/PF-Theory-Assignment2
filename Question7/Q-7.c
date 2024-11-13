#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Includes string functions for easier string handling

#define GRID_ROWS 6
#define GRID_COLS 5

// Fills the grid with random letters from A to Z
void RandomLetters(char grid[GRID_ROWS][GRID_COLS]) {
    const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

    // Fill each cell in the grid except for the last row
    for (int row = 0; row < GRID_ROWS - 1; row++) {
        for (int col = 0; col < GRID_COLS; col++) {
            int randomIndex = rand() % 26; // Pick a random letter
            grid[row][col] = letters[randomIndex]; 
        }
    }

    // Fill the last row with specific numbers
    grid[5][0] = '1';
    grid[5][1] = '2';
    grid[5][2] = '3';
    grid[5][3] = '4';
    grid[5][4] = '0';
}

// Shows the grid to the player
void displayGrid(char grid[GRID_ROWS][GRID_COLS]) {
    printf("\nCurrent Grid:\n");
    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLS; col++) {
            printf("%c\t", grid[row][col]); // Print each cell with a tab space
        }
        printf("\n"); 
    }
    printf("\n");
}

// Checks if the word is found horizontally in the grid
int searchHorizontal(char grid[GRID_ROWS][GRID_COLS], const char word[]) {
    int wordLength = strlen(word); 

    // Go through each row of the grid
    for (int row = 0; row < GRID_ROWS - 1; row++) {
        for (int col = 0; col <= GRID_COLS - wordLength; col++) {
            int match = 1; // A flag to keep track if the word matches

            // Check each letter in the word
            for (int k = 0; k < wordLength; k++) {
                if (grid[row][col + k] != word[k]) { 
                    match = 0; // Set flag to 0, meaning word doesn't match here
                    break;
                }
            }

            if (match) return 1; // Word was found 
        }
    }
    return 0; 
}

// Checks if the word is found vertically in the grid
int searchVertical(char grid[GRID_ROWS][GRID_COLS], const char word[]) {
    int wordLength = strlen(word); // Get the length of the word

    // Go through each column of the grid
    for (int col = 0; col < GRID_COLS; col++) {
        for (int row = 0; row <= GRID_ROWS - 1 - wordLength; row++) {
            int match = 1; 
            // Check each letter in the word
            for (int k = 0; k < wordLength; k++) {
                if (grid[row + k][col] != word[k]) { 
                    match = 0; // Set flag to 0, meaning word doesn't match here
                    break; 
                }
            }

            if (match) return 1; // Word was found 
        }
    }
    return 0; 
}

int main() {
    char grid[GRID_ROWS][GRID_COLS]; // 2D array for the grid
    char word[50]; // Array to store the word to search for
    int score = 0; // Keeps track of the player's score

    srand((unsigned) time(0)); // Initialize random number generator

    while (1) {
        // Fill the grid with random letters and display it
        RandomLetters(grid);
        displayGrid(grid);

        
        while (1) {
            printf("Enter a word to search (type END to refresh grid): ");
            scanf("%s", word); 
            
            if (strcmp(word, "END") == 0) { 
                printf("\nRefreshing grid...\n");
                break;//if user enter end break
            }

            // Check if the word is found in the grid (horizontal or vertical)
            if (searchHorizontal(grid, word) || searchVertical(grid, word)) {
                score++; 
                printf("%s found! Current Score: %d\n", word, score);
            } else {
                score--; //dec score if wrong
                printf("%s not found! Current Score: %d\n", word, score);
            }
        }
    }

    return 0;
}

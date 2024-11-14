#include <stdio.h>

// Function to determine the number of matchsticks A should pick
int game(int n) {
    if (n % 5 == 0) {
        return -1; 
    } else {
        return n % 5; 
    }
}

int main() {
    int n,game;

    // taking input(no.of matchsticks on table
    printf("Enter the number of matchsticks: ");
    scanf("%d", &n);

    // result
    output= game(n);

    if (output== -1) {
        printf("it is impossible for A to win the game");
    } else {
        printf("Player A should pick %d matchsticks on the first turn to guarantee a win\n", result);
    }

    return 0;
}

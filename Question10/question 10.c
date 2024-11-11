#include <stdio.h>
/* 
 * This program prints a star pattern in the shape of a star with a given size N.
 * The size N must be an odd number for the pattern to be symmetrical.
 * The pattern is formed by printing '*' at calculated positions.
 */
 //FUNCTION TO PRINT THE UPPER PART OF START
void pattern(int n)
{
	int j,i,space;
	
	for(i=0;i<n;i++){
	    if(i < n-1){
            // Print initial spaces
            for (j = 0; j < 2 * (n-1) - i; j++) {
                printf(" ");
            }
            // Print first asterisk
            printf("*");
            // Print middle spaces
            if (i != 0) {
                space =( 2 * i )- 1;
                for (j = 0; j < space; j++) {
                    printf(" ");
                }
                // Print second asterisk
                printf("*");
            }
        }
        
        else {
        	for (int k = 0; k < n; k++) {
                printf("*");
            }
            // Print spaces in between
            space = (2 * i) - 1;
            for (int j = 0; j < space; j++) {
                printf(" ");
            }
            // Print ending n *
            for (int k = 0; k < n; k++) {
                printf("*");
            }
		}
		printf("\n");
	}
}

//FUNCTION TO PRINT INWARD DAIGNOLS
void Upper(int n) {
    int mid = 4 * n - 7;//space in between
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
    	//loop to print spaces
        for (j = 0; j < i + 1; j++) {
            printf(" ");
        }
        printf("*");

        for (k = 0; k < mid; k++) {
            printf(" ");
        }
        mid -= 2;//middle spaces reduced by 2 to have a inward effect

        printf("*\n");
    }
}
//FUNCTION TO PRINT LOWER PART
void Lower(int n) {
    int rows = 2 * n - 2;
    int temp= 1;//extra spaces between stars
    int i, j, k;
    int spaces;//initial spaces on each line

    for (i = n - 1; i < rows; i++) {
        spaces = 2 * n - 3 - i;

        for (j = 0; j < spaces; j++) {
            printf(" ");
        }

        printf("*");

        for (k = 0; k < spaces; k++) {
            printf(" ");
        }
        if (i == rows - 1) {
            printf(" ");
        } else {
            printf("*");
        }
        // Print extra space between two stars in lower half, incrementing by 4 each line
        for (k = 0; k < temp; k++) {
            printf(" ");
        }
        temp += 4;
        if (i == rows - 1) {
            printf(" ");
        } else {
            printf("*");
        }
        for (int k = 0; k < spaces; k++) {
            printf(" ");
        }
        //printing the last star
        printf("*\n");
    }
}


int main(){
	int n;
	printf("enter n(an odd number): ");
	scanf("%d",&n);
	pattern(n);
	Upper(n);
	Lower(n);
	return 0;
}
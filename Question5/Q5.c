#include <stdio.h>

// Function to print the horizontal histogram
void horizontal_histogram(int arr[], int n) {
    printf("\nHorizontal Histogram:\n");
    int i, j;
    for (i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        for (j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print the vertical histogram
void vertical_histogram(int arr[], int n) {
    printf("\nVertical Histogram:\n");
    int maxh = 0;

    // Finding the maximum value in the array
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] > maxh) {
            maxh = arr[i];
        }
    }
    // Print the histogram from top to bottom
    int j,k;
    for (j=maxh; j > 0; j--) {
	//each each element of array is checked with max h
        for (k = 0; k < n; k++) {
            if (arr[k] >= j) {
                printf("* ");
            } else {
                printf("  "); 
            }
        }
        printf("\n");
    }

    // Printing the values at the bottom
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; 
    int n; 
    printf("Enter the number of values: ");
    scanf("%d", &n);

    // taking values from the user and storing in an array
    printf("Enter the values:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }

    // Print the horizontal histogram
    horizontal_histogram(arr,n);
    
    // Print the vertical histogram
    vertical_histogram(arr,n);

    return 0;
}

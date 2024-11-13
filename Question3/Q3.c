#include <stdio.h>
#include <string.h>

// Function to compress a word
//taking input by ref
void compress(const char *original, char *compressed) {
    int j = 0; 
    int i;
	for (i = 0; original[i] != '\0'; i++) {
        if (original[i] != original[i - 1]) {
            compressed[j++] = original[i];
        }
    }
    compressed[j] = '\0';
}

int main() {
	int n;
    printf("enter number of words in an array\n");
	scanf("%d",&n);
    char str[n][20];
	char compressed[n][20];
	int removed_L[n];
    for(int i=0;i<n;i++){
	    // Taking input of a word
        printf("Enter a word: ");
        scanf("%s",&str[i]);

        // Compressing the word
        compress(str[i],compressed[i]);
    
        // Calculating the removed letter
        int initial_L = strlen(str[i]);
        int compressed_L = strlen(compressed[i]);
        removed_L[i] = initial_L - compressed_L;
    }
    // Displaying the results represent string and the number of letter removed from each word
    printf("[");
    for(int j=0;j<n;j++){
    	
        printf(" %s %d ,",compressed[j],removed_L[j]);
    }
    printf("]");

    return 0;
}

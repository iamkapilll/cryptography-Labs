#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void rowTransposeEncrypt(char *plaintext, char *ciphertext, int key) {
    int len = strlen(plaintext);
    int rows = (len + key - 1) / key;  // Calculating the number of rows
    
    // Fill the grid row by row
    char grid[rows][key];
    
    int k = 0;  // Index for plaintext
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (k < len) {
                grid[i][j] = plaintext[k];
                k++;
            } else {
                grid[i][j] = 'X';  // Fill with 'X' if the grid cell is empty
            }
        }
    }

    // Read column by column to generate ciphertext
    k = 0;
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            ciphertext[k] = grid[i][j];
            k++;
        }
    }
    ciphertext[k] = '\0';  // Null-terminate the ciphertext
}

void rowTransposeDecrypt(char *ciphertext, char *plaintext, int key) {
    int len = strlen(ciphertext);
    int rows = (len + key - 1) / key;  // Calculate the number of rows
    
    char grid[rows][key];
    
    // Fill the grid column by column
    int k = 0;  // Index for ciphertext
    for (int j = 0; j < key; j++) {
        for (int i = 0; i < rows; i++) {
            if (k < len) {
                grid[i][j] = ciphertext[k];
                k++;
            }
        }
    }

    // Read the grid row by row to reconstruct plaintext
    k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key; j++) {
            if (grid[i][j] != 'X') {  // Skip the filler 'X'
                plaintext[k] = grid[i][j];
                k++;
            }
        }
    }
    plaintext[k] = '\0';  // Null-terminate the plaintext
}

int main() {
    char plaintext[MAX], ciphertext[MAX], decrypted[MAX];
    int key;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove the newline character
    
    printf("Enter the key (number of columns): ");
    scanf("%d", &key);
    
    // Encrypting the plaintext
    rowTransposeEncrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);
    
    // Decrypting the ciphertext
    rowTransposeDecrypt(ciphertext, decrypted, key);
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}

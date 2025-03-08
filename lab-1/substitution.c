#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char* text, int s) {
    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            text[i] = (text[i] + s - 'A') % 26 + 'A';
        } else if (islower(text[i])) {
            text[i] = (text[i] + s - 'a') % 26 + 'a';
        }
    }
}
void decrypt(char* text, int s) {
    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            text[i] = (text[i] - s - 'A' + 26) % 26 + 'A';
        } else if (islower(text[i])) {
            text[i] = (text[i] - s - 'a' + 26) % 26 + 'a';
        }
    }
}
int main() {
    char text[100];
    int s;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  
    printf("Enter shift: ");
    scanf("%d", &s);
    printf("Original Text: %s\n", text);
    encrypt(text, s);
    printf("Encrypted Text: %s\n", text);
    decrypt(text, s);
    printf("Decrypted Text: %s\n", text);
    return 0;
}

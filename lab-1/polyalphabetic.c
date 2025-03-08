#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char* text, char* keyword) {
    int textLen = strlen(text);
    int keywordLen = strlen(keyword);
    int keywordIndex = 0;

    for (int i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char shift = toupper(keyword[keywordIndex % keywordLen]) - 'A';
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + shift) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' + shift) % 26 + 'a';
            }
            keywordIndex++;
        }
    }
}

int main() {
    char text[100];
    char keyword[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    printf("Original Text: %s\n", text);
    vigenere_encrypt(text, keyword);
    printf("Encrypted Text: %s\n", text);

    return 0;
}

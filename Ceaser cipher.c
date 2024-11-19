#include <stdio.h>
#include <ctype.h>

void caesarCipher(char *text, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a'; 
            ch = (ch - base + k) % 26 + base;   
        }
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int k;

    printf("Enter a string to encrypt: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift value (1-25): ");
    scanf("%d", &k); 

    if (k < 1 || k > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25.\n");
        return 1;
    }

    caesarCipher(text, k);

    printf("Encrypted text: %s\n", text);

    return 0;
}

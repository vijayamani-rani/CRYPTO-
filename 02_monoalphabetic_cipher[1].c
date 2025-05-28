#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], key[100];
    
    printf("Enter plaintext (no spaces): ");
    scanf("%s", plaintext);  // Reads a single word
    
    printf("Enter key (no spaces): ");
    scanf("%s", key);        // Reads a single word

    // Convert key to uppercase
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }

    int len = strlen(plaintext);
    int keyLen = strlen(key);

    printf("Encrypted: ");
    for (int i = 0, j = 0; i < len; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            int shift = key[j % keyLen] - 'A';
            if (isupper(ch))
                printf("%c", 'A' + (ch - 'A' + shift) % 26);
            else
                printf("%c", 'a' + (ch - 'a' + shift) % 26);
            j++;
        } else {
            printf("%c", ch);
        }
    }

    printf("\n");
    return 0;
}

#include <stdio.h>
#include <ctype.h>

void caesarCipher(char *text, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) text[i] = (text[i] - 'A' + k) % 26 + 'A';
        else if (islower(text[i])) text[i] = (text[i] - 'a' + k) % 26 + 'a';
    }
}

int main() {
    char text[1000];
    int k;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift (1-25): ");
    scanf("%d", &k);
    caesarCipher(text, k);
    printf("Encrypted: %s\n", text);
    return 0;
}

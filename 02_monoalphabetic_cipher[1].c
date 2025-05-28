#include <stdio.h>
#include <string.h>
#include <ctype.h>

char map[26];

void generateMap(char *key) {
    int used[26] = {0}, idx = 0;
    for (int i = 0; key[i]; i++) {
        char ch = toupper(key[i]);
        if (!used[ch - 'A']) {
            map[idx++] = ch;
            used[ch - 'A'] = 1;
        }
    }
    for (int i = 0; i < 26; i++)
        if (!used[i])
            map[idx++] = 'A' + i;
}

void encrypt(char *text) {
    for (int i = 0; text[i]; i++) {
        if (isupper(text[i]))
            text[i] = map[text[i] - 'A'];
        else if (islower(text[i]))
            text[i] = tolower(map[text[i] - 'a']);
    }
}

int main() {
    char key[100], text[1000];
    printf("Enter keyword: ");
    scanf("%s", key);
    printf("Enter plaintext: ");
    getchar(); fgets(text, sizeof(text), stdin);
    generateMap(key);
    encrypt(text);
    printf("Encrypted text: %s", text);
    return 0;
}

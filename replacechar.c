#include <stdio.h>
#include <string.h>

void replaceChars(char *str, char oldChar, char newChar) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int main() {
    char inputString[1000];
    char oldChar, newChar;

    scanf("%s", inputString);
    scanf(" %c", &oldChar); 
    scanf(" %c", &newChar);

    replaceChars(inputString, oldChar, newChar);

    printf("%s\n", inputString);

    return 0;
}

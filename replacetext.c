#include <stdio.h>
#include <string.h>

void replaceString(char *text, const char *oldStr, const char *newStr) {
    char *pos, temp[1000];
    int index = 0;
    int oldStrLen = strlen(oldStr);
    
    while ((pos = strstr(text, oldStr)) != NULL) {
        int diff = pos - text;
        strncpy(temp, text, diff);
        temp[diff] = '\0';
        strcat(temp, newStr);
        index = diff + strlen(newStr);
        strcat(temp, pos + oldStrLen);
        strcpy(text, temp);
    }
}

int main() {
    char P1[1000], P2[1000], T[1000];
    fgets(P1, sizeof(P1), stdin);
    P1[strcspn(P1, "\n")] = '\0';
    fgets(P2, sizeof(P2), stdin);
    P2[strcspn(P2, "\n")] = '\0';
    fgets(T, sizeof(T), stdin);
    T[strcspn(T, "\n")] = '\0';
    replaceString(T, P1, P2);
    puts(T);
    return 0;
}
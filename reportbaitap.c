#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100000

struct Entry {
    char date[11];
    int count;
};

int compareDates(const void *a, const void *b) {
    return strcmp(((struct Entry *)a)->date, ((struct Entry *)b)->date);
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int totalEntries = 0;

    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '*') {
            break;
        }

        char date[11];
        sscanf(line, "%s", date);

        int found = 0;
        for (int i = 0; i < totalEntries; i++) {
            if (strcmp(entries[i].date, date) == 0) {
                entries[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(entries[totalEntries].date, date);
            entries[totalEntries].count = 1;
            totalEntries++;
        }
    }

    qsort(entries, totalEntries, sizeof(struct Entry), compareDates);

    for (int i = 0; i < totalEntries; i++) {
        printf("%s %d\n", entries[i].date, entries[i].count);
    }

    return 0;
}

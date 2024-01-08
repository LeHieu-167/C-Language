#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxn = 100;

typedef struct sv{
    char nameElement[3][20];
    char name[100];
    char birth[100];
} SV;

SV sv[20], tmp[20];

void loadFile(){
    FILE *f = fopen("profile-n.txt", "r");
    if(f == NULL) {
        printf("Cannot open file");
        return;
    }
    char tmp[100];
    int k = 0;
    while(fgets(tmp, sizeof(tmp), f)){
        if(strcmp(tmp, "#") == 0) break;
        tmp[strlen(tmp) - 1] = '\0';
        if(k % 2 == 0){
            strcpy(sv[k/2].name, tmp);
            char *token = strtok(tmp, " ");
            int i = 0;
            while(token != NULL){
                strcpy(sv[k/2].nameElement[i++], token);
                token = strtok(NULL, " ");
            }
        }
        else strcpy(sv[k/2].birth, tmp);
        k++;
    }
    fclose(f);
}

void printOut(){
    for(int i = 0; i < 7; i++){
        printf("%s %s\n", sv[i].name, sv[i].birth);
    }
}

void sort(int l, int m, int r){
    int i = l, j = m + 1;
    for(int k = l; k <= r; k++){
        if(i > m)
            tmp[k] = sv[j++];
        else if(j > r)
            tmp[k] = sv[i++];
        else {
            if(sv[i].nameElement[2][0] < sv[j].nameElement[2][0])
                tmp[k] = sv[i++];
            else
                tmp[k] = sv[j++];
    }
    for(int k = l; k <= r; k++)
        tmp[k] = sv[k];
}
}
void merge(int l, int r){
    if(l >= r) return;
    int m = l + r >> 1;
    merge(l, m);
    merge(m + 1, r);
    sort(l, m, r);
}
void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(sv[left].nameElement[2], sv[largest].nameElement[2]) > 0)
        largest = left;

    if (right < n && strcmp(sv[right].nameElement[2], sv[largest].nameElement[2]) > 0)
        largest = right;

    if (largest != i) {
        SV temp = sv[i];
        sv[i] = sv[largest];
        sv[largest] = temp;

        heapify(n, largest);
    }
}

void heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        SV temp = sv[0];
        sv[0] = sv[i];
        sv[i] = temp;

        heapify(i, 0);
    }
}

int partition(int low, int high) {
    SV pivot = sv[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(sv[j].nameElement[2], pivot.nameElement[2]) <= 0) {
            i++;

            SV temp = sv[i];
            sv[i] = sv[j];
            sv[j] = temp;
        }
    }

    SV temp = sv[i + 1];
    sv[i + 1] = sv[high];
    sv[high] = temp;

    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
int main(){
    loadFile();
    int lc;
    scanf("%d",&lc);
    if(lc == 1)
    {
        merge(0,6);
        printOut();
    }
    else if(lc == 2)
    {
         heapSort(7);
         printOut();
    }
    else if(lc == 3)
    {
         heapSort(7);
         printOut();
    }
}


#include<stdio.h>
void print_combinations(int arr[], int n, int r) {
    int data[r];
    combination_util(arr, data, 0, n-1, 0, r);
}

void combination_util(int arr[], int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++) {
        data[index] = arr[i];
        combination_util(arr, data, i+1, end, index+1, r);
    }
}

int main() {
    int arr[100];
    int n = 5;
    for(int i=0; i<n; i++) arr[i] = i+1;
    int r = 3;
    print_combinations(arr, n, r);
    return 0;
}

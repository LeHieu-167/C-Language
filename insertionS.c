#include<stdio.h>
#include<stdlib.h>
void insertionSort(int A[], int n){
    for(int k =2;k<=n;k++){
        int last = A[k];
        int j = k;
        while(j> 1 && A[j-1]>last){
            A[j]=A[j-1];
            j--;
        }
            A[j]=last;
        }
    }

int main(){
    int A[5],n;
    printf("nhap n:");scanf("%d",&n);
    for(int i =0;i<n;i++){
    scanf("%d",&A[i]);}
    insertionSort(A,n);
    for(int i = 0; i<n; i++){
        printf("%d\t", A[i]);
    }
    return 0;
}
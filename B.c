
#include<stdio.h>
#include<stdlib.h>
#define max 100
void bubbleSort(int A[], int N) {
// index tu 1 den N
int swapped;
do{
swapped = 0;
for(int i = 0; i < N - 1; i++){
if(A[i] > A[i+1]){
int tmp = A[i];
A[i] = A[i+1];
A[i+1] = tmp;
swapped = 1;
}
}
}while(swapped == 1);
}

int main(){
int A[max];
int n;
printf("Nhap n:");
scanf("%d",&n);
for(int k =0; k< n; k++){
    scanf("%d", &A[k]);
}
bubbleSort(A, n);
for(int k = 0; k<n; k++){
        printf("%d", A[k]);
}
printf("\n");
return 0;
}

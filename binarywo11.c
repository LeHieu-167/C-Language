#include<stdio.h>
#define Max 20
int n;
int x[Max];
int print(){
    for(int k = 0; k <n; k++)
    printf("%d",x[k]);
    printf("\n");
}
int try(int k){
    for(int v = 0; v <=1;v++){
        if(k==0||(k>=1 && x[k-1] + v <2)){
            x[k]=v;
            if(k==n-1) print();
            else try(k+1);
      }

    }
}
int main(){
    scanf("%d", &n);
    try(0);
    return 0;
}
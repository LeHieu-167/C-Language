#include<stdio.h>
int x[20];
int n, k;
int print(){
    for(k = 0; k < n; k++)
    printf("%d",x[k]);
    printf("\n");
}
int check(int v, int k){
    for(int i = 0; i <=k-1; i++){
        if(x[i] == v ) return 0;
        if(x[i]+i == v+k) return 0;
        if(x[i]-i == v-k) return 0;
    }
    return 1;
}
void try(int k){
    for(int v = 0; v < n; v++){
        if(check(v,k)){
            x[k] = v;
            if (k == n) print();
        else try(k+1);
        }
    }
}
void main(){
    try(1);
}
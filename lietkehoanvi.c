#include<stdio.h>
int n, x[100], m[100] ={0};
int i,k;
int print(){
    for(k = 0; k < n; k++)
    printf("%d",x[k]);
    printf("\n");
}
void try(int i){
    for(int v = 1;v <= n; v++){
        if(!m[v]){
            x[i] = v;
            m[v] = 1;
            if(i==n) print();
            else try(i+1);
            m[v] = 0;
        }
    }
}
void main(){
    scanf("%d", &n);
    //for(int v = 1; v<=n; v++)
   // m[v]=0;
    //x[0] = 0;
    try(1);
}
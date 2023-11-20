/*Bai 1*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
int friends[max][max];
int reach[max];
void Init(int N){
   for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        friends[i][j] = (i == j)?0 : 1;
    }
   }
}
void Blocked(int a, int b){
    friends[a][b] = friends[b][a] = 0;
}
/*void mark_reach(int N, int start){
    for(int i = 0;i < N; i++){
        reach(i)=0;
        reach(start)=1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(friends[i][j] && reach[i])
            reach[j] = 1;
        }
    }
}
void print_unreach(int N, int X){
    mark_reach(N,X);
    int count = 0;
    for(int i = 0; i<N; i++){
        if(!reach[i]){
            printf("%d",i);
            count++;
        }
    }
    if(!count) printf("-1");
    printf("\n");
}
void find_path(int N, int start, int current, int *visited){
    printf("%d",current);
    visited[current] = 1;
    for(int i = 0; i < N; i++){
        if(friends[current][i] && !visited(i)){
            find_path(N,start,i,visited);
        }
    }
}
void print_path(int N, int y){
    int visited[max] = {0};
    int count = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            find_path(N,y,i,visited);
            count++;
        }
    }
    if (count == 1) printf("-1\n");else printf("\n");
}
void print_all_paths(int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if (friends[i][j]){
                printf("%d %d\n",i,j);
                count++;
            }
        } 
    }
    printf("%d\n",count);
}*/
int main(){
    int N;
    printf("Nhap so luong ban trong nhom:");
    scanf("%d",&N);
    int a, b;
    while(scanf("%d %d", &a,&b)==2 && a!=b);
    Init(N);
    Blocked(a, b);
    return 0;
}
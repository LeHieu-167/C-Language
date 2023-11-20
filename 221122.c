#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
typedef struct Goat{
    char name[256];
    int ID;
    double w;
    double h;
    double L;
    int fID;
    int mID;
    struct Goat* leftMostChild;
    struct Goat* rightSibling;
}Goat;
Goat* root;

Goat* makeNode(char* name, int ID, double w, double h, double L, int fID, int mID){
    Goat* g = (Goat*)malloc(sizeof(Goat));
    strcpy(g->name,name);
    g->ID = ID;
    g->w = w;
    g->h = h;
    g->fID = fID;
    g->L = L;
    g->mID = mID;
    g->leftMostChild = NULL;
    g->rightSibling = NULL;
    return g;
}

void main(){
    int i,N;
    printf("khai bao N:");
    scanf("%d", &N);
    for(int i = 1; i < N+1; i++){
        char* name[256];
        int ID, fID, mID;
        double w, h, L;
        printf("Nhap thong tin cua con de thu %d:\n", i);
        printf("Name:"); scanf("%s",name);
        printf("ID:"); scanf("%d", &ID);
        printf("Weight:"); scanf("%f",&w);
        printf("Height:"); scanf("%f",&h);
        printf("Length:"); scanf("%f",&L);
        printf("fID:"); scanf("%d",&fID);
        printf("mID:"); scanf("%d",&mID);
        makeNode(name, ID, w, h, L, fID, mID);
    }
    return 0;
}
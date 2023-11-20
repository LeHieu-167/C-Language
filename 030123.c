#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256
#define max 10000
int n = 0;
typedef struct Node{
    char name[256];
    char email[256];
    struct Node* LeftChild;
    struct Node* RightChild;
}Node;
Node* root;
Node* makeNode(char* name, char* email){
    Node* p = (Node*)malloc(sizeof(Node));
    strcpy(p->name,name); strcpy(p->email,email);
    p->LeftChild = NULL; p->RightChild = NULL;
    return p;
}
Node* insert(Node* r, char* name, char* email){
    if(r == NULL) return makeNode(name,email);
        int c = strcmp(r->name,name);
    if(c == 0){
        printf("Student %s exists, do not insert\n",name); return r;
    }else if(c < 0){
        r->RightChild = insert(r->RightChild,name,email); return r;
    }else{
        r->LeftChild = insert(r->LeftChild,name,email); return r;
}
}
Node* find(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if(c == 0) return r;
    if(c < 0) return find(r->RightChild,name);
    return find(r->LeftChild,name);
}
Node* findMin(Node* r){
    if(r == NULL) return NULL;
    Node* lmin = findMin(r->LeftChild);
    if(lmin != NULL) return lmin;
    return r;
}
Node* RemoveStudent(Node* r, char* name){
    if(r == NULL) return NULL;
    int c = strcmp(r->name,name);
    if (c>0) r->LeftChild= RemoveStudent(r->LeftChild,name);
    else if (c<0) r->RightChild= RemoveStudent(r->RightChild,name);
    else{
        if (r-> LeftChild != NULL && r->RightChild != NULL){
            Node* tmp = findMin(r->RightChild);
            strcpy(r->name,tmp->name); strcpy(r->email,tmp->email);
            r->RightChild = RemoveStudent(r->RightChild, tmp->name);
        }else{
            Node* tmp = r;
            if(r->LeftChild == NULL) r=r->RightChild; else r=r->LeftChild;
            free(tmp);
        }
    }
    return r;

}
void freeTree(Node* r){
    if(r == NULL) return;
    freeTree(r->LeftChild);
    freeTree(r->RightChild);
    free(r);
}
void load(char* filename){
    FILE* f = fopen(filename,"r");
    if (f == NULL) printf("Load data -> file not found\n");
    root = NULL;
    while (!feof(f))
    {
        char name[MAX], email[MAX];
        fscanf(f, "%s%s", name, email);
        root = insert(root, name, email);
    }
    fclose(f);
}
void processLoad(){
    char filename[256];
    scanf("%s",filename);
    load(filename);
}
void InOrder(Node* r){
    if(r == NULL) return;
    InOrder(r->LeftChild);
    printf("%s %s\n",r->name,r->email);
    InOrder(r->RightChild);
}
void InOrderF(Node* r, FILE* f){
    if(r == NULL) return;
    InOrderF(r->LeftChild,f);
    fprintf(f,"%s %s\n",r->name,r->email);
    InOrderF(r->RightChild,f);
}
void printList(){
    InOrder(root);
    printf("\n");
}

void processStore(){
    char filename[MAX];
    scanf("%s", filename);
    FILE* f = fopen(filename,"w");
    InOrderF(root,f);
    fclose(f);
}
void processInsert(){
    char name[MAX], email[MAX];
    scanf("%s%s",name , email);
    root = insert(root,name, email);
}
void processRemove(){
    char name[MAX];
    scanf("%s", name);
    root =  RemoveStudent(root, name);
}

void main(){
    while(1){
    printf("Enter command: ");
    char cmd[256];
    scanf("%s",cmd);
    if(strcmp(cmd,"Quit")==0) break;
    else if(strcmp(cmd,"Load")==0) processLoad();
    else if(strcmp(cmd,"Print")==0) printList();
    /*else if(strcmp(cmd,"Find")==0) processFind();*/
    else if(strcmp(cmd,"Insert")==0) processInsert();
    else if(strcmp(cmd,"Remove")==0) processRemove();
    else if(strcmp(cmd,"Store")==0) processStore();
}
freeTree(root);
}



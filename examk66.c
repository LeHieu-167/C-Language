#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
    char code[7];
    int songuoi;
    int sophong;
    char ks[10];
    int dd,mm,yyy;
    int kid;
}Data;

Data *park;

typedef struct node{
    Data data;
    struct node *leftChild;
    struct node *rightChild;
}Node;

Node *root;

int n;
int position;
int sluong=0;
void Load(char *filename){
    FILE *f=fopen(filename,"r");
    
    fscanf(f,"%d",&n);
    while(!feof(f)){
        Data item;
        fscanf(f,"%s %d %d %s %d-%d-%d %d",item.code,&item.songuoi,&item.sophong,item.ks,&item.dd,&item.mm,&item.yyy,&item.kid);
        park[sluong++]=item;
        position=sluong;
        printf("insert %d\n",sluong);
    }
    fclose(f);
}

void printData(Data item){
    printf("%s %d %d %s %02d-%02d-%d %d\n",item.code,item.songuoi,item.sophong,item.ks,item.dd,item.mm,item.yyy,item.kid);
}
void task1(){
    char filename[]="booking_orders.txt";
    Load(filename);
    for(int i=0;i<sluong;i++){
        printData(park[i]);
    }
}

void back(){
    printf("Nhan enter\n");
    getchar();
}

void initBST(){
    root = NULL;
}

Node * makenode(Data item){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=item;
    p->leftChild=NULL;
    p->rightChild=NULL;
    return p;
}

Node* insert(Node* r,Data item){
    if(r==NULL){
        r=makenode(item);
        return r;
    }
    int c=strcmp(r->data.code,item.code);
    if(c<0){
        r->rightChild=insert(r->rightChild,item);
        return r;
    }
    if(c>0){
        r->leftChild=insert(r->leftChild,item);
        return r;
    }
}

Node *Find(Node* r,char *code){
    if(r==NULL) return NULL;
    int c=strcmp(r->data.code,code);
    if(c==0) return r;
    if(c<0) {
        return Find(r->rightChild,code);
    }
    if(c>0) {
        return Find(r->leftChild,code);
    }
}

Node *FindMin(Node* r){
    if(r==NULL) return NULL;
    Node * lMin=FindMin(r->leftChild);
    if(lMin != NULL) return lMin;
    return r;
}

Node *RemoveNode(Node *r,char *code){
    if(r==NULL) return NULL;
    int c=strcmp(r->data.code,code);
    if(c<0){
        r->rightChild=RemoveNode(r->rightChild,code);
    }
    else if(c>0){
        r->leftChild=RemoveNode(r->leftChild,code);
    }
    else{
        if(r->leftChild != NULL && r->rightChild != NULL){
            Node *tmp=FindMin(r->rightChild);
            r->data=tmp->data;
            r->rightChild=RemoveNode(r->rightChild,r->data.code);
        }else{
            Node* tmp=r;
            if(r->leftChild==NULL){ 
                r=r->rightChild;
            }
            else{ 
                r=r->leftChild;
            }
            free(tmp);
        }
    }
    return r;
}

void printTree(Node *r){
    if(r==NULL) return;
    printTree(r->leftChild);
    printData(r->data);
    printTree(r->rightChild);
}

void freeTree(Node *r){
    if(r==NULL) exit(0);
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r);
}

void task2(){
    int count=0;
    for(int i=0;i<sluong;i++){
        if(park[i].kid>0 && (park[i].songuoi-park[i].kid)<1){
            count++;

        }
    }
    printf("SO luong yeu cau khong hop le : %d\n",count);

}

int countNode=0;

Node* query(Node *r,int s,int f){
    for(int i=s;i<f;i++){
        r=insert(r,park[i]);
        countNode++;
        printf("%d\n",countNode);

    }
    return r;
}

void task3(){
    printTree(root);
    char maYC[7];
    printf("Nhap ma yeu cau : ");
    scanf("%s",maYC);
    Node* check=Find(root,maYC);
    if(check == NULL){
        printf("Not found !\n");
    }else{
        printData(check->data);
    }
}

void task4(){
    //cap nhat yeu cau
    char maYC[7];
    printf("Nhap ma yeu cau :");
    scanf("%s",maYC);
    int songuoi,kid,dd,mm,yyy;
    Node*check=Find(root,maYC);
    if(check==NULL){
        printf("Not found !\n");
    }else{
        printf("Ban muon thay doi gi :");
        
        scanf("%d %d-%d-%d %d",&songuoi,&dd,&mm,&yyy,&kid);
        if(kid>0 && (songuoi-kid)<1){
            printf("Invalid\n");
        }else{
            check->data.songuoi=songuoi;
            check->data.kid=kid;
            check->data.dd=dd;
            check->data.mm=mm;
            check->data.yyy=yyy;
        }
        if(check->data.songuoi==songuoi && check->data.kid==kid){
            printf("Update ! \n");
        }
        

    }
}

void task5(){
    //xoa yeu cau
    char maYC[7];
    printf("Nhap ma yc :\n");
    fflush(stdin);
    scanf("%s",maYC);
    Node*check=Find(root,maYC);
    if(check == NULL){
        printf("Not found! \n");

    }else{
        root=RemoveNode(root,maYC);
        if(check==NULL) printf("Delete\n");
        --countNode;
    }
}

void FprintTree(Node*r,FILE*f){
    if(r==NULL) return;
    FprintTree(r->leftChild,f);
    fprintf(f,"%s %d %d %s %02d-%02d-%d %d\n",r->data.code,r->data.songuoi,r->data.sophong,r->data.ks,r->data.dd,r->data.mm,r->data.yyy,r->data.kid);
    FprintTree(r->rightChild,f);
}

void task6(){
    char filename[]="booking_output.txt";
    FILE *f=fopen(filename,"w");
    if(f==NULL) printf("error \n");
    FprintTree(root,f);
    printf("%d \n",countNode);
    fclose(f);
}
void printMenu(){
    printf("Program \n");
    printf("1.Load data file \n");
    printf("2.Kiem tra yeu cau khong hop le \n");
    printf("3.Tra cuu theo ma yeu cau\n");
    printf("4.Thay doi yeu cau\n");
    printf("5.Huy yeu cau\n");
    printf("6.Luu ra file\n");
    printf("0.Quit\n");
}
int main(){
    int task;
    
    park = (Data*)malloc(1000*sizeof(Data));
    if(park==NULL){ 
    printf("ERROR: can't dynamically allocate memory!!!");
    return 1;
  }
    initBST();
    
    while (1)
    {
        printMenu();
        printf("Nhap chuc nang : ");
        scanf("%d", &task);
        switch (task)
        {
        case 1:
            task1();
              root=  query(root,0,sluong);
             back();
             getchar();
             
            break;
        case 2:
            task2();
            back();
            getchar();
            break;
        case 3:
          
            task3();
            back();
            getchar();
            break;
        case 4:
            task4();
            getchar();
            break;
       
        case 5:
            task5();
            back();
            getchar();
            break;

        case 6:
            task6();
            back();
            getchar();
            break;

        case 0:
            free(park);
            freeTree(root);
            return 0;
            break;
        }
    }
    return 0;
}
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
typedef struct Person{
    int id;
    char name[256];
    double w;
    double h;
    int age;
    struct Person *leftChild;
    struct Person *rightChild;
}Person;
Person* root;
Person* makePerson(int id, char* name, double w, double h, int age){
    Person* p = (Person*)malloc(sizeof(Person));
    strcpy(p -> name, name);
    p->id=id;
    p->w=w;
    p->h=h;
    p->age=age;
    p->leftChild=NULL;
    p->rightChild=NULL;
    return p;
}
Person* findPerson(Person* r,int id){
    if(r == NULL) return NULL;
    if(r->id == id) return r;
    Person* p = find(r->leftChild,id);
    if(p != NULL) return p;
    return find(r->rightChild, id);
}
void addleftChild(int u, int left, char* name, double w, double h, int age){
    Person* pu = find(root,u);
    if(pu == NULL){
        printf("not found %d\n", u); return;
    }
    if(pu->leftChild != NULL){
        printf("Person %d has already leftChild\n",u); return;
    }
    pu->leftChild = makePerson(left, name, w, h, age);
}
void addrightChild(int u, int right, char* name, double w, double h, int age)
{
    Person* pu = find(root,u);
    if(pu == NULL){
        printf("not found %d\n", u); return;
    }
    if(pu->rightChild != NULL)
    {
        printf("Person %d has already rightChild\n",u);
        return;
    }
    pu->rightChild = makePerson(right, name, w, h, age);
}
void load(){
    int id;
	char name[256];
	double w, h;
	int age;
	printf("input id: ");
	scanf("%d", &id);
	printf("input name: ");
	scanf("%s", &name);
	printf("input weight: ");
	scanf("%f", &w);
	printf("input height: ");
	scanf("%f", &h);
	printf("input age: ");
	scanf("%f", &age);
	root = makePerson(id, name, w, h, age);
}
   
void printTree(Person* r){
    if(r == NULL) return;
    printf("%d:", r->id);
    if(r->leftChild == NULL) printf("leftChild = NULL");
    else printf("leftChild = %d", r->leftChild->id);
    if(r->rightChild == NULL) printf(", rightChild =NULL");
    else printf(", rightChild = %d", r->rightChild->id);
    printf("\n");
    printTree(r->leftChild);
    printTree(r->rightChild);
}

void processLoad(){
    load();
}
void printChildren(Person* p){
    if(p->leftChild == NULL) printf("Person %d doesn't have leftChlid",p -> id);
    else printf(", LeftChild = %d", p->leftChild->id);
    if(p->rightChild == NULL) printf("Person %d doesn't have rightChild\n", p->id);
    else printf(", rightChild = %d\n", p->rightChild->id);
}
void processFind(){
    int id;
    scanf("%d",&id);
    Person* p = find(root,id);
    if(p == NULL) printf("Not found %d\n",id);
    else{
        printf("found person %d:", id);
        printChildren(p);
    }
}
void processPrint(){
    printTree(root);
}
void processAddLeftChild(){
    int id,u;
	char* name;
	double w,h;
	int age;
    scanf("%d%d",&id,&u);
    addleftChild(id,u, name, w, h, age);
}
void processAddRightChild(){
    int id,u;
	char* name;
	double w,h;
	int age;
    scanf("%d%d",&id,&u);
    addrightChild(id,u,name,w,h,age);
}
int height(Person* p){
    if(p == NULL) return 0;
    int maxH = 0;
    int hl = height(p->leftChild);
    if(maxH < hl) maxH = hl;
    int hr = height(p->rightChild);
    if(maxH < hr) maxH = hr;
    return maxH + 1;
}
void processHeight(){
    int id;
    scanf("%d",&id);
    Person* p = find(root,id);
    if(p == NULL) printf("Not found %d\n",id);
    else printf("Height of %d is %d\n", height(p));
}
int count(Person* p){
    if(p == NULL) return 0;
    return 1 + count(p->leftChild) + count(p->rightChild);
}
void printLeaves(Person* p){
    if(p == NULL) return;
    if(p->leftChild == NULL && p->rightChild == NULL)
    printf("%d ",p->id);
    printLeaves(p->leftChild);
    printLeaves(p->rightChild);
}
void processFindLeaves(){
    printLeaves(root); printf("\n");
}
void processCount(){
    printf("Number of person = %d\n",count(root));
}
void freeTree(Person* r){
    if(r == NULL) return;
    freeTree(r->leftChild);
    freeTree(r->rightChild);
    free(r); r = NULL;
}
void main(){
while(1){
char cmd[256];
printf("Enter a command: ");
scanf("%s",cmd);
if(strcmp(cmd,"Quit") == 0) break;
else if(strcmp(cmd,"Load")==0) processLoad();
else if(strcmp(cmd,"Print")==0) processPrint();
else if(strcmp(cmd,"Find")==0) processFind();
else if(strcmp(cmd,"Height")==0) processHeight();
else if(strcmp(cmd,"Count")==0) processCount();
else if(strcmp(cmd,"FindLeaves")==0) processFindLeaves();
else if(strcmp(cmd,"AddLeftChild")==0) processAddLeftChild();
else if(strcmp(cmd,"AddRightChild")==0) processAddRightChild();
}
freeTree(root);
}
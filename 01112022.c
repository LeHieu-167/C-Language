#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PERSON{
    int ID[10];
    float weight;
    int age;
    int gender;
    char vID[10];
    struct PERSON *next;
}PERSON;

typedef struct X{
    PERSON *P;
    struct X *next;
}X;
X *first, *last;
void initList(){
first = NULL; last = NULL;
}
X* makeNode(PERSON *P){
    X* node = (X*)malloc(sizeof(X));
    P->ID = X.ID;
    P->weight = X.weight;
    P->age = X.age;
    P->gender = X.gender;
    P->vID = X.vID;
    node->next =NULL;
    return node;
}
int listEmpty(){
return first == NULL && last == NULL;
}
void insertLast(int* ID, float* weight, int* age, int* gender, char*vID){
X* x = makeNode(PERSON *P);
if(listEmpty()){
first = x; last = x;
}else{
last->next = x; last = x;}
}
void printList(){
for(X* x = first; x != NULL; x = x->next)
printf("%s, %s\n",x->ID, x->weight, x->age, x->gender, x->vID);
}
void processInsert(){
    int ID[10];
    float weight;
    int age;
    int gender;
    char vID[10];
scanf("%d\n%f\n%d\n%d\n%c",&ID,&weight,&age,&gender,&vID);
insertLast(ID,weight,age,gender,vID);
}

int main()
{
   initList();
   while(1){
   printf("Enter command: ");
   char cmd[256];
   scanf("%s",cmd);
   if(strcmp(cmd,"Quit")==0) break;
   else if (strcmp(cmd,"Insert")==0)
   {
     processInsert();
   }
   return 0;
}
}
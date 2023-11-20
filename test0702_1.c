#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define max 100
void buildTree(int N){
  typedef struct Node{
  char name[max], seller[max], buyer[max], productID[max];
  int number;
  int cost;
  struct Node* lastleftchild;
  struct Node* rightsibling;
}Node;
Node* root;
Node* makeNode(char* name, char* seller, char* buyer, char* productID, int* number, int* cost){
  Node* p = (Node*)malloc(sizeof(Node));
  strcpy(p->name, name);
  strcpy(p->seller, seller);
  strcpy(p->buyer, buyer);
  strcpy(p->productID, productID);
  p->number = number;
  p->cost = cost;
  p->lastleftchild = NULL;
  p->rightsibling = NULL;
  return p;
}
Node* Insert(Node* r, char* name, char* seller, char* buyer, char* productID, int* number, int* cost){
  if (r == NULL) return makeNode(name, seller, buyer, productID, number, cost);
  int c = strcmp(r->name, name);
  if (c < 0)
  {r-> rightsibling = Insert(r->rightsibling, name, seller, buyer, productID, number, cost); return r; }
  if(c> 0)
  {r-> lastleftchild = Insert(r->lastleftchild, name, seller, buyer, productID, number, cost); return r;}

}
/*void processInsert(){
  char name[max];
  root = Insert(root, name, seller, buyer, productID, number, cost);
}*/
}


int isLeapYear(int year) {
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    return 1;
  }
  return 0;
}

int checkDate(int day, int month, int year) {
  if (year < 1 || year > 9999) {
    return 0;
  }
  if (month < 1 || month > 12) {
    return 0;
  }
  if (day < 1 || day > 31) {
    return 0;
  }
  if (month == 2) {
    if (isLeapYear(year)) {
      if (day > 29) {
        return 0;
      }
    } else {
      if (day > 28) {
        return 0;
      }
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return 0;
    }
  }
  return 1;
}

int checkcost(int cost){
  if(cost < 1 || cost > 2000000) return 0;
  return 1;
}
int checknumber(int number){
  if (number < 0 || number >= 100) return 0;
  return 1;
}
int maxcost(int cost, int number, int nline){
  int pcost = cost/number;
  int max_cost = 0;
  for (int i = 0; i < max; i++){
  if (pcost > max_cost){
    max_cost = pcost;
    nline = i;
  }
  }
  return 1;
}
int main() {
  int nline = 0;
  char line[max];
  int valid_dates = 0;
  int valid_cost = 0;
  int valid_number = 0;
  int count = 0;
  while (1) {
    fgets(line, max, stdin);
    if (line[0] == '$') {
      break;
    }
    int day, month, year, number, valid_line;
    int cost;
    char seller[max], buyer[max], productID[max];
    sscanf(line, "%d-%d-%d %s %s %s %d %d %d", &day, &month, &year, seller, buyer, productID, &number, &cost);
    if (checkDate(day, month, year)) {
      valid_dates++;
    }
    if (checkcost(cost)){
      valid_cost++;
      printf("So dong thoa man so tien hop le la: %d\n",valid_cost);
    }
    if (checknumber(number)){
      valid_number++;
      printf("So dong thoa man so san pham hop le la: %d\n", valid_number);
    }
    if (maxcost(cost, number, nline)){
      printf("Dong co so tien tren 1 san pham cao nhat la: %d\n",nline);
    }
  }
  int N;
  printf("nhap N:");
  scanf("%d",&N);
  buildTree(N);
  return 0;
}
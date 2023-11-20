#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bus{
	char name[256];
	int id;
	struct bus* next;
}bus;
bus* first, *last;

bus* makeBus(char* name, int id){
	bus* p = (bus*)malloc(sizeof(bus));
	strcpy(p->name,name);
	p->id = id;
	p->next = NULL;
	return p;
}

void initList(){
  first = NULL; last = NULL;
}
int listEmpty(){
  return first == NULL && last == NULL;
}

bus* insertLast(char* name, int id){
	bus* bus = makeBus(name, id);
  if(listEmpty()){
    first = bus; last = bus;
  }else{
    last->next=bus; last=bus;
  }
}

bus insertFirst(char* name, int id) {
  bus* bus = makeBus(name, id);
  if(listEmpty()){
    first = bus; last = bus;
  }else{
    
}

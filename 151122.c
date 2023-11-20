#include<stdio.h>
#include<stdlib.h>
typedef struct chicken{
    double w;
    double e;
    int g;
    struct chicken *next;
} chicken;

chicken *head, *tail;
chicken* makeNode(double w, double e, int g){
    chicken* p = (chicken*)malloc(sizeof(chicken));
    p -> w = w;
    p->e = e;
    p->g = g;
    p->next = NULL;
    return p;
}

void initQueue(){
    head = NULL; tail = NULL;
}

int queueEmpty(chicken *head, chicken *tail){
    return head == NULL && tail ==  NULL;
}

void push(double w, double e,int g, chicken* head, chicken* tail){
    chicken* p = makeNode(w, e, g);
    int a = check(p);
    if(a!=1)
    return ;
    if (queueEmpty(head, tail)){
        head = p; tail = p;
    }else{
        tail->next = p; tail = p;
    }
}

chicken* pop(chicken* head){
    if(queueEmpty(head, tail)) 
    return NULL;
    chicken* p = (chicken*)malloc(sizeof(chicken));
    p->w = head->w;
    p->e = head->e;
    p->g = head->g;

    chicken* tmp = head; head = head->next; free(tmp);

    return p;
}
int check(chicken* ch){
    if(ch->g != 0 && ch->g != 1)	return 0;
	if(ch->w > 5 || ch->w < 0.1)	return 0;
	if(ch->e > 1)	return 0;
	if(ch->g == 1 && ch->e >= 0) 	return 0;
	return 1;
}

int main(){
    head = NULL;
    tail = NULL;
	int N;
	printf("Nhap vao gia tri N: "); scanf("%d", &N);
	for(int i = 0; i < N; i++){
		double w, e;
		int g;
		printf("Nhap vao khoi luong: "); scanf("%lf", &w);
		printf("Nhap vao trung binh so trung trong 1 ngay: ");  scanf("%lf", &e);
		printf("Nhap truong gender cho ga: "); scanf("%d", &g);
		push(w, e, g, head, tail);
	}
return 0;
}

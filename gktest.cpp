#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char malop[10];
	char mahocphan[10];
	struct Node* next;
}Node;

Node* root;

Node* makeNode(char* malop, char* mahocphan){
	Node* p = (Node*)malloc(sizeof(Node));
	strcpy(p->malop, malop);
	strcpy(p->mahocphan, mahocphan);
	p->next = NULL;
	return p;
}

void insertLast(Node**r, char* malop, char* mahocphan){
	if (*r == NULL) {
        *r = makeNode(malop, mahocphan);
        return;
    }
    Node* tmp = *r;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    Node* tmp1 = makeNode(malop, mahocphan);
    tmp->next = tmp1;
}

void insertFirst(char* malop, char* mahocphan){
Node* newNode = makeNode(malop, mahocphan);
    newNode->next = root;
    root = newNode;
}

void printList(){
	for(Node* p = root; p!=NULL;p=p->next){
		printf("%s	%s\n", p->malop, p->mahocphan);
	}
}

void load(char* filename){
	FILE* f = fopen(filename,"r");
	if(f==NULL) {
		printf("Not found\n");
		return;
	}
	while(!feof(f)){
		char malop[10], mahocphan[10];
		fscanf(f, "%s%s", malop, mahocphan);
		insertLast(&root, malop, mahocphan);
	}
	fclose(f);
}

void processFind(){
	char mahocphan[10];
	scanf("%s", mahocphan);
	Node* tmp = root;
	for(Node* p = tmp; p!=NULL;p = p->next){
		if(strcpy(p->mahocphan, mahocphan)==0){
			tmp = p; break;
		}
	}
	if(tmp == NULL){
		printf("Not found");
	}else{
		printf("Found: %s	%s\n", tmp->malop,tmp->mahocphan);
	}
}

void processLoad(){
	char filename[256];
	scanf("%s",filename);
	load(filename);
}

int count(Node* p){
	int count = 0;
	Node* tmp = p;
	while(tmp!=NULL){
		count++;
		tmp=tmp->next;
	}
	return count;
}

Node* removeInfo(Node* r, char* malop){
	if(r==NULL) return NULL;
	if(strcpy(r->malop,malop)==0){
		Node* tmp = r->next;
		free(r);
		if(tmp == NULL) tmp = NULL;
		return tmp;
	}else{
		r->next = removeInfo(r->next,malop);
		return r;
	}
	printList();
}

void processInsertL(){
	char malop[10], mahocphan[10];
	scanf("%s%s",malop,mahocphan);
	insertLast(&root,malop,mahocphan);
}

void processInsertF(){
	char malop[10], mahocphan[10];
	scanf("%s%s",malop,mahocphan);
	insertFirst(malop,mahocphan);
}

void processStore(){
	char filename[256];
	scanf("%s", filename);
	FILE* f = fopen(filename, "w");
	for(Node* p = root; p!=NULL; p=p->next){
		fprintf(f,"%s	%s", p->malop, p->mahocphan);
		if(p->next==NULL) fprintf(f,"\n");
	}
	fclose(f);
}

void processRemove(){
	char malop[10];
	scanf("%s", malop);
	root = removeInfo(root, malop);
}

void freeNode(Node* r) {
    while (r != NULL) {
        Node* tmp = r;
        r = r->next;
        free(tmp);
    }
}

int main(){
	while(1){
		int d;
		printf("1.Hien thi:\n");
		printf("2.Tim kiem:\n");
		printf("3.Them vao dau danh sach:\n");
		printf("4.Them vao cuoi danh sach:\n");
		printf("5.Xoa\n");
		printf("6.Luu ra file\n");
		printf("7.Dem\n");
		printf("Bam so khac de thoat\n");
		printf("Chon chuc nang:");
		scanf("%d",&d);
		switch(d){
			case 1: processLoad; printList(); break;
			case 2: processFind(); break;
			case 3: processInsertF(); break;
			case 4: processInsertL(); break;
			case 5: processRemove(); break;
			case 6: processStore(); break;
			case 7: count(root); break;
			default: break;
		}
	}
	freeNode(root);
	return 0;
}

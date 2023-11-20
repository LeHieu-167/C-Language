#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int id;
	struct Node* LeftChild;
	struct Node* RightChild;
}Node;
Node* root;

Node* makeNode(int id){
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = id;
	p->LeftChild = NULL;
	p->RightChild = NULL;
	return p;
}

Node* find(Node* r,int id){
	if(r==NULL) return NULL;
	if(r->id==id) return r;
	Node* p = find(r->LeftChild, id);
	if(p!=NULL) return p;
	return find(r->RightChild, id);
}

void addLeftChild(int v, int left){
	Node* pv = find(root, v);
	if (pv==NULL) {
		printf("Not found %d\n", v);
		return;
	}
	if (pv->LeftChild!=NULL){
		printf("Node %d has already had LeftChild\n",v);
		return;
	}
	pv->LeftChild=makeNode(left);
}

void addRightChild(int v,int right){
	Node* pv = find(root,v);
	if(pv==NULL){
		printf("Not found %d\n", v);
		return;
	}
	if(pv->RightChild!=NULL){
		printf("Node %d has already had RightChild\n",v);
		return;
	}
	pv->RightChild=makeNode(right);
}

void load(char* filename){
	FILE* f = fopen(filename, "r");
	root = NULL;
	while (1){
		int v;
		fscanf(f,"%d",&v);
		if (v == -2) break;
		if (root == NULL) root = makeNode(v);
		int l, r;
		fscanf(f, "%d%d", &l, &r);
		if(l>-1) addLeftChild(v,l);
		if(r>-1) addRightChild(v, r);
	}
	fclose(f);
}

void printTree(Node* r){
	if (r == NULL) return;
	printf("%d: ", r->id);
	if (r->LeftChild==NULL) printf("LeftChild: null");
	else printf("LeftChild = %d", r->LeftChild->id);
	if (r->RightChild==NULL) printf(", RightChild: null");
	else printf(", RightChild = %d", r->RightChild->id);
	printf("\n");
	printTree(r->LeftChild);
	printTree(r->RightChild);
}

void printTreeF(Node* r, FILE* f){
	if(r==NULL) return;
	fprintf(f,"%d",r->id);
	if(r->LeftChild==NULL) fprintf(f, "-1");
	else fprintf(f,"&d",r->LeftChild->id);
	if(r->RightChild==NULL) fprintf(f, "-1");
	else fprintf(f,"%d",r->RightChild->id);
	fprintf(f,"\n");
	printTreeF(r->LeftChild,f);
	printTreeF(r->RightChild,f);
}

void processLoad(){
	char filename[256];
	scanf("%s",filename);
	load(filename);
}

void printChildren(Node* p){
	if(p->LeftChild==NULL) printf("Node %d doesn't have LeftChild", p->id);
	else printf(", LeftChild: %d",p->LeftChild->id);
	if(p->RightChild==NULL) printf("Node %d doesn't have RightChild", p->id);
	else printf(", RightChild: %d",p->RightChild->id);
}

void processFind(){
	int id;
	scanf("%d", &id);
	Node* p = find(root, id);
	if(p==NULL) printf("Not found %d\n", id);
	else{
		printf("Found node %d",id);
		printChildren(p);
	}
}

void processPrint(){
	printTree(root);
}

void processAddLeftChild(){
	int id, v;
	scanf("%d%d",&id,&v);
	addLeftChild(id, v);
}
void processAddRightChild(){
	int id, v;
	scanf("%d%d", &id,&v);
	addRightChild(id,v);
}

int height(Node* p){
	if(p==NULL) return 0;
	int maxH = 0;
	int hl = height(p->LeftChild);
	if(maxH<hl) maxH=hl;
	int hr = height(p->RightChild);
	if (maxH<hr) maxH=hr;
	return maxH + 1;
}

void processHeight(){
	int id;
	scanf("%d",&id);
	Node* p = find(root, id);
	if(p==NULL) printf("Not found %d\n", id);
	else printf("Height: %d\n", height(p));
}

int count(Node* p)
{
    if(p == NULL) return 0;
    return 1 + count(p->LeftChild) + count(p->RightChild);
}

void printLeaves(Node* p)
{
    if(p == NULL) return;
    if(p->LeftChild == NULL && p->RightChild == NULL) printf("%d ", p->id);
    printLeaves(p->LeftChild);
    printLeaves(p->RightChild);
}

void processFindLeaves()
{
    printLeaves(root);
    printf("\n");
}

void processCount()
{
    printf("Number of nodes = %d\n", count(root));
}

void processStore()
{
    char filename[256];
    scanf("%s", filename);
    FILE* f = fopen(filename, "w");
    printTreeF(root, f);
    fprintf(f,"-2");
    fclose(f);
}

void freeTree(Node* r)
{
    if(r == NULL) return;
    freeTree(r->LeftChild);
    freeTree(r->RightChild);
    free(r);
    r == NULL;
}

int main()
{
    while(1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if(strcmp(cmd, "Quit") == 0) break;
        else if(strcmp(cmd, "Load") == 0) processLoad();
        else if(strcmp(cmd, "Print") == 0) processPrint();
        else if(strcmp(cmd, "Find") == 0) processFind();
        else if(strcmp(cmd, "Height") == 0) processHeight();
        else if(strcmp(cmd, "Count") == 0) processCount();
        else if(strcmp(cmd, "FindLeaves") == 0) processFindLeaves();
        else if(strcmp(cmd, "AddLeftChild") == 0) processAddLeftChild();
        else if(strcmp(cmd, "AddRightChild") == 0) processAddRightChild();
        else if(strcmp(cmd, "Store") == 0) processStore();
    }
    return 0;
}

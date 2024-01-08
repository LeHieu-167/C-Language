#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 256
#define N 100000
typedef struct Profile{
	char name[max];
	char email[max];
}Profile;
Profile profile[N];
int n = 0;

void insert(char* name, char* email){
	int i = n-1;
	while(i >= 0){
		int c = strcmp(profile[i].name,name);
		if(c == 0){
			printf("Name %s exists, do not insert\n",name); return;
		}else if(c > 0){
			profile[i+1] = profile[i]; i--;
		}else break;
	}
	i++;
	strcpy(profile[i].name,name);
	strcpy(profile[i].email,email);
	n++;
}

void removeStudent(int idx){
	for(int i = idx; i < n -1; i++) profile[i] = profile [i+1];
	n--;
}

void load(char* filename){
	FILE* f = fopen(filename , "r");
	if(f == NULL) printf("File not found\n");
	n=0;
	while(!feof(f)){
		char name[max], email[max];
		fscanf(f, "%s%s",name,email);
		insert(name, email);
	}
	fclose(f);
}

void processLoad(){
	char filename[256];
	scanf("%s",filename);
	load(filename);
}

void printList(){
	for(int i = 0; i < n; i++){
		printf("student[%d]: %s, %s\n",i,profile[i].name, profile[i].email);
	}
}

int binarySearch(int L, int R,char* name){
	if(L > R) return -1;
	if(L == R){
		if(strcmp(profile[L].name,name)==0) return L;
		else return -1;
	}
	int m = (L+R)/2;
	int c = strcmp(profile[m].name,name);
	if(c == 0) return m;
	if(c < 0) return binarySearch(m+1,R,name);
	return binarySearch(L,m-1,name);
}

void processFind(){
	char name[256];
	scanf("%s",name);
	int idx = binarySearch(0,n-1,name);
	if(idx == -1){
		printf("Not found student %s\n",name);
	}else{
	printf("Found student %s, at position %d, email %s\n",profile[idx].name,idx,profile[idx].email);
	}
}

void processStore(){
	char filename[max];
	scanf("%s",filename);
	FILE* f = fopen(filename,"w");
	for(int i = 0; i<n; i++){
		fprintf(f,"%s %s",profile[i].name,profile[i].email);
		if(i < n-1) fprintf(f,"\n");
	}
	fclose(f);
}

void processInsert(){
	char name[256], email[256];
	scanf("%s%s",name,email);
	insert(name,email);
}

void processRemove(){
	char name[256];
	scanf("%s",name);
	int idx = binarySearch(0,n-1,name);
	if(idx == -1) printf("Not found %s\n",name);
	else{
		removeStudent(idx);
	}
}

int main(){
	while(1){
		printf("Enter command: ");
		char cmd[256];
		scanf("%s",cmd);
		if(strcmp(cmd,"Quit")==0) break;
		else if(strcmp(cmd,"Load")==0) processLoad();
		else if(strcmp(cmd,"Print")==0) printList();
		else if(strcmp(cmd,"Find")==0) processFind();
		else if(strcmp(cmd,"Insert")==0) processInsert();
		else if(strcmp(cmd,"Remove")==0) processRemove();
		else if(strcmp(cmd,"Store")==0) processStore();
	}
}

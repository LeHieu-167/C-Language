#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	int classid;
	char coursename[30];
	char room[10];
	int day;
	char slots[10];
	
} ql;
int kiemtra(char a[]){
	
	int i;
	int c=0;
    char h[10];
    for (i=0;i<strlen(a);i++){
    	if (a[i]=='-')
    	{   if (i==1){
    		
		
    		if (strlen(a)==3)
    		h[c]=a[i+1];
    		
			if (strlen(a)==4) {
				h[c]=a[i+1];
				h[c+1]=a[i+2];
			}
		}
		 if ( i==2){
			if (strlen(a)==4)
			h[c]=a[i+1];
			else if (strlen(a)==5){
				h[c]=a[i+1];
				h[c+1]=a[i+2];
			}
		}
		}
		
	
	
}
if (atoi(a)>12 || atoi(a)<1 || atoi(h)<1 || atoi(h)>12 || atoi(a)>atoi(h))
  return 0;
  else return 1;	
	
}
int kiemtra1(char a[],char b[]){
	int i;
	int c=0;
    char h[10];
    for (i=0;i<strlen(a);i++){
    	if (a[i]=='-')
    	{   if (i==1){
    		
		
    		if (strlen(a)==3)
    		h[c]=a[i+1];
    		
			if (strlen(a)==4) {
				h[c]=a[i+1];
				h[c+1]=a[i+2];
			}
		}
		 if ( i==2){
			if (strlen(a)==4)
			h[c]=a[i+1];
			else if (strlen(a)==5){
				h[c]=a[i+1];
				h[c+1]=a[i+2];
			}
		}
		}
	}
if (atoi(h)>=atoi(b))
return 1;
else return 0;

}


void nhap(ql mang[],int n){
	int i;
	for (i=0;i<n;i++){
		printf("nhap id lop : ");
		fflush(stdin);
		scanf("%d",&mang[i].classid);
		printf("nhap ten hoc phan : ");
		fflush(stdin);
		gets(mang[i].coursename);
		printf("nhap phong hoc : ");
		fflush(stdin);
		gets(mang[i].room);
		printf("nhap ngay hoc : ");
		fflush(stdin);
	do scanf("%d",&mang[i].day);
	while (mang[i].day<2 || mang[i].day>7);
		printf("nhap tiet hoc : ");
	do{
		
		fflush(stdin);
		 gets(mang[i].slots);
	}
		while (kiemtra(mang[i].slots)==0);
		
		
		
	}
}

void in(ql mang[],int n){
	int i;
	printf("%-10s %-30s %-20s %-10s %-10s\n","ma lop","ten mon hoc","ten phong","thu","tiet hoc");
	for (i=0;i<n;i++){
			printf("%-10d %-30s %-20s %-10d %-10s\n",mang[i].classid,mang[i].coursename,mang[i].room,mang[i].day,mang[i].slots);
	}
}
void timkiem(ql mang[],int n){
	char phong[10];
	printf("hay nhap ten phong muon tim : ");
	fflush(stdin);
	gets(phong);
	int i,dem=0;
	
	for (i=0;i<n;i++){
		if (strcmp(phong,mang[i].room) ==0) 
		{
			dem=dem+1;
		}
		
	}
	if (dem==0)
	printf("khong ton tai %s trong danh sach\n",phong);
	else {
		
	
	printf("thong tin lop hoc :\n");
	
	printf("so lop hoc : %d\n",dem);
	printf("%-10s %-30s %-20s %-10s %-10s\n","ma lop","ten mon hoc","ten phong","thu","tiet hoc");
	for (i=0;i<n;i++){
		if (strcmp(phong,mang[i].room)==0)
		printf("%-10d %-30s %-20s %-10d %-10s\n",mang[i].classid,mang[i].coursename,mang[i].room,mang[i].day,mang[i].slots);
	}
}
}
void sapxep(ql mang[],int n){
	int i,j;
	ql tem;
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
			if (mang[i].classid>mang[j].classid){
				tem=mang[i];
				mang[i]=mang[j];
				mang[j]=tem;
			}
		}
	}
	printf("%-10s %-30s %-20s %-10s %-10s\n","ma lop","ten mon hoc","ten phong","thu","tiet hoc");
	for (i=0;i<n;i++)
	printf("%-10d %-30s %-20s %-10d %-10s\n",mang[i].classid,mang[i].coursename,mang[i].room,mang[i].day,mang[i].slots);
}
void kiemtratrungphong(ql mang[],int n){
	int i,j;
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
			if (mang[i].day==mang[j].day && strcmp(mang[i].room,mang[j].room)==0 && kiemtra1(mang[i].slots,mang[j].slots)==1 ){
				printf("%d\n%d\n",mang[i].classid,mang[j].classid);
			}
		}
	}
}

int main(){
	ql mang[200];
	int key,xacnhan=0;
	int i=0,n;
	int a;
	while (1){
		printf("menu chuong trinh\n");
		printf("1.bo sung lop hoc\n");
		printf("2.in thong tin cac lop\n");
		printf("3.tim kiem theo phong\n");
		printf("4.sap xep\n");
		printf("5.kiem tra trung phong\n");
		printf("6.thoat chuong trinh\n");
		printf("chon 1,2,3,4,5,6 : ");
		scanf("%d",&key);
		if (key==1) i=i+1;
		switch (key){
			case 1:
				if (i<2)
				{
					printf("hay nhap so lop :");
					do scanf("%d",&n);
					while (n<=0 || n>200 );
					nhap(mang,n);
				
				}
				else {
					
	
	printf("so lop bo sung them : ");
	fflush(stdin);
	do scanf("%d",&a);
	while (n+a>200 ||a<1);
	   
	for (i=n;i<a+n;i++){
		printf("nhap id lop : ");
		fflush(stdin);
		scanf("%d",&mang[i].classid);
		printf("nhap ten hoc phan : ");
		fflush(stdin);
		gets(mang[i].coursename);
		printf("nhap phong hoc : ");
		fflush(stdin);
		gets(mang[i].room);
		printf("nhap ngay hoc : ");
	
		
		fflush(stdin);
     do scanf("%d",&mang[i].day);
  
	while (mang[i].day<2 || mang[i].day>7);
		printf("nhap tiet hoc : ");
	do{
		
		fflush(stdin);
	    gets(mang[i].slots);
	}
       while (kiemtra(mang[i].slots)==0);
	
}
n=n+a;
				}
				xacnhan=1;
				break;
			case 2 :
				if (xacnhan)
				in(mang,n);
				else printf("hay nhap du lieu \n ");
				break;
			case 3 : 
			     if (xacnhan)
			     timkiem(mang,n);
			     else printf("hay nhap du lieu\n");
			     break;
			case 4 :
				if (xacnhan)
				sapxep(mang,n);
				else printf("hay nhap du lieu \n");
				break;
			case 5 :
				if (xacnhan)
				kiemtratrungphong(mang,n);
				else printf("hay nhap du lieu\n");
				break;
			case 6 :
				return 1;
			default :
				printf("khong co lua chon trong menu\n");
				break;
			
		}
	}
	return 0;
}

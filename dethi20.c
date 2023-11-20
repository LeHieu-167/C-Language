#include <stdio.h>
#include <string.h>
#include<conio.h>
typedef struct{
    long ID ; // Question ID
    int chapter; // Chapter (from 1 to 20)
    char content[50]; // Question content (containing space)
} Question;
long ID =0;
int n = 0,num;
Question list[100];

int check(char str[], char c){
    int n=strlen(str);
    for(int i=0;i<n;++i){
        if(str[i] == c){
            return 0;
        }
    }
    return 1;
}

void printques(int i){
    printf("%d \t %d \t\t \"%s\" \n",list[i].ID,list[i].chapter,list[i].content);
}

void printmenu(){
    printf("**********MENU************ \n");
    printf("1.Read \n");
    printf("2.Search \n");
    printf("3.Add \n");
    printf("4.Count \n");
    printf("5.Check \n");
    printf("6.Exit \n");

}

int checkPrint(){
    int x;
    do{
        printf("Moi ban chon chuc nang (1->6): ");
        scanf("%d",&x);
        getchar();
    }while(x>6||x<1);
    return x;
}

int task1(int start){
    
    if(start>0) printf("Ban dang nhap cau hoi \n");
    do{
        printf("Moi ban nhap so cau hoi : \n");
        scanf("%d",&num);
        getchar();
        if(num<= 0 || num >100) printf(" Ban da nhap sai ! Moi nhap lai ! \n");

    }while(num<=0 || num > 100);
    num+=start;
    
    for(int i= start;i<num;i++){
        printf("Nhap cau hoi thu %d : ",i+1);list[i].ID = i+1;
        scanf("%d %[^\n]s",&list[i].chapter,list[i].content);
    }

    printf("Nhap thanh cong ! Duoi day la danh sanh cau hoi : \n");
    printf("ID \t Chapter \t Content \n");
    for(int i=0; i<num;++i){
            printques(i);
    }

    getchar();
    return num;
}

void task2(){
    //search
    
    int idx,key=0;
    printf("Nhap ID cua cau hoi muon tim : ");
    scanf("%d",&idx);
    for(int i=0; i < num ;i++){
        if(idx == list[i].ID){
            key=1;
            printf("ID \t Chapter \t Content \n");
            printques(i);
        }
            
    }
if(key == 0) printf("ID not found \n");
}

void task3(){
    //add
    int stt = num;
    printf("Moi ban nhap thong tin cua cau hoi can them : \n");
    scanf("%d %[^\n]s",&list[stt].chapter,list[stt].content);
    list[stt].ID = num +1;
    num++;
    printf("Nhap thanh cong ! Duoi day la danh sanh cau hoi : \n");
    printf("ID \t Chapter \t Content \n");
    for(int i=0; i<num;++i){
            printques(i);
    }

}

void task4(){
    int count[10000];
    int Max = list[0].chapter;
    for(int i=0;i<num;++i){
        if(list[i].chapter > Max) Max =list[i].chapter;
    }

    for(int i=0;i<=Max;++i){
        count[i]=0;
    }
    for(int i=0;i<num;++i){
        count[list[i].chapter]+=1;
    }
    printf("Chapter \t Count \n");
    for(int i=0;i<=Max;++i){
        if(count[i]>0){
            printf("%d \t\t %d \n",i,count[i]);
        }
    }
    getchar();
}

void task5(){
    //check
    int key[100];
    for(int i=0;i<num;++i){
        key[i] = 0;
    }
    for(int i=0;i<num;++i){
        if(list[i].content[0]>=65 &&  list[i].content[0] <=90){
            if(check(list[i].content,'*') == 1){
                if(check(list[i].content,'$') == 1){
                    if(check(list[i].content,'\\') == 1){
                        key[i]=1;
                    }
                }
            }
        }
    }
    printf("ID \t Chapter \t Content \n");
    for(int i=0;i<num;++i){
        if(key[i]==1){
            printques(i);
        }
    }
    getchar();
}
int main(){
  
    //#menu
    int task;
    while(1){
        printmenu();
        task=checkPrint();
        switch(task){
            case 1: n=task1(n);
            break;
            case 2: task2();
            break;
            case 3: task3();
            break;
            case 4: task4();
            break;
            case 5: task5();
            break;
            case 6: return 0;
            break;
        }
    }
  
    return 0;
}
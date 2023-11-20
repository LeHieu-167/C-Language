
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define C 10
typedef struct Info
{
    char hoVaTen[100];
    char birthday[100];
}Info;

int main(){
   char ** ho = malloc(10*sizeof(char*));
   /*char space[]= " ";
   char space2[]= " ";*/
   for (int i = 1; i<10; i++){
    ho[i]= malloc(100*sizeof(char));
    switch (i)
    {
    case 1: ho[i]="Nguyen "; break;
    case 2: ho[i]= "Tran "; break;
    case 3: ho[i]= "Le "; break;
    case 4: ho[i]= "Ly "; break;
    case 5: ho[i]= "Pham "; break;
    case 6: ho[i]= "Bui "; break;
    case 7: ho[i] = "Vu "; break;
    case 8: ho[i] = "Hoang "; break;
    case 9: ho[i] = "Mai "; break;
    default:
        break;
    }
   }
   char ** tenDem = malloc(10*sizeof(char*));
    for(int i = 0; i < 10; i++){
        tenDem[i] = malloc(100*sizeof(char));
        switch(i){
            case 0: tenDem[i] = "Van "; break;
            case 1: tenDem[i] = "Dac "; break;
            case 2: tenDem[i] = "The "; break;
            case 3: tenDem[i] = "Ly "; break;
            case 4: tenDem[i] = "Minh "; break;
            case 5: tenDem[i] = "Gia "; break;
            case 6: tenDem[i] = "Quoc "; break;
            case 7: tenDem[i] = "Duc "; break;
            case 8: tenDem[i] = "Si "; break;
            case 9: tenDem[i] = "Thi "; break;
        }
    }
     char** ten = malloc(10*sizeof(char*));
    for(int i = 0; i < 10; i++){
        ten[i] = malloc(100*sizeof(char));
        switch(i){
            case 0: ten[i] = "An"; break;
            case 1: ten[i] = "Bao"; break;
            case 2: ten[i] = "Cong"; break;
            case 3: ten[i] = "Dung"; break;
            case 4: ten[i] = "Minh"; break;
            case 5: ten[i] = "Giang"; break;
            case 6: ten[i] = "Hoa"; break;
            case 7: ten[i] = "Kien"; break;
            case 8: ten[i] = "Long"; break;
            case 9: ten[i] = "Nam"; break;
        }
    }
    Info arr[10];
     for(int i = 0; i < 10; i++){
        char* ghep = malloc(100*sizeof(char));
        strcat(ghep, ho[(i*i) % C]);
        strcat(ghep, tenDem[(i*i + 2*i + 1) % C]);
        strcat(ghep, ten[(i + i*i) % C]);
        strcpy(arr[i].hoVaTen, ghep);
        printf("%s \n", arr[i].hoVaTen);
    }

    return 0;
}  


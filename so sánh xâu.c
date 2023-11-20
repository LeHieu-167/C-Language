#include<stdio.h>
#include<string.h>
 
int main()
{
    int i, j, dem = 0;
    char s1[100], s2[100], s3[100];
    printf("\n Nhap chuoi s1:  ");
    gets(s1);
    fflush(stdin);
    printf("\n Nhap chuoi s1:  ");
    gets(s2);
    fflush(stdin);
    for(i = 0; i < strlen(s1); i++)
    {
        for(j = 0; j < strlen(s2); j++)
        {
            if(s1[i] == s2[j])
            {
                s3[dem] = s1[i];
                dem++;
                break;
            }
        }
    }
    printf("\n 2 chuoi co so ki tu giong nhau la: %d \n", dem);
    for(i = 0; i < dem; i++)
    putchar(s3[i]);
    return 0;
}
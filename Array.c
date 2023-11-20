#include <stdio.h>
#include<math.h>
int main(){
    double A[10];
    printf("please enter 10 numbers:\n");
    for(int i=0; i<10; i++){
    scanf("%lf", &A[i]);
    }
    double sum = 0.0, avg;
    for(int i = 0; i < 10; i++){
        sum = sum + A[i];
        avg = sum / (i+1);
    }
    printf("avg = %lf\n", avg);
    double mindiff = 10000;
    int medianindex;
    for(int i=0; i<10; i++){
        double diff = fabs(A[i] - avg);
        if(diff < mindiff){
            mindiff = diff;
            medianindex = i;
        }
    }
    printf("medianindex is %d\n", medianindex);
    printf("numbers in reversed order:\n");
    for(int i=9; i>=0; i--){
    printf("%3.4lf\n", A[i]);
    }
    return 0;
}
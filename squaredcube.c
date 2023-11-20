#include<stdio.h>
#include<math.h>
void main()
{
    double a, xn, ketqua;
    printf("Enter the value need to be squared cube\n");
    scanf("%lf", &a);
    xn = (a + 1)/2;
    do{
        ketqua = xn;
        xn = 0.5 * (xn + a/xn);
    } while (fabs(xn - ketqua) > 0.0001);
    printf("\nResult = %lf", xn);
}
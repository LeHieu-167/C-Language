#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    double D = b * b - 4 * a * c;

    if (D < 0) {
        printf("NO SOLUTION\n");
    } else if (D == 0) {
        double x0 = -b / (2.0 * a);
        printf("%.2lf\n", x0);
    } else {
        double x1 = (-b + sqrt(D)) / (2.0 * a);
        double x2 = (-b - sqrt(D)) / (2.0 * a);
        if (x1 < x2) {
            printf("%.2lf %.2lf\n", x1, x2);
        } else {
            printf("%.2lf %.2lf\n", x2, x1);
        }
    }

    return 0;
}

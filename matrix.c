#include <stdio.h>
int blackcol(int matrix[][1000],int rows, int colindex) {
    for (int i = 0; i < rows; i++) {
        if (matrix[i][colindex] != 1) {
            return 0;
        }
    }
    return 1;
}

int counting(int matrix[][1000], int rows, int cols) {
    int count = 0;
    for (int j = 0; j < cols; j++) {
        if (blackcol(matrix, rows, j)) {
            count++;
        }
    }
    return count;
}
int main() {
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);
    // Khai báo ma trận có kích thước rows x cols
    int matrix[1000][1000];
    // Nhập các phần tử của ma trận
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int colCount = counting(matrix, rows, cols);
    printf("%d\n", colCount);
    return 0;
}

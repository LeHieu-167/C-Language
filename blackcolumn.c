#include <stdio.h>

// Hàm kiểm tra xem một hàng có toàn phần tử 1 không
int isAllOnes(int row, int cols) {
    for (int i = 0; i < cols; i++) {
        if (row[i] != 1) {
            return 0; // Hàng không toàn phần tử 1
        }
    }
    return 1; // Hàng toàn phần tử 1
}

// Hàm đếm số hàng chỉ có phần tử 1 trong ma trận
int countRowsWithAllOnes(int matrix[][1000], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        if (isAllOnes(matrix[i], cols)) {
            count++;
        }
    }
    return count;
}

int main() {
    int rows, cols;

    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &rows);

    printf("Nhập số cột của ma trận: ");
    scanf("%d", &cols);

    int matrix[1000][1000]; // Đảm bảo đủ lớn để chứa ma trận

    printf("Nhập các phần tử của ma trận (chỉ 0 hoặc 1):\n");

    // Nhập các phần tử của ma trận
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rowCount = countRowsWithAllOnes(matrix, rows, cols);

    printf("Số hàng chỉ chứa phần tử 1: %d\n", rowCount);

    return 0;
}

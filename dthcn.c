#include <stdio.h>
#include <math.h>

int main() {
    int n; // Số lượng hình chữ nhật
    scanf("%d", &n);

    int max_dien_tich = 0; // Biến lưu trữ diện tích lớn nhất

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Tính chiều dài và chiều rộng
        int chieu_dai = fabs(x1 - x2);
        int chieu_rong = fabs(y1 - y2);

        // Tính diện tích
        int dien_tich = chieu_dai * chieu_rong;

        // So sánh diện tích với diện tích lớn nhất
        if (dien_tich > max_dien_tich) {
            max_dien_tich = dien_tich;
        }
    }

    printf("%d\n", max_dien_tich);

    return 0;
}

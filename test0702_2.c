#include <stdio.h>

int main() {
    FILE *fp;
    char c;

    

    // Mở tệp để ghi
    fp = fopen("test.txt", "w");

    // Kiểm tra xem tệp có thể mở hay không
    if (fp == NULL) {
        printf("Không thể mở tệp\n");
        return 1;
    }

    // Ghi một chuỗi vào tệp
    fprintf(fp, "Xin chào, đây là ví dụ về các thao tác với tệp.\n");

    // Đóng tệp
    fclose(fp);

    fp = fopen("test.txt", "r");

    // Kiểm tra xem tệp có thể mở hay không
    if (fp == NULL) {
        printf("Không thể mở tệp\n");
        return 1;
    }

    // Đọc từng ký tự trong tệp và in ra màn hình
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    // Đóng tệp
    fclose(fp);
    return 0;
}

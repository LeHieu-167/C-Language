#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hàm để đảm bảo cả hai chuỗi có cùng độ dài bằng cách thêm '0' ở đầu chuỗi ngắn hơn.
void equal_length(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    while (len_a < len_b) {
        strcat(a, "0");
        len_a++;
    }

    while (len_b < len_a) {
        strcat(b, "0");
        len_b++;
    }
}

// Hàm để thực hiện phép cộng.
char* add(char *a, char *b) {
    equal_length(a, b);

    int carry = 0;
    char *result = (char*)malloc(1000); // Đảm bảo đủ lớn để chứa kết quả.
    result[0] = '\0'; // Khởi tạo chuỗi kết quả rỗng.

    int len = strlen(a);

    for (int i = len - 1; i >= 0; --i) {
        // Cộng hai chữ số cùng hàng và thêm biến nhớ từ hàng bên phải dồn lên.
        int d = (a[i] - '0') + (b[i] - '0') + carry;

        carry = d / 10; // Biến nhớ bằng kết quả hàng trước chia 10.
        char temp[2];
        sprintf(temp, "%d", d % 10); // Viết chữ số cuối của kết quả thành chuỗi.

        // Nối chuỗi con vào kết quả.
        strcat(result, temp);
    }

    if (carry) {
        char temp[2];
        sprintf(temp, "%d", carry); // Biến nhớ thành chuỗi.
        strcat(result, temp);
    }

    // Đảo ngược chuỗi kết quả vì đã tính từ hàng đơn vị đến hàng cao nhất.
    int left = 0, right = strlen(result) - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }

    return result;
}

int main() {
    char a[1000], b[1000];
    scanf("%s", a);
    scanf("%s", b);

    char *result = add(a, b);

    printf("%s\n", result);

    // Giải phóng bộ nhớ.
    free(result);

    return 0;
}

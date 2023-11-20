#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char highest_transaction[100];
    int highest_cost_per_item = -1;
    int transaction_number = 0;

    while (1) {
        // Đọc dữ liệu đầu vào từ người dùng
        fgets(input, 100, stdin);

        // Kiểm tra nếu người dùng nhập dấu $ thì dừng vòng lặp
        if (input[0] == '$') {
            break;
        }

        // Phân tích thông tin từ dòng đầu vào
        char* day = strtok(input, "-");
        char* month = strtok(NULL, "-");
        char* year = strtok(NULL, " ");
        char* seller = strtok(NULL, " ");
        char* buyer = strtok(NULL, " ");
        char* productID = strtok(NULL, " ");
        char* number_str = strtok(NULL, " ");
        char* cost_str = strtok(NULL, "\n");

        // Chuyển đổi số lượng và giá thành số nguyên
        int number = atoi(number_str);
        int cost = atoi(cost_str);

        // Tính giá trên mỗi sản phẩm
        int cost_per_item = cost / number;

        // Kiểm tra nếu giá trên mỗi sản phẩm lớn hơn giá trên mỗi sản phẩm của giao dịch cao nhất hiện tại
        if (cost_per_item > highest_cost_per_item) {
            // Lưu thông tin của giao dịch cao nhất hiện tại
            highest_cost_per_item = cost_per_item;
            strcpy(highest_transaction, input);
        }

        transaction_number++;
    }

    // Kiểm tra nếu có ít nhất một giao dịch được nhập và giao dịch cao nhất hiện tại hợp lệ
    if (transaction_number > 0 && highest_cost_per_item >= 0) {
        // Tìm số thứ tự của giao dịch cao nhất hiện tại
        int i;
        for (i = 0; i < strlen(highest_transaction); i++) {
            if (highest_transaction[i] >= '0' && highest_transaction[i] <= '9') {
                printf("%d", atoi(&highest_transaction[i]));
                break;
            }
        }
    }

    return 0;
}


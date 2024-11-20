#include <stdio.h>

int input_quantity(int* array, int quantity) {
    int total = 0;

    for (int i = 0; i < quantity; i++) { 
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < quantity; i++) { 
        total += array[i];
    }

    return total;
}

void print_max_min(int* array, int min, int max) {
    printf("\n가장 많이 판매된 상품 : ID %d, 판매량 %d", max + 1, array[max]);
    printf("\n가장 적게 판매된 상품 : ID %d, 판매량 %d", min + 1, array[min]);
}

void check_low_stock(int* array, int amount) {
    for (int i = 0; i < amount; i++) {
        if (array[i] < 3) {
            printf("\n상품 ID %d : 재고부족(%d)", i + 1, array[i]);
        }
    }
}

int main() {
    int amount;
    scanf("%d", &amount);

    int receive[100];
    int total_receive = input_quantity(receive, amount);

    int sell[100];
    int total_sales = input_quantity(sell, amount);

    int stock[100];

    for (int i = 0; i < amount; i++) {
        stock[i] = receive[i] - sell[i];
    }

    printf("재고 수량 : ");
    for (int i = 0; i < amount; i++) {
        printf("%d ", stock[i]);
    }

    printf("\n총 판매량 : %d (판매율 %.2lf%%)", total_sales,
        (double)total_sales / total_receive * 100);

    int max_sales = 0, min_sales = 0;
    for (int i = 0; i < amount; i++) {
        for (int j = i + 1; j < amount; j++) {
            if (sell[max_sales] < sell[j]) {
                max_sales = j;
            }
            if (sell[min_sales] > sell[j]) {
                min_sales = j;
            }
        }
    }

    print_max_min(sell, min_sales, max_sales);
    check_low_stock(stock, amount);

    return 0;
}

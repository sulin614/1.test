#include <stdio.h>
#define AMOUNT 5

int receive[AMOUNT], sell[AMOUNT], stock[AMOUNT];
char product_name[30][AMOUNT];

void check_low_stock(int* array, int amount) {
    for (int i = 0; i < amount; i++) {
        if (array[i] < 3) {
            printf("상품 ID %d : 상품명 : %s 재고부족(%d)\n", i + 1, product_name[i],
                array[i]);
        }
    }
    printf("\n");
}

void print_result() {
    int max_sales = 0, min_sales = 0;

    for (int i = 0; i < AMOUNT - 1; i++) {
        if (sell[max_sales] < sell[i + 1]) {
            max_sales = i + 1;
        }
        if (sell[min_sales] > sell[i + 1]) {
            min_sales = i + 1;
        }
    }

    printf("\n가장 많이 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d",
        max_sales + 1, product_name[max_sales], sell[max_sales]);
    printf("\n가장 적게 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n",
        min_sales + 1, product_name[min_sales], sell[min_sales]);
}

void print_array(int* array) {
    for (int i = 0; i < AMOUNT; i++) {
        printf("%d ", array[i]);
    }
}

void add_stock() {
    for (int i = 0; i < AMOUNT; i++) {
        stock[i] += receive[i];
    }
}

void sub_stock() {
    for (int i = 0; i < AMOUNT; i++) {
        stock[i] -= sell[i];
    }
}

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

void ind_edit(int* array) {
    int id;

    printf("상품 ID: ");
    scanf("%d", &id);

    printf("입고수량: ");
    scanf("%d", &array[id - 1]);
}

void select_1() { 
    int select;

    printf(
        "입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n: ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        input_quantity(receive, AMOUNT);
        break;
    case 2:
        ind_edit(receive);
    default:
        break;
    }

    add_stock();
}

void select_2() {
    int select;

    printf(
        "판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n: ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        input_quantity(sell, AMOUNT);
        break;
    case 2:
        ind_edit(sell);
        break;
    default:
        break;
    }

    sub_stock();
}

void select_3() {
    printf("\n재고수량: ");
    print_array(stock);
    print_result();
    check_low_stock(stock, AMOUNT);
}

void select_4() {
    for (int i = 0; i < AMOUNT; i++) {
        printf("ID %d 상품명: ", i + 1);
        scanf("%s", product_name[i]);
    }

    printf("\n");
}

int select_menu() { 
    int select = 5;

    printf("[쇼핑몰 관리 프로그램]\n원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, "
        "3. 상품현황, 4. 상품명 입력 5. 종료)\n: ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        select_1();
        return 1;
        break;
    case 2:
        select_2();
        return 1;
        break;
    case 3:
        select_3();
        return 1;
        break;
    case 4:
        select_4();
        return 1;
        break;
    case 5:
        return -1;
        break;
    default:
        return -1;
        break;
    }
}

int main() {
    while (select_menu() != -1)
        printf("------------------------------------------------------------\n\n");
    printf("\n종료");

    return 0;
}

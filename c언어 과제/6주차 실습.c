#include <stdio.h>

struct product_struct {
    char name[100];
    int receive;
    int sell;
    int price;
};

struct product_struct product[5];

void get_total_sell() {
    int total_recv = 0, total_sell = 0;
    double sell_proportion;

    for (int i; i < 5; i++) {
        total_recv += product[i].receive;
        total_sell += product[i].sell;
    }

    sell_proportion = (double)total_sell / total_recv * 100;

    printf("\n총 판매량 : %d (판매율 : %.2lf%%)\n", total_sell, sell_proportion);
}

void get_min_max() {    // function that calculates min & max
    int max_idx = 0, min_idx = 0;

    for (int i = 1; i < 5; i++) {
        if (product[i].sell > product[max_idx].sell) max_idx = i;
        if (product[i].sell < product[min_idx].sell) min_idx = i;
    }

    printf("가장 많이 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n", max_idx + 1, product[max_idx].name, product[max_idx].sell);
    printf("가장 적게 판매된 상품 : ID %d, 상품명 : %s, 판매량 %d\n", min_idx + 1, product[min_idx].name, product[min_idx].sell);
}

void get_lower_stock() {
    for (int i = 0; i < 5; i++) {
        if ((product[i].receive - product[i].sell) < 3) {
            printf("상품 ID %d : 상품명 : %s 재고부족(%d)\n", i + 1, product[i].name, product[i].receive - product[i].sell);
        }
    }
}

void select_1() {   // 입고
    int id;
    printf(">> 상품 ID : ");
    scanf("%d", &id);

    if (id > 5) printf("\n(등록할 수 있는 상품의 최대 개수는 5개 입니다.)\n");   // 상품의 최대 개수를 5개로 설정

    else {
        printf(">> 상품명 : ");
        scanf("%s", product[id - 1].name);

        printf(">> 입고량 : ");
        scanf("%d", &product[id - 1].receive);

        printf(">> 판매가격 : ");
        scanf("%d", &product[id - 1].price);
    }
}

void select_2() {   // 판매
    int id;
    printf(">> 상품 ID : ");
    scanf("%d", &id);

    if (product[id - 1].price == 0) printf("\n(등록되지 않은 상품입니다.)\n");

    else {
        printf(">> 판매량 : ");
        scanf("%d", &product[id - 1].sell);
    }
}

void select_3() {   // 개별현황
    int id;
    printf(">> 상품 ID : ");
    scanf("%d", &id);

    printf("\n상품명 : %s\n", product[id - 1].name);
    printf("상품가격 : %d\n", product[id - 1].price);
    printf("입고량 : %d\n", product[id - 1].receive);
    printf("판매량 : %d\n", product[id - 1].sell);
    printf("총 판매금액 : %d\n", product[id - 1].price * product[id - 1].sell);
}

void select_4() {   // 전체현황
    printf("\n재고 수량 : ");
    for (int i = 0; i < 5; i++)  printf("%d ", product[i].receive - product[i].sell);
    get_total_sell();
    get_min_max();
    get_lower_stock();
}

int select_menu() { // 메뉴 선택 함수
    int select = 5;

    printf("[1] : 입고\n[2] : 판매\n[3] : 개별현황\n[4] : 전체현황\n[5] : 종료\n>> ");
    scanf("%d", &select);

    switch (select) {
    case 1:
        select_1();
        return 0;
        break;
    case 2:
        select_2();
        return 0;
        break;
    case 3:
        select_3();
        return 0;
        break;
    case 4:
        select_4();
        return 0;
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
        printf("\n------------------------------------------------------------\n\n");

    return 0;
}
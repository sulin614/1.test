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

    printf("\n�� �Ǹŷ� : %d (�Ǹ��� : %.2lf%%)\n", total_sell, sell_proportion);
}

void get_min_max() {    // function that calculates min & max
    int max_idx = 0, min_idx = 0;

    for (int i = 1; i < 5; i++) {
        if (product[i].sell > product[max_idx].sell) max_idx = i;
        if (product[i].sell < product[min_idx].sell) min_idx = i;
    }

    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", max_idx + 1, product[max_idx].name, product[max_idx].sell);
    printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ�� : %s, �Ǹŷ� %d\n", min_idx + 1, product[min_idx].name, product[min_idx].sell);
}

void get_lower_stock() {
    for (int i = 0; i < 5; i++) {
        if ((product[i].receive - product[i].sell) < 3) {
            printf("��ǰ ID %d : ��ǰ�� : %s ������(%d)\n", i + 1, product[i].name, product[i].receive - product[i].sell);
        }
    }
}

void select_1() {   // �԰�
    int id;
    printf(">> ��ǰ ID : ");
    scanf("%d", &id);

    if (id > 5) printf("\n(����� �� �ִ� ��ǰ�� �ִ� ������ 5�� �Դϴ�.)\n");   // ��ǰ�� �ִ� ������ 5���� ����

    else {
        printf(">> ��ǰ�� : ");
        scanf("%s", product[id - 1].name);

        printf(">> �԰� : ");
        scanf("%d", &product[id - 1].receive);

        printf(">> �ǸŰ��� : ");
        scanf("%d", &product[id - 1].price);
    }
}

void select_2() {   // �Ǹ�
    int id;
    printf(">> ��ǰ ID : ");
    scanf("%d", &id);

    if (product[id - 1].price == 0) printf("\n(��ϵ��� ���� ��ǰ�Դϴ�.)\n");

    else {
        printf(">> �Ǹŷ� : ");
        scanf("%d", &product[id - 1].sell);
    }
}

void select_3() {   // ������Ȳ
    int id;
    printf(">> ��ǰ ID : ");
    scanf("%d", &id);

    printf("\n��ǰ�� : %s\n", product[id - 1].name);
    printf("��ǰ���� : %d\n", product[id - 1].price);
    printf("�԰� : %d\n", product[id - 1].receive);
    printf("�Ǹŷ� : %d\n", product[id - 1].sell);
    printf("�� �Ǹűݾ� : %d\n", product[id - 1].price * product[id - 1].sell);
}

void select_4() {   // ��ü��Ȳ
    printf("\n��� ���� : ");
    for (int i = 0; i < 5; i++)  printf("%d ", product[i].receive - product[i].sell);
    get_total_sell();
    get_min_max();
    get_lower_stock();
}

int select_menu() { // �޴� ���� �Լ�
    int select = 5;

    printf("[1] : �԰�\n[2] : �Ǹ�\n[3] : ������Ȳ\n[4] : ��ü��Ȳ\n[5] : ����\n>> ");
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
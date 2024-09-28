#include <stdio.h>
#define AMOUNT 5

int receive[AMOUNT], sell[AMOUNT], stock[AMOUNT];

void check_low_stock(int* array, int amount) {
    for (int i = 0; i < amount; i++) {
        if (array[i] < 3) {
            printf("��ǰ ID %d : ������(%d)\n", i + 1, array[i]);
        }
    }
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

    printf("\n���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d", max_sales + 1, sell[max_sales]);
    printf("\n���� ���� �Ǹŵ� ��ǰ : ID %d, �Ǹŷ� %d\n", min_sales + 1, sell[min_sales]);
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

    for (int i = 0; i < quantity; i++) {  // ���� �Է�
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < quantity; i++) {  // �� ���� ���
        total += array[i];
    }

    return total;
}

void ind_edit(int* array) {
    int id;

    printf("��ǰ ID: ");
    scanf("%d", &id);

    printf("�԰����: ");
    scanf("%d", &array[id - 1]);
}

void select_1() {  // �԰� ����
    int select;

    printf("�԰���� �Է� : ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n: ");
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

    printf("�Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����\n: ");
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
    printf("\n������: ");
    print_array(stock);
    print_result();
    check_low_stock(stock, AMOUNT);
}

int select_menu() {  // �޴� ���� �Լ�
    int select = 4;

    printf("[���θ� ���� ���α׷�]\n���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n: ");
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
    printf("\n����");

    return 0;
}
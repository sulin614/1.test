#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void inputRandomArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 100;               // 0~99
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d\t", *(array + i));
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

int main() {
    int number[SIZE];

    srand(time(NULL));
    inputRandomArray(number, SIZE);             // &number[0] = number
    printArray(number, SIZE);

    return 0;
}

// ������ 4����Ʈ ���ڴ� 1����Ʈ --> p++ 1���� ���������� 5����(1~4�� ���� a�� ����), cp++ 7���� ���������� 8����(char�� 1����Ʈ)
// �迭�� ���ӵ� ������ ������� �ּҿ���(+,-)�� �迭�� ������,�����濡 �����ϱ� ����
// ������ ������ ������ ������ ��
// ������ ������ Ȱ���� �迭�� �ε��� �����ϱ� ������ �߿�
// �迭�� �ּ� ���� �����ؼ� �Ű�����(������)�� ���� --> ������������(*)�� ���ؼ� �迭�� ���� ����
// �迭�� �̸��� �ش� �迭 ���� �ּҰ��� �ǹ�
// a[0] = *(a+0)
// &a[0] = a
// a(1����)  a+0(1����)  *(a+0) 1������ �ִ� �� 
// a(1����)  a+1(5����)  *(a+1) 5������ �ִ� �� 
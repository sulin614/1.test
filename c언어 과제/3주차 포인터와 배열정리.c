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

// 정수는 4바이트 문자는 1바이트 --> p++ 1번지 다음번지는 5번지(1~4는 정수 a의 영역), cp++ 7번지 다음번지는 8번지(char는 1바이트)
// 배열은 연속된 공간에 만들어짐 주소연산(+,-)로 배열의 다음방,이전방에 접근하기 때문
// 포인터 연산은 덧셈과 뺄셈만 됨
// 포인터 연산은 활용해 배열의 인덱스 조작하기 때문에 중요
// 배열의 주소 값을 복사해서 매개변수(포인터)에 저장 --> 간접참조연산(*)을 통해서 배열에 접근 가능
// 배열의 이름은 해당 배열 시작 주소값을 의미
// a[0] = *(a+0)
// &a[0] = a
// a(1번지)  a+0(1번지)  *(a+0) 1번지에 있는 값 
// a(1번지)  a+1(5번지)  *(a+1) 5번지에 있는 값 
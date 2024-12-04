//구조체 : 서로 다른 데이터 타입들을 하나로 묶어 논리적으로 그룹화한 사용자 정의 데이터 타입이다.
#include <stdio.h>
#include <stdlib.h>

//구조체 정의
typedef struct point {
    int x;
    int y;
} POINT;

int inputMenu(void) {
    int input;
    printf("메뉴입력(1.구조체 만들기, 2. 구조체 출력하기, -1 종료) : ");
    scanf("%d", &input);
    return input;
}
//구조체 동적 생성 함수 : 동적으로 메모리를 할당하여 POINT 구조체를 생성하고, 초기화한 뒤 반환
POINT* makePoint(void) {
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}
//구조체 출력 함수 : POINT 구조체 포인터 배열과 크기를 받아, 모든 구조체의 내용을 출력
void printPoint(POINT* p[], int size) {
    for(int i = 0; i < size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}
//메모리 해체 함수 : POINT 구조체 포인터 배열과 크기를 받아, 할당된 모든 메모리를 해제
void freePoints(POINT* p[], int size) {
    for(int i = 0; i< size; i++)
        free(p[i]);
}

int main() {
    int menu;
    int count = 0;
    POINT* points[100];
    
    //메뉴 반복 처리
    do{
        menu = inputMenu();
        if(menu == 1) { //메뉴 1:  구조체 생성
            // 구조체 만들기
            points[count] = makePoint();
            count++;
        } else if(menu == 2) { //메뉴 2: 구조체 출력
            // 구조체 출력하기
            printPoint(points, count);
        } else if(menu == -1) { //메뉴 -1: 프로그램 종료
            freePoints(points, count);
            printf("프로그램을 종료합니다.\n");
        } while(menu > 0); //반복 종료 조건
        
        return 0;
    }
}

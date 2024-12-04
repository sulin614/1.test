#include <stdio.h>
#include <stdlib.h>

//구조체 정의
typedef struct point { //구조체 : 여러 데이터를 하나의 묶음으로 관리할 수 있게 해주는 사용자 정의 데이터 형식
    int x;
    int y;
} POINT;

//메뉴 입력 함수 정의 : 이 함수는 사용자에게 메뉴를 입력받고 해당 값을 반환함.
int inputMenu(void) {
    int input;

    printf("메뉴입력(1.구조체 만들기, 2. 구조체 출력하기, -1. 종료) : "); //출력
    scanf("%d", &input); //사용자로부터 정수를 입력받아 input 변수에 저장함.
    return input; //입력받은 값을 호출한 곳으로 반환합니다. 
}

int main() {
    int menu;

    //메뉴 입력 반복 처리 : inputMenu 함수를 호출하여 사용자로부터 메뉴를 입력받습니다.
    do {
        menu = inputMenu();
        //메뉴 선택에 따라 행동
        if(menu == 1) {
            // 구조체 만들기
        } else if(menu == 2) {
            // 구조체 출력하기
        } else if(menu == -1) {
            printf("프로그램을 종료합니다.");
        }
    } while(menu > 0); //반복문 종료 조건

    return 0;
}
//전체 동작 요약
//1. 프로그램이 시작되면 do-while 반복문이 실행됩니다.
//2. inputMenu() 함수가 호출되어 사용자가 메뉴를 입력합니다.
//3. 입력된 값에 따라 다음과 같은 행동(구조체를 생성하는 작업)을 수행
//4. 반복문이 종료되면 main 함수가 끝나며 프로그램이 종료됩니다.

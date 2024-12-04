#include <stdio.h>
#include <stdlib.h>                  //exit 함수와 rand,srand 등 랜덤 관련 함수 사용하기 위한 헤더파일
#include <time.h>                   // 시간 관련 함수(time)사용하기 위한 헤더파일

//구조체 정의
typedef struct point {                 // POINT라는 이름의 구조체 정의
    int x;                                //x좌표
    int y;                                //y좌표
} POINT;

//포인트 생성 함수
POINT makePoint(void) {                 //사용자로부터 좌표 입력받아 POINT구조체 반환하는 함수
    POINT p;                            //POINT 타입의 변수 p 선언
    scanf("%d %d", &p.x, &p.y);         //사용자로부터 x,y 좌표 입력받아 p.x와 p.y에 저장

    return p;                         //입력받은 좌표 포함한 POINT 구조체 반환
}
//임의의 좌표 생성 함수
void makeRandomPoints(POINT p[], int size) {               //포인트 구조체 배열에 임의의 숫자값으로 넣기
    srand(time(NULL));                                  //난수 생성기의 시드를 현재 시간으로 설정
    for (int i = 0; i < size; i++) {                   // 배열 크기만큼 반복
        p[i].x = rand() % 100;                        // 0~99까지의 랜덤한 x값 생성하여 배열에 저장
        p[i].y = rand() % 100;                        // 0~99까지의 랜덤한 y값 생성하여 배열에 저장
    }
}

//포인트 출력 함수
void printPoints(POINT p[], int size) {                    //구조체 한 개의 정보를 입력받아 출력하는 함수 만들기
    for (int i = 0; i < size; i++)                         //배열 크기만큼 반복
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);    //각 구조체의 x,y 값을 출력
}

//파일 저장 함수
void saveFile(POINT p[], int size) {                // savefile 함수에서 구조체배열(POINT p[])과 구조체배열의크기(int size)를 받아서 
    FILE* fp;                                       //           구조체사이즈만큼(sizeof) p부터 쓰는데 size번만큼 반복해서 fp에 써라
    fp = fopen("struct.bin", "wb");                  //써야지 읽을 수 있음 그래서 쓰기 모드 wb
    if (fp == NULL) exit(-1);                        // 파일 열기에 실패하면 프로그램을 종료하는 함수 --- <stdlib.h> 안에 있는 함수
    fwrite(p, sizeof(POINT), size, fp);             //POINT 배열 p의 내용을 바이너리 형식으로 파일에 기록
    fclose(fp);
}

//파일 로딩 함수
void loadFile(POINT p[], int size) {             //struct.bin 파일에서 데이터 읽어 POINT 구조체 배열에 로드하는함수
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);         //파일에서 POINT 배열 p로 데이터를 읽어옴
    fclose(fp);
}

int main() {
    POINT p[10];           //POINT 구조체 배열 p를 크기 10으로 선언
    loadFile(p, 10);       //파일에서 10개의 POINT 데이터를 읽어 p 배열에 저장
    printPoints(p, 10);    //p 배열에 저장된 10개의 POINT 데이터를 출력
    return 0;
}
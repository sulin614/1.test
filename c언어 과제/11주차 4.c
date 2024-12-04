#include <stdio.h>
#include <stdlib.h>

//POINT 구조체 정의
typedef struct point{
    int x;
    int y;
} POINT;
//메뉴 입력 함수
int inputMenu(void){
    int input;
    printf("1. 만들기, 2. 출력하기, 3. 클리어, 4. 파일저장, 5. 파일로드, -1. 종료 : \n");
    scanf("%d", &input);
    return input;
}
//POINT 생성 함수
POINT* makePoint(void){
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}
// POINT 배열 출력
void printPoint(POINT* p[], int size){
    for(int i = 0; i < size; i++){
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
    }
}
//동적 메모리 해제
void freePoints(POINT* p[], int size){
    for(int i = 0; i < size; i++){
        free(p[i]); // 동적으로 생성된 POINT 메모리 해제
    }
}
//좌표 데이터 파일 저장
int saveFile(POINT* p[], int count) {
    FILE* fp;
    fp = fopen("points.bin", "ab");  // 파일을 추가 쓰기 모드로 열기
    if (fp == NULL) return 0;       // 파일 열기 실패 시 0 반환

    for (int i = 0; i < count; i++) {
        fwrite(p[i], sizeof(POINT), 1, fp);  // POINT 데이터를 바이너리 형식으로 저장
    }
    fclose(fp);  // 파일 닫기
    return 1;    // 저장 성공 시 1 반환
}
//좌표 데이터 파일 로드
int loadFile(POINT* p[], int max) {
    FILE* fp;
    int fSize, fCount;

    fp = fopen("points.bin", "rb");  // 바이너리 읽기 모드로 파일 열기
    if (fp == NULL) return 0;       // 파일 열기 실패 시 0 반환

    fseek(fp, 0, SEEK_END);         // 파일 포인터를 파일 끝으로 이동
    fSize = ftell(fp);              // 파일 크기(바이트) 가져오기
    fCount = fSize / sizeof(POINT); // 저장된 POINT 개수 계산
    rewind(fp);                     // 파일 포인터를 파일 시작으로 이동

    for (int i = 0; i < fCount; i++) {
        if (i == max) break;        // 최대 로드 가능한 POINT 개수 초과 시 중단
        p[i] = (POINT*)malloc(sizeof(POINT));  // 동적으로 POINT 생성
        fread(p[i], sizeof(POINT), 1, fp);     // 파일에서 POINT 데이터 읽어오기
    }
    fclose(fp);  // 파일 닫기
    return fCount;  // 로드된 POINT 개수 반환
}
//메인 함수
int main() {
    int menu;                    // 사용자 선택 메뉴 번호
    int count = 0;               // 현재 POINT 개수
    POINT* points[100];          // 최대 100개의 POINT를 저장할 수 있는 배열

    do {
        menu = inputMenu();      // 사용자로부터 메뉴 입력
        switch (menu) {
            case 1:              // 새로운 POINT 생성
                points[count] = makePoint();
                count++;
                break;
            case 2:              // POINT 출력
                printPoint(points, count);
                break;
            case 3:              // 화면 클리어
                system("clear");  // 화면을 지움 (Linux/Unix 기반 명령어)
                break;
            case 4:              // POINT 데이터를 파일에 저장
                if (!saveFile(points, count)) 
                    printf("file open error...\n");
                else 
                    printf("file writing success..\n");
                break;
            case 5:              // 파일에서 POINT 데이터 로드
                count = loadFile(points, 100);
                break;
            case -1:             // 프로그램 종료
                freePoints(points, count);  // 동적으로 생성된 메모리 해제
                printf("프로그램을 종료합니다.\n");
                break;
        }
    } while (menu > 0);          // 양수 메뉴가 입력되었을 때 반복

    return 0;
}

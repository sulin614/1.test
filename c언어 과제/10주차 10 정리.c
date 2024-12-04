#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point {
    int x;
    int y;
} POINT;

POINT makePoint(void) {
    POINT p;
    scanf("%d %d", &p.x, &p.y);

    return p;
}

void makeRandomPoints(POINT p[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        p[i].x = rand() % 100;
        p[i].y = rand() % 100;
    }
}

void printPoints(POINT p[], int size) {
    for (int i = 0; i < size; i++)
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);
}

void saveFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "wb");
    if (fp == NULL) exit(-1);
    fwrite(p, sizeof(POINT), size, fp);
    fclose(fp);
}

void loadFile(POINT p[], int size) {
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);
    fclose(fp);
}

int main() {
    FILE* fp;
    POINT p[10];
    POINT p2;
    int pi;
    loadFile(p, 10);
    printPoints(p, 10);

    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1);                          // SEEK_SET 파일의 시작
    fseek(fp, sizeof(POINT) * 3, SEEK_SET);            // fseek --> stream에서 위치 찾아 파일 위치지정자(파일읽거나쓸위치)를 그곳으로 옮겨놓는 함수
    pi = ftell(fp);
    printf("pi = %d");
    fread(&p2, sizeof(POINT), 1, fp);                    // fseek(찾아서)--> fread(읽고)--> printf(출력)
    printf("p2 -> x : %d, p2 -> y : %d\n", p2.x, p2.y);
    fseek(fp, sizeof(POINT) * -2, SEEK_END);                  //-2 인덱스처럼 뒤에서 두번째거
    printf("pi = %d\n", ftell(fp));
    fread(&p2, sizeof(POINT), 1, fp);
    printf("p2 -> x : %d, p2 -> y : %d\n", p2.x, p2.y);
    fclose(fp);
    return 0;
}

// ftell --> 이진 스트림의 위치 지정자 현재 위치값을 반환한다(바이트 단위)
// 현재 위치를 알고 싶을 때, 파일의 크기를 알고 싶을 때 사용
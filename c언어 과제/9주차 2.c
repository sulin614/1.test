#include <stdio.h>

int getline(char* line) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}

int main() {
    char input[100];
    FILE* fp;              // 열기

    if ((fp = fopen("output.txt", "w")) == NULL) {     //"w"--> 쓰기모드    , 파일이 존재하지 않을시 NULL 반환
        printf("error...");
        return 0;
    }

    for (int i = 0; i < 5; i++) {     // 5번반복
        getline(input);
        fputs(input, fp);           // 한줄찍기
        fputs("\n", fp);            // fputs 함수는 \n을 자동으로 넣어주지 않아서 넣어줘야 함
    }

    fclose(fp);           // 닫기

    return 0;
}
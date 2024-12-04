// 텍스트 파일 복사하기
#include <stdio.h>

int getline(char* line) {    //사용자가 입력한 한줄 읽어 line배열에 저장
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') line[i++] = ch;  // 한문자 입력받고 \n 아닌동안 반복
    line[i] = '\0';    //줄바꿈 만나지 않으면 입력끝났을때 종료문자(\0)추가
    return i;          //줄바꿈 제외된 문자수만큼 반환
}

int main() {
    char input[100];
    FILE* fp;              // 열기

    if ((fp = fopen("output.txt", "w")) == NULL) {     //"w"--> 쓰기모드    , fopen-파일열면 포인터 반환, 파일이 존재하지 않을시 NULL 반환
        printf("error...");
        return 0;
    }

    for (int i = 0; i < 5; i++) {     // 5번반복
        getline(input);              // 한줄의 입력을 읽고 input배열에 저장
        fputs(input, fp);           // 한줄찍기
        fputs("\n", fp);            // fputs 함수는 \n을 자동으로 넣어주지 않아서 넣어줘야 함
    }

    fclose(fp);           // 닫기

    return 0;
}

//"w" 파일 존재하지 않으면 새로 만들고 이미 있으면 기존 파일에 덮어씀

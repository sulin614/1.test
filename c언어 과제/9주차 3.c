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
    FILE* fp_src;             // src = source
    FILE* fp_dest;

    if ((fp_src = fopen("output.txt", "r")) == NULL) {     // 읽기는 "r", 파일 열 수 없으면 fopen은 NULL반환
        printf("error...");
        return 0;                                                 //output 텍스트파일 열기
    }
    if ((fp_dest = fopen("output2.txt", "w")) == NULL) {    // 쓰기는 "w", "w"은 파일 없으면 새로 만들고 기존파일 있으면 덮어쓰기
        printf("error...");
        return 0;                                                //output2 텍스트파일 열기
    }

    while (!feof(fp_src)) {        // feo 함수는 파일포인터를 주면 파일의 끝인지 아닌지 확인하는 함수,파일끝 도달할때까지 반복, 끝이면 1, 끝이 아니면 0, !는 아니다라는 뜻
        fgets(input, 100, fp_src);  // fp_src 한줄씩 읽고 input배열에 저장, 최대 100개 읽고 \n 함께 읽음
        fputs(input, fp_dest);     //puts는 \n 찍어줌
    }

    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}

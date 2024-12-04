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

    if ((fp_src = fopen("output.txt", "r")) == NULL) {     // 읽기는 "r" 
        printf("error...");
        return 0;                                                 //output 텍스트파일 열기
    }
    if ((fp_dest = fopen("output2.txt", "w")) == NULL) {    // 쓰기는 "w"
        printf("error...");
        return 0;                                                //output2 텍스트파일 열기
    }

    while (!feof(fp_src)) {        // feo 함수는 파일포인터를 주면 파일의 끝인지 아닌지 알려주는 함수, 끝이면 1, 끝이 아니면 0, !는 아니다라는 뜻
        fgets(input, 100, fp_src);  // 한줄씩 읽는거
        fputs(input, fp_dest);     //puts는 \n 찍어줌
    }

    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}
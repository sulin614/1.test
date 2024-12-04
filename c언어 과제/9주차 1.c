#include <stdio.h>

int main() {
    int x, y, ch;
    char buffer[100];

    fscanf(stdin, "%d %d", &x, &y);
    fprintf(stdout, "%d %d\n", x, y);

    while ((ch = getchar()) != '\n');

    fgets(buffer, 100, stdin);
    fputs(buffer, stdout);

    return 0;
}

// stream : (컴퓨터)연속되는 데이터의 흐름, 모든 자료의 입출력은 운영체제(os)가 스트림으로 처리
// stdin(키보드) --> 입력, stdout(모니터파일) --> 출력
// 운영체제가 내부에 스트림 만들고 주소값(포인터)을 반환
// FILE 포인터로 접근해야 한다 
// stderr 스트림 : 에러 발생시 사용하는 스트림(모니터)
// fprintf --> 파일프린트f

// 텍스트파일 함수 원형
// FILE* fopen(const char* filename, const char* mode);   
// int fclose(FILE* stream);

// FILE* fp = fopen("test.txt", "w");

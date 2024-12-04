//표준 입출력 함수 사용
#include <stdio.h>

int main() {
    int x, y, ch;       //ch는 getchar() 읽어들인 문자 하나 저장하는변수
    char buffer[100];   //최대 100개 문자하나 저장하는 변수

    fscanf(stdin, "%d %d", &x, &y);  //fscanf-파일로부터 데이터 읽는 함수,stdin-->사용자가 키보드로 입력한 내용 읽음
    fprintf(stdout, "%d %d\n", x, y); //fprintf-파일에 데이터 출력,stdout-->표준출력에 값출력 

    while ((ch = getchar()) != '\n'); 
//getchar()로 입력받은 문자가 줄바꿈이 아닐때까지 계속 실행
    fgets(buffer, 100, stdin);   //fgets함수 문자열 읽어 buffer배열에 저장, 100-fgets 최대 99개까지 읽기가능,stdin-표준입력에서 문자열읽기
    fputs(buffer, stdout);      //fputs함수 문자열 파일에 출력,buffer-fgets로 입력받은문자열 출력,fputs 문자열끝 \n도 그대로 출력

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

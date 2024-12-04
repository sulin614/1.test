#include <stdio.h>          // printf,fopen,fwrite,fclose같은 함수들 이 라이브러리에서 제공
#define SIZE 100      //배열 크기를 100으로 정의

int main() {
    char input[SIZE];   //크기가 100인 문자 배열 선언
    FILE* fp = NULL;    //FILE 포인터를 NULL로 초기화, 이 포인터는 파일 열고 쓰고 닫는데 사용

    if ((fp = fopen("output.bin", "wb")) == NULL) {     //파일 열 수 없으면 fopen은 NULL반환 후   //bin = 바이너리, 쓰기 모드는 텍스트에서 w인데 바이너리라서 wb
        printf("error...");                             //파일 열기에 실패한 경우 error메시지 출력    
        return 0;
    }
    gets(input);                              //한줄의 문자열 입력받는 함수, puts - 내용출력하는거
    //fputs(input, fp);
    fwrite(input, strlen(input), 1, fp);     // input : 입력데이터를 저장하고 있는 배열, 2진수 데이터로 써야할 때는 fwrite  
                                            //  strlen(input) 문자열길이까지만 NULL문자 이전까지만 카운팅이 됨
    fclose(fp);                             //  파일 닫는 함수(닫지 않으면 제대로 저장 안 될 수도 있음)

    return 0;
}

// 원형
// size_t fread(void* ptr(읽어들일 데이터의 저장공간 주소값,자료형 크기 상관 없으므로 void*),size_t size(읽을데이터크기), size_t count(읽을데이터개수), FILE* stream(읽을파일));
// size_t fwrite(const void* ptr(써야할 데이터의 저장공간 주소값,자료형 크기 상관 없으므로 void*),size_t size(쓸데이터크기), size_t count(쓸데이터개수), FILE* stream(쓸파일));

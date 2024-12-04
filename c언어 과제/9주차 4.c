#include <stdio.h>

int my_getline(char* line) {
    int ch;
    int i = 0;
    while((ch = getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}

int main() {
    char input[100]; //문자열 데이터를 임시 저장할 버퍼
    int num1, num2; //파일에서 읽어온 두 정수를 저장할 변수
    FILE* fp_src; //소스 파일(output.txt)을 가리키는 파일 포인터
    FILE* fp_dest; //대상 파일(output3.txt)을 가리키는 파일 포인터

    //소스 파일 열기
    if((fp_src = fopen("output.txt", "r")) == NULL) { 
        printf("error...");
        return 0;
    }
    //대상 파일 열기
    if((fp_dest = fopen("output3.txt", "w")) == NULL) {
        printf("error...");
        return 0;
    }
    // 파일 데이터 처리
    while(!feof(fp_src)) { //파일의 끝(EOF)에 도달할 때까지 반복
        fscanf(fp_src, "%s %d %d\n", input, &num1, &num2); 
        //"%s %d %d\n":첫 번째는 문자열(%s), 두 번째와 세 번째는 정수(%d) 형식으로 읽습니다,
        //읽어온 데이터를 input, num1, num2에 저장
        fprintf(fp_dest, "%s %d %d\n", input, num1, num2); 
        // 읽어온 데이터를 동일한 형식으로 대상 파일 fp_dest에 씁니다.
    }
    //파일 닫기
    fclose(fp_src);
    fclose(fp_dest);
    return 0;
}

//  fscanf와 fprintf는 형식이 지정되어 있는 문자열일 경우 보 통 fprintf로 출력하면 fscanf 읽어드릴 수가 있다.
// 즉 한 줄씩 하고 싶다면 fgets와 fputs를 쓰면 된다.

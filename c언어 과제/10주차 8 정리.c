// 바이너리파일 배열데이터 읽기
#include <stdio.h>

int main() {
    int array[1000];
    FILE* fp;                 // 파일을 처리할 파일 포인터 선언(이 포인터는 파일을 열고,데이터를 읽고,파일을 닫는데 사용)
    int i = 0;                // 반복문에서 사용할 변수 i 선언
    fp = fopen("array.bin", "rb");         // rb ---> 읽기 모드
    if (fp == NULL) return -1;             // 파일 열기에 실패하면 -1을 반환하고 종료

    fread(array, sizeof(int), 100, fp);       // fread --> array에 fp파일에서 intsize만큼 100번 반복해서 읽어와서 집어넣기(fread를 사용하여 해당 파일에서 100개의 int값을 읽고 array배열에 저장)
                                              // fread ==> 파일에서 데이터를 읽어오는 함수
                                              // array : 읽은데이터저장할배열, sizeof(int) : 읽을데이터크기, 100 : 읽을데이터개수, fp : 읽을파일에대한포인터
    for (int i = 0; i < 100; i++) printf("%d ", array[i]);     // 0부터 99까지 반복

    fclose(fp);

    return 0;
}


// 바이너리파일 배열데이터 쓰기
#include <stdio.h>
int main() {
    int array[100];
    FILE* fp;

    for (int i = 0; i < 100; i++) array[i] = i;   //array[0] = 0, array[1] = 1, array[2] = 2 ...

    fp = fopen("array.bin", "wb");             // wb --> 쓰기모드
    if (fp == NULL) return -1;                 // 파일 열기 실패하면 -1 반환하고 종료

    fwrite(array, sizeof(int), 100, fp);        //배열의 데이터를 파일에 쓰는 함수, fwrite는 한번에 여러개 데이터를 파일에 쓰는 함수,int값은 4바이트로가정 총(100*4바이트)400바이트기록
    //array : 데이터를 쓸 배열의 포인터, sizeof(int) : 한번에 쓸 데이터 크기(int크기만큼데이터쓸거--int는 4바이트), 100 : 쓸 데이터 개수, fp : 데이터 쓸 파일 포인터
    fclose(fp);
    return 0;
}
// 바이너리 형식은 데이터를 텍스트 형식이 아님 텍스트 파일과는 달리 사람이 직접 읽을 수 없음 이 방식은 데이터 크기가 더 적고 빠르게 입출력 할 수 있음



//fread 기본실습
#include <stdio.h>
#define SIZE 100

int main()
{
    char input[SIZE];
    FILE* fp = NULL;           //파일 포인터 선언 및 초기화
    int i = 0;
    if((fp = fopen("output.bin", "rb")) == NULL){
        printf("error...");
        return 0;
    }
    while (!feof(fp)) {           // 파일 끝까지 반복(feof(fp)함수는 파일 끝에 도달했는지 여부 확인)--0을 반환시 아직 파일끝에 도달하지 않은것이고 1 반환시 파일끝에 도달한 것
        fread(&input[i], sizeof(char), 1, fp);   // 한문자씩 읽어서 input배열에 저장
        i++;                                    //배열 인덱스 증가
    }
    input[--i] = '\0';    // eof 만나면 fread까지 읽어서 뒤에 다른문자까지 찍혀서 출력됨 그래서 아예 앞번째 방에 넣어주기 위해 [--i]
    puts(input);         // 마지막에 불필요한 데이터가 배열에 추가되었을 수 있어서 마지막 문자 뒤에 '\0'추가하여 문자열 종료 시키는 것

    fclose(fp);

    return 0;
}
//동적할당 : 프로그램이 실행되는 도중에 메모리의 크기와 위치를 동적으로(필요에 따라) 결정하여 할당(나누어 주는 것)하는 것을 의미합니다.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* pChar; //문자형 포인터
    int* pInt; //정수형 포인터
    int count; //정수형 변수

    //프로그램이 실행되는 중간에 사용자로부터 카운트를 입력받아 메모리를 할당 받은것이다.
    //카운트 값에 따라서 받는 공간 값도 달라진다.
    //입력 받는 값에 크기가 프로그램이 동작할 때마다 달라진다면 지금 코드처럼 이런 경우에 사용하는 것이다.
    scanf("%d", &count); 
    pInt = (int*)malloc(count*sizeof(int));
    //malloc: 동적 메모리 할당 함수. count 크기의 정수형 배열을 힙 메모리에 생성하고, 그 시작 주소를 pInt에 저장한다.
    //(int*) : malloc 앞에(int*)를 써주는 이유는 지금 우리는 정수형으로 쓰고 싶기 때문에 int* 값으로 형변환을 해주는 것.
    //원래는 malloc이 반환하는 포인터는 void* 형식
    //count * sizeof(int): 필요한 메모리 크기를 계산. 정수형의 크기(sizeof(int))에 배열의 크기(count)를 곱함.

    for(int i = 0; i < count; i++) pInt[i] = rand() % 100;
    for(int i = 0; i < count; i++) printf("%d ", pInt[i]); //배열에 저장된 난수를 출력
    //printf("%d ", pInt[i]): 각 정수 값 뒤에 공백을 추가하여 출력

    pChar = (char*)pInt; //(char*)pInt: 정수형 포인터(int*)를 문자형 포인터(char*)로 형변환
    //할당 받은 공간을 문자형으로 쓰겠다 라는 의미

    while(getchar() != '\n'); //버퍼에 남아 있는 줄바꿈 문자(\n)를 소비합니다.
    gets(pChar); //사용자로부터 문자열 입력을 받음. 문자열은 pChar가 가리키는 메모리에 저장됌.
    puts(pChar); //puts: pChar가 가리키는 메모리 내용을 출력

    free(pInt); //동적으로 할당된 메모리를 해제

    return 0; //프로그램 종료
}
//malooc 활용방법 .1
//동적할당 받은건 반드시 꼭 헤제를 시켜줘야 한다.(Free를 이용해서 받은 주소값을 넘겨주면 된다)

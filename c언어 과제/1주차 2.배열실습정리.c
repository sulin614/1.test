#include <stdio.h>
#include <stdlib.h>                                  // 난수를 생성하기 위한 함수 rand가 들어있는 헤더파일 이름         
#include <time.h>                                     // 날짜 및 시간과 관계된 라이브러리 함수의 정보가 들어있음
int main()
{
	int number[10];                      //0~9

	srand(time(NULL));                   //srand는 seed-rand의 약자

	for (int i = 0; i < 10; i++) {           //for은 반복문 , 여기서는 입력을 해줌
		number[i] = (rand() % 100)+1;   // 어떤 숫자든 %(나누기) 100을 하면 0부터 99까지, 그래서 + 1 해주면 i값에 1부터 100까지 나온다
	}


	for (int i = 0; i < 10; i++) {            //여기서는 출력을 해줌
		printf("number = %d\n", number[i]);

	
	
	return 0;
}

// rand() --> 0에서부터 이 시스템에서 줄 수 있는 최대한의 수 임의의 값을 준다
// 실행할 때마다 동일한 패턴의 난수가 나오지 않게 srand를 활용/ time(NULL) time함수에 NULL값을 주면
//              이 프로그램이 돌아가는 현재 시간으로 초기값이 설정이 된다 --> 실행될때마다 시간이 다르므로 난수값이 다르게 나옴
// 배열의 방번호(index)--> 0부터 시작
// int array[3]: ---> 정수 세 개 저장하는 변수 array
// 배열 사용하면 99% for문 사용해야 --> 배열의 크기만큼 반복의 횟수 정해져 있음
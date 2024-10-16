#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void swap(int* a, int* b) {       //int* = 인티저포인터형 이거 앞에 * 꼭 해야함--> 주소값을 담는 변수, a에 주소값 들어가야 /int a = 답이 복사되어서 넘어가서 값이 바뀌지 않는다 swap거가 바뀌는 거 main에 영향 못 미침
	int temp;               
	temp = *a;                    //temp = a --> 이렇게 하면 안 됨 오류발생! a에 있는값(주소값)을 temp(일반변수)에 집어넣는 것이기 떄문
	*a = *b;
	*b = temp;                  

}
int main()
{
	int number[SIZE] = { 0 };
	int most;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 10000) + 1;
	}

	for (int i = 0; i < SIZE - 1; i++) {    
		most = i;
		for (int j = i + 1; j < SIZE; j++) {     
			if (number[most] < number[j]) most = j;
		}
		swap(&number[i], &number[most]);        //number[]이건 number값, 주소값 받으려면 앞에 &
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0)printf("\n");
	}

	return 0;
}
// c언어의 함수는 return이 한 개 밖에 안 됨 --> 그래서 pointer 필요한 것
//scanf에서 변수 앞 &는 주소값, 왜? --> c언어의 함수는 return이 한 개밖에 안 됨 두 개 이상 반환하려면 매개변수로 주소값 전달해야됨
//scanf --> 키보드에서 입력받아 저장 할 변수의 주소를 달라는 것
//정수는 크기가 4바이트 --> 맨 앞의 수로 넘어감 --> number[0] = 100번지 number[1] = 104번지 --> a와 b의 주소값 100,104를 scanf에 준다
//swap함수에게 주소값을 전달하면 swap함수가 a와 b의 주소값을 받는다
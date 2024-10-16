#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100             // 많이 쓰이는 수 SIZE 만들어주기
int main()
{
	int number[SIZE];
	int most;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 10000) + 1;
	}

	for (int i = 0; i < SIZE - 1; i++) {         //SIZE가 가장 마지막 방인데 마지막은 안 봐도 됨 그래서 SIZE-1
		most = i;
		for (int j = i + 1; j < SIZE; j++) {     //비교하기 위해선 두번째방부터 봐야하니 i+1부터 봐야됨 비교하는건 마지막까지 봐야해서 
			if (number[most] < number[j]) most = j;
		}
		temp = number[i];
		number[i] = number[most];                    // swap(number[i],number[most]);
		number[most] = temp;                         // 두 개의 변수 안에 있는 값 서로 바꿔주는 거
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);              //5자리 포맷으로 오른쪽 정렬해서 찍어라, %-5d 하면 왼쪽정렬됨
		if ((i + 1) % 10 == 0)printf("\n");      // (i+1)을 한 이유가 i가 0부터 시작해서 하나 출력하고 엔터키가 쳐지기 때문
	}

	return 0;
}
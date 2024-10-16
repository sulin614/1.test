#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100                          //SIZE라고 있는 곳에 100이 넣어짐
int main()
{
	int number[SIZE];
	int total = 0;
	int max, min;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 100) + 1;
	}
	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);          //%3d --> 3자리 포맷으로 오른쪽 정렬해서 찍는것, %-3d는 왼쪽정렬
		if ((i + 1) % 10 == 0)printf("\n");
	}
	for (int i = 0; i < SIZE; i++) {
		total += number[i];                //+= 계속하여 더하기
	}
	avg = (float)total / SIZE;             //total이 정수인데 float(실수)로 취급하는것 --> 형 변환
	max = number[0];
	min = number[0];

	for (int i = 1; i < SIZE; i++) {         
		if (max < number[i]) max = number[i];
		if (min > number[i]) min = number[i];
	}
	printf("avg = %f, max = %d, min = %d\n", avg,max,min);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100             // ���� ���̴� �� SIZE ������ֱ�
int main()
{
	int number[SIZE];
	int most;
	int temp;
	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = (rand() % 10000) + 1;
	}

	for (int i = 0; i < SIZE - 1; i++) {         //SIZE�� ���� ������ ���ε� �������� �� ���� �� �׷��� SIZE-1
		most = i;
		for (int j = i + 1; j < SIZE; j++) {     //���ϱ� ���ؼ� �ι�°����� �����ϴ� i+1���� ���ߵ� ���ϴ°� ���������� �����ؼ� 
			if (number[most] < number[j]) most = j;
		}
		temp = number[i];
		number[i] = number[most];                    // swap(number[i],number[most]);
		number[most] = temp;                         // �� ���� ���� �ȿ� �ִ� �� ���� �ٲ��ִ� ��
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);              //5�ڸ� �������� ������ �����ؼ� ����, %-5d �ϸ� �������ĵ�
		if ((i + 1) % 10 == 0)printf("\n");      // (i+1)�� �� ������ i�� 0���� �����ؼ� �ϳ� ����ϰ� ����Ű�� ������ ����
	}

	return 0;
}
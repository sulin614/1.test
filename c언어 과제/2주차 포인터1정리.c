#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void swap(int* a, int* b) {       //int* = ��Ƽ���������� �̰� �տ� * �� �ؾ���--> �ּҰ��� ��� ����, a�� �ּҰ� ���� /int a = ���� ����Ǿ �Ѿ�� ���� �ٲ��� �ʴ´� swap�Ű� �ٲ�� �� main�� ���� �� ��ħ
	int temp;               
	temp = *a;                    //temp = a --> �̷��� �ϸ� �� �� �����߻�! a�� �ִ°�(�ּҰ�)�� temp(�Ϲݺ���)�� ����ִ� ���̱� ����
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
		swap(&number[i], &number[most]);        //number[]�̰� number��, �ּҰ� �������� �տ� &
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%5d\t", number[i]);
		if ((i + 1) % 10 == 0)printf("\n");
	}

	return 0;
}
// c����� �Լ��� return�� �� �� �ۿ� �� �� --> �׷��� pointer �ʿ��� ��
//scanf���� ���� �� &�� �ּҰ�, ��? --> c����� �Լ��� return�� �� ���ۿ� �� �� �� �� �̻� ��ȯ�Ϸ��� �Ű������� �ּҰ� �����ؾߵ�
//scanf --> Ű���忡�� �Է¹޾� ���� �� ������ �ּҸ� �޶�� ��
//������ ũ�Ⱑ 4����Ʈ --> �� ���� ���� �Ѿ --> number[0] = 100���� number[1] = 104���� --> a�� b�� �ּҰ� 100,104�� scanf�� �ش�
//swap�Լ����� �ּҰ��� �����ϸ� swap�Լ��� a�� b�� �ּҰ��� �޴´�
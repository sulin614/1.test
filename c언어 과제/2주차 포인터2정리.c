#include <stdio.h>
int main()
{
	int i = 10;
	int* p;                                //int* p --> 정수형 변수의 주소값을 저장하는 변수 p 선언
	p = &i;                                //p = i하면 안 됨 i(정수)의 값을 (주소값)에 대입하는것이기 때문. i의 주소 = &i --> 변수의 메모리 주소(번지)

	printf("i = %d\n", i);
	printf("address of i = % p\n", p);
	printf("*p = %d\n", *p);

	return 0;
}
// p = &i --> 변수 i의 주소값을 p에 대입
//  p = &i 변수 i의 주소값을 p에 대입
//포인터의 초기화 int* p = NULL(널) 
//포인터 초기화    -->stdio.h 
// 여기까지 초기화 --> #define NULL 0
//포인터 변수의 크기는 모두 4바이트로 동일
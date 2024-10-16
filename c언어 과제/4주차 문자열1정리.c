#include <stdio.h>
int main() {

	char message[5] = { 'a','b','c','\0' };
	char message2[5] = { 'a','b','c','d','/0' };     //마지막에 반드시 NULL문자(\0)를 넣어줘야 printf가 판단을 하고 종료를 함

	printf("message = %s, message2 = %s", message, message2);   //printf는 배열의 크기 필요없음

	return 0;
}
// 문자열 데이터의 표현방법은 ""(큰따옴표로 묶는거)
// 배열 마지막에는 NULL문자(\0) 넣기 약속
// 문자열로 취급하는 배열은 \0 으로 끝난다 약속
// NULL문자가 들어갈 공간까지 고려해줘야함
// %s 문자열형식으로 출력
#include <stdio.h>
int main()
{
	int ch;
	char message[100];
	int i = 0;
	while ((ch = getchar())!= '\n') {           // 엔터키 아닌 동안 받겠다
		message[i++] = ch;
	}
	message[i] = '\0';     // 반드시 널 문자 넣어주기 
	printf("%s", message);
	return 0;
}
// int getchar(void); 키보드에서 문자 1개 입력받아 반환
// int putchar(int ch;); ch로 받은 문자를 화면에 출력, 해당 문자 반환
// End Of File  =  EOF(-1) 키보드 및 파일 입력의 끝 ctrl+z
// getchar() 엔터키 입력시 종료


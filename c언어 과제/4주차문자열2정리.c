#include <stdio.h>
int main()
{
	int ch;
	char message[100];
	int i = 0;
	while ((ch = getchar())!= '\n') {           // ����Ű �ƴ� ���� �ްڴ�
		message[i++] = ch;
	}
	message[i] = '\0';     // �ݵ�� �� ���� �־��ֱ� 
	printf("%s", message);
	return 0;
}
// int getchar(void); Ű���忡�� ���� 1�� �Է¹޾� ��ȯ
// int putchar(int ch;); ch�� ���� ���ڸ� ȭ�鿡 ���, �ش� ���� ��ȯ
// End Of File  =  EOF(-1) Ű���� �� ���� �Է��� �� ctrl+z
// getchar() ����Ű �Է½� ����


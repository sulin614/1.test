#include <stdio.h>
#include <string.h>           //���ڿ� ó�� �Լ�

int main()
{
    char src[100];
    char dest[100];
    int result;
    
    gets(src);
    gets(dest);
    
    // int length;
    
    // gets(src);
    // length = strlen(src);
    // printf("length of src = %d\n", length);
    
    // strcpy(dest, src);       �ڿ��� ������ ī�� 
    // printf("src = %s, dest = %s\n", src, dest);
    
    // strcat(dest, src);
    // printf("src = %s, dest = %s\n", src, dest);
    
    result = strcmp(src, dest);
    printf("result = %d\n", result);

    return 0;
}
// strcmp(���ڿ�1, ���ڿ�2) �� ���ڿ��� ������ 0 ����
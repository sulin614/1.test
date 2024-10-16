#include <stdio.h>
#include <string.h>           //문자열 처리 함수

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
    
    // strcpy(dest, src);       뒤에서 앞으로 카피 
    // printf("src = %s, dest = %s\n", src, dest);
    
    // strcat(dest, src);
    // printf("src = %s, dest = %s\n", src, dest);
    
    result = strcmp(src, dest);
    printf("result = %d\n", result);

    return 0;
}
// strcmp(문자열1, 문자열2) 두 문자열이 같으면 0 리턴
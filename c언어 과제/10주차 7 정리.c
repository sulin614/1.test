#include <stdio.h>          // printf,fopen,fwrite,fclose���� �Լ��� �� ���̺귯������ ����
#define SIZE 100      //�迭 ũ�⸦ 100���� ����

int main() {
    char input[SIZE];   //ũ�Ⱑ 100�� ���� �迭 ����
    FILE* fp = NULL;    //FILE �����͸� NULL�� �ʱ�ȭ, �� �����ʹ� ���� ���� ���� �ݴµ� ���

    if ((fp = fopen("output.bin", "wb")) == NULL) {     //���� �� �� ������ fopen�� NULL��ȯ ��   //bin = ���̳ʸ�, ���� ���� �ؽ�Ʈ���� w�ε� ���̳ʸ��� wb
        printf("error...");                             //���� ���⿡ ������ ��� error�޽��� ���    
        return 0;
    }
    gets(input);                              //������ ���ڿ� �Է¹޴� �Լ�, puts - ��������ϴ°�
    //fputs(input, fp);
    fwrite(input, strlen(input), 1, fp);     // input : �Էµ����͸� �����ϰ� �ִ� �迭, 2���� �����ͷ� ����� ���� fwrite  
                                            //  strlen(input) ���ڿ����̱����� NULL���� ���������� ī������ ��
    fclose(fp);                             //  ���� �ݴ� �Լ�(���� ������ ����� ���� �� �� ���� ����)

    return 0;
}

// ����
// size_t fread(void* ptr(�о���� �������� ������� �ּҰ�,�ڷ��� ũ�� ��� �����Ƿ� void*),size_t size(����������ũ��), size_t count(���������Ͱ���), FILE* stream(��������));
// size_t fwrite(const void* ptr(����� �������� ������� �ּҰ�,�ڷ��� ũ�� ��� �����Ƿ� void*),size_t size(��������ũ��), size_t count(�������Ͱ���), FILE* stream(������));

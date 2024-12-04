#include <stdio.h>

int main() {
    int x, y, ch;
    char buffer[100];

    fscanf(stdin, "%d %d", &x, &y);
    fprintf(stdout, "%d %d\n", x, y);

    while ((ch = getchar()) != '\n');

    fgets(buffer, 100, stdin);
    fputs(buffer, stdout);

    return 0;
}

// stream : (��ǻ��)���ӵǴ� �������� �帧, ��� �ڷ��� ������� �ü��(os)�� ��Ʈ������ ó��
// stdin(Ű����) --> �Է�, stdout(���������) --> ���
// �ü���� ���ο� ��Ʈ�� ����� �ּҰ�(������)�� ��ȯ
// FILE �����ͷ� �����ؾ� �Ѵ� 
// stderr ��Ʈ�� : ���� �߻��� ����ϴ� ��Ʈ��(�����)
// fprintf --> ��������Ʈf

// �ؽ�Ʈ���� �Լ� ����
// FILE* fopen(const char* filename, const char* mode);   
// int fclose(FILE* stream);

// FILE* fp = fopen("test.txt", "w");

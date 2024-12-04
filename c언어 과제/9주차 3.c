#include <stdio.h>

int getline(char* line) {
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n') line[i++] = ch;
    line[i] = '\0';
    return i;
}

int main() {
    char input[100];
    FILE* fp_src;             // src = source
    FILE* fp_dest;

    if ((fp_src = fopen("output.txt", "r")) == NULL) {     // �б�� "r" 
        printf("error...");
        return 0;                                                 //output �ؽ�Ʈ���� ����
    }
    if ((fp_dest = fopen("output2.txt", "w")) == NULL) {    // ����� "w"
        printf("error...");
        return 0;                                                //output2 �ؽ�Ʈ���� ����
    }

    while (!feof(fp_src)) {        // feo �Լ��� ���������͸� �ָ� ������ ������ �ƴ��� �˷��ִ� �Լ�, ���̸� 1, ���� �ƴϸ� 0, !�� �ƴϴٶ�� ��
        fgets(input, 100, fp_src);  // ���پ� �д°�
        fputs(input, fp_dest);     //puts�� \n �����
    }

    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}
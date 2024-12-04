#include <stdio.h>
#include <stdlib.h>                  //exit �Լ��� rand,srand �� ���� ���� �Լ� ����ϱ� ���� �������
#include <time.h>                   // �ð� ���� �Լ�(time)����ϱ� ���� �������

//����ü ����
typedef struct point {                 // POINT��� �̸��� ����ü ����
    int x;                                //x��ǥ
    int y;                                //y��ǥ
} POINT;

//����Ʈ ���� �Լ�
POINT makePoint(void) {                 //����ڷκ��� ��ǥ �Է¹޾� POINT����ü ��ȯ�ϴ� �Լ�
    POINT p;                            //POINT Ÿ���� ���� p ����
    scanf("%d %d", &p.x, &p.y);         //����ڷκ��� x,y ��ǥ �Է¹޾� p.x�� p.y�� ����

    return p;                         //�Է¹��� ��ǥ ������ POINT ����ü ��ȯ
}
//������ ��ǥ ���� �Լ�
void makeRandomPoints(POINT p[], int size) {               //����Ʈ ����ü �迭�� ������ ���ڰ����� �ֱ�
    srand(time(NULL));                                  //���� �������� �õ带 ���� �ð����� ����
    for (int i = 0; i < size; i++) {                   // �迭 ũ�⸸ŭ �ݺ�
        p[i].x = rand() % 100;                        // 0~99������ ������ x�� �����Ͽ� �迭�� ����
        p[i].y = rand() % 100;                        // 0~99������ ������ y�� �����Ͽ� �迭�� ����
    }
}

//����Ʈ ��� �Լ�
void printPoints(POINT p[], int size) {                    //����ü �� ���� ������ �Է¹޾� ����ϴ� �Լ� �����
    for (int i = 0; i < size; i++)                         //�迭 ũ�⸸ŭ �ݺ�
        printf("point[%d] = x : %d, y : %d\n", i, p[i].x, p[i].y);    //�� ����ü�� x,y ���� ���
}

//���� ���� �Լ�
void saveFile(POINT p[], int size) {                // savefile �Լ����� ����ü�迭(POINT p[])�� ����ü�迭��ũ��(int size)�� �޾Ƽ� 
    FILE* fp;                                       //           ����ü�����ŭ(sizeof) p���� ���µ� size����ŭ �ݺ��ؼ� fp�� ���
    fp = fopen("struct.bin", "wb");                  //����� ���� �� ���� �׷��� ���� ��� wb
    if (fp == NULL) exit(-1);                        // ���� ���⿡ �����ϸ� ���α׷��� �����ϴ� �Լ� --- <stdlib.h> �ȿ� �ִ� �Լ�
    fwrite(p, sizeof(POINT), size, fp);             //POINT �迭 p�� ������ ���̳ʸ� �������� ���Ͽ� ���
    fclose(fp);
}

//���� �ε� �Լ�
void loadFile(POINT p[], int size) {             //struct.bin ���Ͽ��� ������ �о� POINT ����ü �迭�� �ε��ϴ��Լ�
    FILE* fp;
    fp = fopen("struct.bin", "rb");
    if (fp == NULL) exit(-1);
    fread(p, sizeof(POINT), size, fp);         //���Ͽ��� POINT �迭 p�� �����͸� �о��
    fclose(fp);
}

int main() {
    POINT p[10];           //POINT ����ü �迭 p�� ũ�� 10���� ����
    loadFile(p, 10);       //���Ͽ��� 10���� POINT �����͸� �о� p �迭�� ����
    printPoints(p, 10);    //p �迭�� ����� 10���� POINT �����͸� ���
    return 0;
}
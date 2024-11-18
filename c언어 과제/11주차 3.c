#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} POINT;

int inputMenu(void) {
    int input;
    printf("�޴��Է�(1.����ü �����, 2. ����ü ����ϱ�, -1 ����) : ");
    scanf("%d", &input);
    return input;
}

POINT* makePoint(void) {
    POINT* p = (POINT*)malloc(sizeof(POINT));
    p->x = rand() % 100;
    p->y = rand() % 100;
    return p;
}

void printPoint(POINT* p[], int size) {
    for (int i = 0; i < size; i++)
        printf("x:%d, y:%d\n", p[i]->x, p[i]->y);
}

void freePoints(POINT* p[], int size) {
    for (int i = 0; i < size; i++)
        free(p[i]);
}

int main() {
    int menu;
    int count = 0;
    POINT* points[100];
    do {
        menu = inputMenu();
        if (menu == 1) {
            // ����ü �����
            points[count] = makePoint();
            count++;
        }
        else if (menu == 2) {
            // ����ü ����ϱ�
            printPoint(points, count);
        }
        else if (menu == -1) {
            freePoints(points, count);
            printf("���α׷��� �����մϴ�.\n");
        } while (menu > 0);

        return 0;
    }
}
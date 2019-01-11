#include <stdio.h>  //STanDart Input-Output
#include <windows.h>
#include <conio.h>
#include <stdlib.h> //STanDart LIBrary

#define numberOfBullets 10
#define sizeOfMap 10
#define tickDuration 60 //���������� � ������������
#define numberOfTanks 2

struct tank {
    int x;
    int y;
    int HP;
};

struct bullet {
    int x;
    int y;
    int damage;
    int direction; // ����� - 0   ����� - 1   �� - 2  ������ - 3
    int velocity;
};

int main () {

    int control; // ����� �������� ����� ��������� �������
    int i, j;   // �������� ������ �����
    int x = sizeOfMap/2, y=sizeOfMap/2;
    int HP=3;
    int *X; // ��������� �� ����� ������ (����� ����� ������), ����������� ��������� ���� Int
    int *Y;
    int *D;
    char **Map; // ���������� ������ (�������) ��������
    struct tank *Tanks;
    struct bullet *Bullets;


    Tanks = (struct tank*)malloc(sizeof(struct tank)*numberOfTanks);
    Bullets = (struct bullet*)malloc(sizeof(struct bullet)*numberOfBullets);

    X = (int*)malloc(sizeof(int)*numberOfBullets);
    Y = (int*)malloc(sizeof(int)*numberOfBullets);
    D = (int*)malloc(sizeof(int)*numberOfBullets);

    for (i=0; i<numberOfBullets; i++) {
        D[i]=0;
        //printf("%d\t%d\n", i, D[i]);
    }

    Map = (char**)malloc(sizeof(char*)*sizeOfMap);
    for (j=0; j<sizeOfMap; j++){
        Map [j]=(char*)malloc(sizeof(char)*sizeOfMap);
    }


    for (i=0; i<sizeOfMap; i++) {
        for (j=0; j<sizeOfMap; j++) {
            Map [i][j]=' ';
            //printf("%d\t%d\t%d\n", i, j, Map[i][j]);
        }
    }

    Map[x][y] = 'T';

    while (1) {
        if (kbhit ()) {// KeyBoard Hit
                        // ���������� 1, ���� ������ �����-�� �������
                        // ���������� 0, ���� ������ �� ������
                control = getch();  // Get CHaracter
        }
        //��������� �����

        // 1. ����������� ������
        Map[x][y] = ' ';
        if (control==119){ // ������� ������� "W"; �������� �����
            x=x-1;
        }
        if (control==97){ // ������� ������� "A"; �������� �����
            y=y-1;
        }
        if (control==115) { // ������� ������� "S"; �������� ����
            x=x+1;
        }
        if (control==100){ // ������� ������� "D"; �������� ������
            y=y+1;
        }

        // 2. ������� ������
        if (control==32) { // ������� ������� "SPACE"; �������
            Bullets[0].velocity = 1;
            Bullets[0].damage = 1;
            Bullets[0].direction = 3;
        }

        if ( (Bullets[0].velocity == 0) ) {
            Map[Bullets[0].x][Bullets[0].y] = ' ';
            if (Bullets[0].direction==0) {
                x=x-1;
            }
            if (Bullets[0].direction==1) {
                y=y-1;
            }
            if (Bullets[0].direction==2) {
                x=x+1;
            }
            if (Bullets[0].direction==3) {
                y=y+1;
            }

        }
        Map[x][y] = 'T';
        printf("x: %d\ty: %d\n", x, y);


        //����� �� ������� ~ ��� `
        if ( (control==96)||(control==126) ){
            return (0);
        }
        control=0;


        // ��������� �����
        for(i=0; i<sizeOfMap; i++){
            for(j=0; j<sizeOfMap;j++){
                printf("%c", Map[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        //printf("%c\n", pressedKey);
        //printf("%d\t%d\n", x, y);
        Sleep (tickDuration);
        system("cls");  // CLean Screen
    }

}

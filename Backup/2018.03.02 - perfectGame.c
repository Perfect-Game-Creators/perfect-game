#include <stdio.h> //STanDart Input-Output
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
    char direction; // ����� - 'N'   ����� - 'W'   �� - 'S'  ������ - 'E'
    int velocity;   // �������, ��� ���� �������� �������, �� ������� �� ���������� (�� ������ ���)
    int damage;
};

int move (int*x, int*y, int direction) {

    if direction=='N'

    return (0);
}
int main () {

    int control; // ����� �������� ����� ��������� �������
    int i, j; // �������� ������ �����
    char **Map; // ���������� ������ (�������) ��������
    struct tank *Tanks;
    struct bullet *Bullets;


    // �������� ������ ��� �����
    Tanks = (struct tank*)malloc(sizeof(struct tank) * numberOfTanks);
    // �������� ������ ��� �������
    Bullets = (struct bullet*)malloc(sizeof(struct bullet) * numberOfBullets);
    // �������� ������ ��� �����
    for (i=0; i<sizeOfMap; i++){
        Map = (char**)malloc(sizeof(char*)*sizeOfMap);
        for (j=0; j<sizeOfMap; j++){
            Map [j]=(char*)malloc(sizeof(char)*sizeOfMap);
        }
    }


    // ����� ��������� ��� ������� ���������������, �� ����, �������� ��������
    for (i = 0; i < numberOfBullets; i++) {
        Bullets[i].velocity = 0;
        //printf("%d\t%d\n", i, D[i]);
    }

    // ��������� ��� ������ ����� ���������
    for (i=0; i<sizeOfMap; i++) {
        for (j=0; j<sizeOfMap; j++) {
            Map [i][j]=' ';
            //printf("%d\t%d\t%d\n", i, j, Map[i][j]);
        }
    }
    // ���������� ��������� ��������� ����� ������
    Tanks[0].x = sizeOfMap/2;
    Tanks[0].y = sizeOfMap/2;
    Tanks[0].HP = 3;
    Map[Tanks[0].x][Tanks[0].y] = 'T';


    // ������������� ���������, ��������� ���� ����
    while (1) {

        /*
            ��������� �����
        */

        // 0. �����������, ������ �� �������, � ���� ��, �� ��������� ��������
        if (kbhit ()) { // KeyBoard Hit
                        // ���������� 1, ���� ������ �����-�� �������
                        // ���������� 0, ���� ������ �� ������
                control=getch();
        }
        //��������� �����

        // 1. ����������� ������
        Map[Tanks[0].x][Tanks[0].y] = ' ';
        if (control==119){ // ������� ������� "W"; �������� �����
            Tanks[0].x = Tanks[0].x - 1;
        }
        if (control==97){ // ������� ������� "A"; �������� �����
            Tanks[0].y = Tanks[0].y - 1;
        }
        if (control==115) { // ������� ������� "S"; �������� ����
            Tanks[0].x = Tanks[0].x + 1;
        }
        if (control==100){ // ������� ������� "D"; �������� ������
            Tanks[0].y = Tanks[0].y + 1;
        }
        Map[Tanks[0].x][Tanks[0].y] = 'T';
        printf("x: %d\ty: %d\n", Tanks[0].x, Tanks[0].y);

        // 2. ������� ������
        if  (control==224){
            control=getch();
            if (control==72) { // ������� ��������� �����; �������
            Bullets[0].direction = 'N';
            }
            if (control == 77) { // ������� ��������� ������; �������
            Bullets[0].direction = 'E';
            }
            if (control ==80){ // ������� ��������� ����; �������
            Bullets[0].direction = 'S';
            }
            if (control==75){ // ������� ��������� �����; �������
            Bullets[0].direction = 'W';
            }

            Bullets[0].x = Tanks[0].x;
            Bullets[0].y = Tanks[0].y;

            Bullets[0].velocity = 1;
            Bullets[0].damage = 1;
            printf("\nx:\t%d\ty:\t%d\tvelocity:\t%d", Bullets[0].x, Bullets[0].y, Bullets[0].velocity == 0);
        }


        /*
            ��������� ��� ���������� �������� (���� �� 1 ������)
        */
        if (Bullets[0].velocity != 0) {

            Map[Bullets[0].x][Bullets[0].y] = ' ';
            if (Bullets[0].direction=='N') {
                Bullets[0].x = Bullets[0].x-1;
            }
            if (Bullets[0].direction=='W') {
                Bullets[0].y = Bullets[0].y - 1;
            }
            if (Bullets[0].direction=='S') {
                Bullets[0].x = Bullets[0].x + 1;
            }
            if (Bullets[0].direction=='E') {
                Bullets[0].y = Bullets[0].y + 1;
            }
            Map[Bullets[0].x][Bullets[0].y] = 'B';
        }


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



        Sleep (tickDuration);
        system("cls");
    }

}

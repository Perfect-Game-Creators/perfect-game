#include "MyFunctions.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define sizeOfMap 10
#define numberOfBullets 10
#define tickDuration 60 //���������� � ������������
#define numberOfTanks 2

struct bullet {
    int x;
    int y;
    char direction; // ����� - 'N'   ����� - 'W'   �� - 'S'  ������ - 'E'
    int velocity;   // �������, ��� ���� �������� �������, �� ������� �� ���������� (�� ������ ���)
    int damage;
};

struct tank {
        int x;
        int y;
        int HP;
    };


int move (int*x, int*y, int direction) {

    if (direction=='N') {
        *x=*x-1;
    }
    if (direction=='S') {
        *x=*x+1;
    }
    if (direction=='W') {
        *y=*y-1;
    }
    if (direction=='E') {
        *y=*y+1;
    }

    if (*x<0) {
        *x=sizeOfMap-1;
    }
    if (*x>=sizeOfMap) {
        *x=0;
    }
    if (*y<0) {
        *y=sizeOfMap-1;
    }
    if (*y>=sizeOfMap) {
        *y=0;
    }

    return (0);
}

int DrawMap (char** Map) {

    int i, j;
    for(i=0; i<sizeOfMap; i++){
        for(j=0; j<sizeOfMap;j++){
            printf("%c", Map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}



int mainLoop(char** Map, struct tank * Tanks, struct bullet * Bullets){
     int control; // ����� �������� ����� ��������� �������
     int i;
     int CounterOfBullets;
     CounterOfBullets = 0;
     int *x, *y; // ������ �� �����-�� ��� ���������� - ����������, �������� ��� ��������


     while (1) {





        /*
            ��������� �����
        */

        ////////////////////////////////////////////// InputProcessing();
        // 0. �����������, ������ �� �������, � ���� ��, �� ��������� ��������
        if (kbhit ()) { // KeyBoard Hit
                        // ���������� 1, ���� ������ �����-�� �������
                        // ���������� 0, ���� ������ �� ������
                control=getch();
        }
        //��������� �����

        Map[Tanks[1].x][Tanks[1].y] = ' ';
        x = &Tanks[1].x;
        y = &Tanks[1].y;
        move(x, y, 'N');
        Map[*x][*y] = 'E';
        ///////////////////////////////////////////////////////



        // 1. ����������� ������
        ////////////////////////////////////// PlayerMoving();
        Map[Tanks[0].x][Tanks[0].y] = ' ';
        x = &Tanks[0].x;
        y = &Tanks[0].y;
        if (control==119){ // ������� ������� "W"; �������� �����
            move(x, y, 'N');
        }
        if (control==97){ // ������� ������� "A"; �������� �����
            move(x, y, 'W');
        }
        if (control==115) { // ������� ������� "S"; �������� ����
            move(x, y, 'S');
        }
        if (control==100){ // ������� ������� "D"; �������� ������
            move(x, y, 'E');
        }
        Map[*x][*y] = 'T';
        //printf("x: %d\ty: %d\n", Tanks[0].x, Tanks[0].y);
        //////////////////////////////////////////////////






        // 2. ������� ������
        ///////////////////////////////////// PlayerShooting();
        if  (control==224){
            control=getch();
            if (control==72) { // ������� ��������� �����; �������
            Bullets[CounterOfBullets].direction = 'N';
            }
            if (control == 77) { // ������� ��������� ������; �������
            Bullets[CounterOfBullets].direction = 'E';
            }
            if (control ==80){ // ������� ��������� ����; �������
            Bullets[CounterOfBullets].direction = 'S';
            }
            if (control==75){ // ������� ��������� �����; �������
            Bullets[CounterOfBullets].direction = 'W';
            }

            Bullets[CounterOfBullets].x = Tanks[0].x;
            Bullets[CounterOfBullets].y = Tanks[0].y;

            Bullets[CounterOfBullets].velocity = 1;
            Bullets[CounterOfBullets].damage = 1;
            //printf("\nx:\t%d\ty:\t%d\tvelocity:\t%d\tx:\t%d\ty:%d\t\n", Bullets[CounterOfBullets].x, Bullets[CounterOfBullets].y, Bullets[CounterOfBullets].velocity == 0, Tanks[0].x, Tanks[0].y);
            CounterOfBullets = CounterOfBullets+1;
        }
        ////////////////////////////////////////////////////




        /*
            ��������� ��� ���������� �������� (���� �� 1 ������)
        */
        /////////////////////////////// MoveBullets();
        for (i=0; i<numberOfBullets; i++) {
            if (Bullets[i].velocity != 0) {

                Map[Bullets[i].x][Bullets[i].y] = ' ';
                x = &Bullets[i].x;
                y = &Bullets[i].y;
                move(x, y, Bullets[i].direction);
                Map[*x][*y] = 'B';

            //printf("x:\t%d\ty:\t%d\tvelocity:\t%d\tnumber:\t%d\n", Bullets[i].x, Bullets[i].y, Bullets[i].velocity, i);
            }
        }
        ////////////////////////////////////






        //����� �� ������� ~ ��� `
        /////////////////////////////////////////// InputProcessing();
        if ( (control==96)||(control==126) ){
            return (0);

        }
        control=0;

        DrawMap(Map);

        Sleep (tickDuration);
        system("cls");
    }

}
        //////////////////////////////////////////////////////////

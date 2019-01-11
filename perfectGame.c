#include <stdio.h> //STanDart Input-Output
#include <windows.h>
#include <conio.h>
#include <stdlib.h> //STanDart LIBrary
#include "MyFunctions.h"


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

int main () {

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
    Tanks[0].x = sizeOfMap/4;
    Tanks[0].y = sizeOfMap/4;
    Tanks[0].HP = 3;
    Map[Tanks[0].x][Tanks[0].y] = 'T';

    Tanks[1].x = sizeOfMap/2;
    Tanks[1].y = sizeOfMap/2;
    Tanks[1].HP = 3;
    Map[Tanks[1].x][Tanks[1].y] = 'E';


    mainLoop(Map, Tanks, Bullets);
}

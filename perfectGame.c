#include <stdio.h> //STanDart Input-Output
#include <windows.h>
#include <conio.h>
#include <stdlib.h> //STanDart LIBrary
#include "MyFunctions.h"


#define numberOfBullets 10
#define sizeOfMap 10
#define tickDuration 60 //Измеряется в милисекундах
#define numberOfTanks 2

struct tank {
        int x;
        int y;
        int HP;
    };

struct bullet {
    int x;
    int y;
    char direction; // север - 'N'   запад - 'W'   юг - 'S'  восток - 'E'
    int velocity;   // Считаем, что если скорость нулевая, то снаряда не существует (не рисуем его)
    int damage;
};

int main () {

    int i, j; // Счётчики кругов цикла
    char **Map; // Двухмерный массив (таблица) символов
    struct tank *Tanks;
    struct bullet *Bullets;


    // Выделяем память под танки
    Tanks = (struct tank*)malloc(sizeof(struct tank) * numberOfTanks);
    // Выделяем память под снаряды
    Bullets = (struct bullet*)malloc(sizeof(struct bullet) * numberOfBullets);
    // Выделяем память под карту
    for (i=0; i<sizeOfMap; i++){
        Map = (char**)malloc(sizeof(char*)*sizeOfMap);
        for (j=0; j<sizeOfMap; j++){
            Map [j]=(char*)malloc(sizeof(char)*sizeOfMap);
        }
    }


    // Сразу объявляем все снаряды несуществующими, то есть, зануляем скорость
    for (i = 0; i < numberOfBullets; i++) {
        Bullets[i].velocity = 0;
        //printf("%d\t%d\n", i, D[i]);
    }

    // Заполняем все клетки карты пробелами
    for (i=0; i<sizeOfMap; i++) {
        for (j=0; j<sizeOfMap; j++) {
            Map [i][j]=' ';
            //printf("%d\t%d\t%d\n", i, j, Map[i][j]);
        }
    }
    // Обозначаем начальное положение танка игрока
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

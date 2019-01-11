#include <stdio.h> //STanDart Input-Output
#include <windows.h>
#include <conio.h>
#include <stdlib.h> //STanDart LIBrary

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

int move (int*x, int*y, int direction) {

    if direction=='N'

    return (0);
}
int main () {

    int control; // Здесь хранится номер считанной клавиши
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
    Tanks[0].x = sizeOfMap/2;
    Tanks[0].y = sizeOfMap/2;
    Tanks[0].HP = 3;
    Map[Tanks[0].x][Tanks[0].y] = 'T';


    // Приготовления завершены, запускаем цикл игры
    while (1) {

        /*
            Обработка ввода
        */

        // 0. Отлавливаем, нажата ли клавиша, и если да, то считываем значение
        if (kbhit ()) { // KeyBoard Hit
                        // возвращает 1, если нажата какая-то клавиша
                        // возвращает 0, если ничего не нажато
                control=getch();
        }
        //Обработка ввода

        // 1. Перемещение игрока
        Map[Tanks[0].x][Tanks[0].y] = ' ';
        if (control==119){ // Нажатие клавиши "W"; движение вверх
            Tanks[0].x = Tanks[0].x - 1;
        }
        if (control==97){ // Нажатие клавиши "A"; движение влево
            Tanks[0].y = Tanks[0].y - 1;
        }
        if (control==115) { // Нажатие клавиши "S"; движение вниз
            Tanks[0].x = Tanks[0].x + 1;
        }
        if (control==100){ // Нажатие клавиши "D"; движение вправо
            Tanks[0].y = Tanks[0].y + 1;
        }
        Map[Tanks[0].x][Tanks[0].y] = 'T';
        printf("x: %d\ty: %d\n", Tanks[0].x, Tanks[0].y);

        // 2. Выстрел игрока
        if  (control==224){
            control=getch();
            if (control==72) { // Нажатие стрелочки вверх; выстрел
            Bullets[0].direction = 'N';
            }
            if (control == 77) { // Нажатие стрелочки вправо; выстрел
            Bullets[0].direction = 'E';
            }
            if (control ==80){ // Нажатие стрелочки вниз; выстрел
            Bullets[0].direction = 'S';
            }
            if (control==75){ // Нажатие стрелочки влево; выстрел
            Bullets[0].direction = 'W';
            }

            Bullets[0].x = Tanks[0].x;
            Bullets[0].y = Tanks[0].y;

            Bullets[0].velocity = 1;
            Bullets[0].damage = 1;
            printf("\nx:\t%d\ty:\t%d\tvelocity:\t%d", Bullets[0].x, Bullets[0].y, Bullets[0].velocity == 0);
        }


        /*
            Обработка уже движущихся снарядов (пока их 1 только)
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


        //Выход по нажатию ~ или `
        if ( (control==96)||(control==126) ){
            return (0);
        }
        control=0;


        // Отрисовка карты
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

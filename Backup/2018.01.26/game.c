#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#define numberOfBullets 10
#define sizeOfMap 10
#define tickDuration 60 //Измеряется в милисекундах

int main () {

    int control;
    int i, j;
    int x = sizeOfMap/2, y=sizeOfMap/2, HP=3;
    int *X;
    int *Y;
    int *D;
    char **Map;

    X = (int*)malloc(sizeof(int)*numberOfBullets);
    Y = (int*)malloc(sizeof(int)*numberOfBullets);
    D = (int*)malloc(sizeof(int)*numberOfBullets);

    for (i=0; i<numberOfBullets; i++) {
        D[i]=0;
        //printf("%d\t%d\n", i, D[i]);
    }
    for (i=0; i<sizeOfMap; i++){
        Map = (char**)malloc(sizeof(char*)*sizeOfMap);
        for (j=0; j<sizeOfMap; j++){
            Map [j]=(char*)malloc(sizeof(char)*sizeOfMap);
        }
    }


    for (i=0; i<sizeOfMap; i++) {
        for (j=0; j<sizeOfMap; j++) {
            Map [i][j]=' ';
            //printf("%d\t%d\t%d\n", i, j, Map[i][j]);
        }
    }

    Map[x][y] = 'T';

    while (1) {
        if (kbhit ()) {
                control=getch();
        }
        //Обработка ввода
        Map[x][y] = ' ';
        if (control==119){
            x=x-1;
        }
        if (control==97){
            y=y-1;
        }
        if (control==115) {
            x=x+1;
        }
        if (control==100){
            y=y+1;
        }
        Map[x][y] = 'T';


        if ( (control==96)||(control==126) ){
            return (0);
        }
        control=0;

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
        system("cls");
    }

}

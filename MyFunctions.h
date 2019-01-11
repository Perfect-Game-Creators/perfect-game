#ifndef MyFuntions_H_
#define MyFuntions_H_

typedef struct tank tank;
typedef struct bullet bullet;

int move (int*x, int*y, int direction);
int mainLoop(char** Map, struct tank * Tanks, struct bullet * Bullets);
int DrawMap (char** Map);

#endif // MyFuntions_H_

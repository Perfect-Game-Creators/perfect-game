#include "MyFunctions.h"
#define sizeOfMap 10

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

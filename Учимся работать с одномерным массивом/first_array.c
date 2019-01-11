#include <stdio.h>
#include <stdlib.h>
#define sizeOfMap 10
#define interestingNumber -13
int main () {

    int *X;


    X = (int*)malloc(sizeof(int)*sizeOfMap);
    scanf("%d", &X[interestingNumber]);
    printf("%d", X[interestingNumber]);
    return (0);
}

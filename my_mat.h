#ifndef MY_MAT
#define MY_MAT

#include <stdbool.h>

int** inputMatrix();

bool hasPath(int** mat, int i, int j);

int shortestPath(int** mat, int i, int j);


#endif
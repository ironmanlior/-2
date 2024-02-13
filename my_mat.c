#include "my_mat.h"

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define V 10

int** inputMatrix(){
	int input;
	int** mat = (int**)malloc(V * sizeof(int*));
	for(int i = 0; i < V; i++) {
		mat[i] = (int*)malloc(V * sizeof(int));
		for (int j = 0; j < V; j++) {
			//printf("Enter value for mat[%d][%d]: ", i, j);
			scanf("%d", &input);
			mat[i][j] = input;
		}
	}


	return mat;
}

bool hasPath(int** mat, int i, int j){
	return shortestPath(mat, i, j) != -1;
}

int shortestPath(int** mat, int i, int j){
	if (i == j) return 0;
	int dist[V]; 
    bool sptSet[V]; 
    for (int v = 0; v < V; v++)
        dist[v] = INT_MAX, sptSet[v] = false;
 
    dist[i] = 0;
	sptSet[i] = true;
 
    for (int count = 0; count < V - 1; count++) {
		int min = INT_MAX, u;
 
		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], u = v;

        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && mat[u][v] && dist[u] != INT_MAX && dist[u] + mat[u][v] < dist[v])
                dist[v] = dist[u] + mat[u][v];
    }
	return dist[j] == INT_MAX ? -1 : dist[j];
}
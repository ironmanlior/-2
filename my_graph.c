#include "my_mat.h"

#include <stdio.h>
#include <stdbool.h>

int main() {
	int** mat;
	char input[1];
	int i, j;

	while (true) {
		printf("Enter a letter from A to D: ");
		scanf("%s", input);


		if (input[0] == 'A') mat = inputMatrix(mat);
		else if (input[0] == 'B') {
			printf("i: ");
			scanf("%d", &i);
			printf("j: ");
			scanf("%d", &j);
			printf("%s", hasPath(mat, i, j) ? "true" : "false");
		}
		else if (input[0] == 'C') {
			printf("i: ");
			scanf("%d", &i);
			printf("j: ");
			scanf("%d", &j);
			printf("%d", shortestPath(mat, i, j));
		}
		else break;
	}
}
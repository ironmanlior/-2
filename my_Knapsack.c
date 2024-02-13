#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_WEIGHT 20
#define LENGTH 5

#define max(a,b) (((a) > (b)) ? (a) : (b))


int knapSack (int weights[], int values[] , int selected_bool[]);

int knapSack (int weights[], int values[] , int selected_bool[]) {
	
	int i, w; 
    int K[LENGTH + 1][MAX_WEIGHT + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= LENGTH; i++) { 
        for (w = 0; w <= MAX_WEIGHT; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    }

	int res = K[LENGTH][MAX_WEIGHT];
	w = MAX_WEIGHT;
    for (i = LENGTH; i > 0 && res > 0; i--) {
        if (res == K[i - 1][w]) continue;        
        else {
            selected_bool[i - 1] = 1;
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }

    return K[LENGTH][MAX_WEIGHT];

}

int main() {
	char* items[LENGTH];
	int weights[LENGTH];
	int values[LENGTH];
	int selected_bool[LENGTH] = {0, 0, 0, 0, 0};

	for (int i = 0; i < LENGTH; i++){
		char* name = (char*)malloc(256 * sizeof(char));
		int weight, value;
		printf("input item name: ");
		scanf("%s", name);
		printf("input value: ");
		scanf("%d", &value);
		printf("input weight: ");
		scanf("%d", &weight);

		items[i] = name;
		weights[i] = weight;
		values[i] = value;
	}

	printf("\nmaximum profit: %d\n", knapSack(weights, values, selected_bool));

	for (int i = 0; i < LENGTH; i++) 
		if (selected_bool[i] == 1)
			printf("%s, ", items[i]);

	return 0;
}
CC = gcc
LIB_FILES_GRAPH = my_mat.o
OBJ_REC = basicClassification.o advancedClassificationRecursion.o

all: my_graph my_Knapsack

my_Knapsack: my_Knapsack.o
	$(CC) -o my_Knapsack my_Knapsack.o


my_graph: my_graph.o my_mat.a
	$(CC) -o my_graph my_graph.o my_mat.a


my_mat.a: my_mat.o
	ar rc my_mat.a my_mat.o
	rm -f my_mat.o

my_mat.o: my_mat.c my_mat.h
	$(CC) -Wall -fPIC -c my_mat.c

my_graph.o: my_graph.c my_mat.h
	$(CC) -Wall -c my_graph.c

my_Knapsack.o: my_knapsack.c
	$(CC) -Wall -c my_knapsack.c
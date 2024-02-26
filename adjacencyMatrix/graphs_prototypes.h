#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int nodes;
    int arc;
    int **adj;
} Graph;

Graph* createNewGraph(int nodes);
int** createNewMatrix(int nodes, int value);
void startMatrixValues(int** matrix, int value, int nodes);
void insertNewArc(Graph* graph, int vertex1, int vertex2);
void deleteArc(Graph* graph, int vertex1, int vertex2);
void printGraph(Graph* graph);
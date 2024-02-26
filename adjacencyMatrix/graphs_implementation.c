#include "graphs_prototypes.h"

Graph* createNewGraph(int nodes) {
    Graph* newGraph = malloc(sizeof(Graph));
    newGraph->nodes = nodes;
    newGraph->arc = 0;
    newGraph->adj = createNewMatrix(nodes, 0);

    return newGraph;
}

int** createNewMatrix(int nodes, int value) {
    int **matrix = malloc(sizeof(int *) * nodes);
    
    for (int i = 0; i < nodes; i++) {
        matrix[i] = malloc(sizeof(int) * nodes);
    }

    startMatrixValues(matrix, value, nodes);

    return matrix;
}

void startMatrixValues(int** matrix, int value, int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            matrix[i][j] = value;
        }
    }
}

void insertNewArc(Graph* graph, int vertex1, int vertex2) {
    if (graph->adj[vertex1][vertex2] == 0) {
        graph->adj[vertex1][vertex2] = 1;
        graph->arc++;
    }
}

void deleteArc(Graph* graph, int vertex1, int vertex2) {
    if (graph->adj[vertex1][vertex2] == 1) {
        graph->adj[vertex1][vertex2] = 0;
        graph->arc--;
    }
}

void printGraph(Graph* graph) {

    int size = graph->nodes;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %2d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}
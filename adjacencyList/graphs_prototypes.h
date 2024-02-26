#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int node;
    struct node *next;
} Node;

typedef struct graph {
    int nodes;
    int arcs;
    Node **adj;
} Graph;

Graph *createNewGraph(int nodes);
Node *createNewNode(int vertex, Node *next);
void insertNewArc(Graph *graph, int vertex1, int vertex2);
void printGraph(Graph *graph);
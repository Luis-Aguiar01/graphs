#include "graphs_prototypes.h"

Graph *createNewGraph(int nodes) {
    Graph *newGraph = malloc(sizeof(Graph));
    newGraph->nodes = nodes;
    newGraph->arcs = 0;
    newGraph->adj = malloc(sizeof(Node *) * nodes);
    
    for (int i = 0; i < nodes; i++) {
        newGraph->adj[i] = NULL;
    }
    
    return newGraph;
}

Node *createNewNode(int vertex, Node *next) {
    Node *newNode = malloc(sizeof(Node));
    newNode->node = vertex;
    newNode->next = next;
    
    return newNode;
}

void insertNewArc(Graph *graph, int vertex1, int vertex2) {
    Node *currentNode = graph->adj[vertex1];

    while (currentNode != NULL) {
        if (currentNode->node == vertex2) return;
        currentNode = currentNode->next;
    }

    graph->adj[vertex1] = createNewNode(vertex2, graph->adj[vertex1]);
    graph->arcs++;
}

void printGraph(Graph *graph) {

    int size = graph->nodes;
    Node *currentNode = NULL;

    for (int i = 0; i < size; i++) {
        currentNode = graph->adj[i];
        printf("%d: ", i);

        while (currentNode != NULL) {
            printf("%d -> ", currentNode->node);
            currentNode = currentNode->next;
        }
        printf("NULL\n");
    }
}
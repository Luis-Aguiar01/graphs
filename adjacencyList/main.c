#include "graphs_prototypes.h"

int main(void) {
    Graph *myGraph = createNewGraph(5);
    insertNewArc(myGraph, 1, 2);
    printGraph(myGraph);
}
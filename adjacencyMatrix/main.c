#include "graphs_prototypes.h"

int main(void) {
    Graph *myGraph = createNewGraph(5);
    insertNewArc(myGraph, 1, 2);
    insertNewArc(myGraph, 3, 4);
    insertNewArc(myGraph, 3, 2);
    deleteArc(myGraph, 3, 2);
    printGraph(myGraph);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int id;
    int custo; 
    struct vertice *next;
} Vertice;

typedef struct graph {
    int numVertices;
    Vertice **adjacencyList;
} Graph;

typedef struct nodeQueue {
    int id;
    int custo;
} NodeQueue;

typedef struct priorityQueue {
    int size;
    NodeQueue *heap;
} PriorityQueue;

Graph *createGraph(int numVertices);
void addAresta(Graph *g, int origem, int destino, int custo);
void printGraph(Graph *g);
int compareQueueNodes(const void *a, const void *b);
PriorityQueue *createPriorityQueue(int numVertices);
void enqueue(PriorityQueue *pq, int id, int custo);
NodeQueue dequeue(PriorityQueue *pq);
void dijkstra(Graph *g, int origem);

int main() {
    
    Graph *g = createGraph(5);
    
    addAresta(g, 0, 1, 2);
    addAresta(g, 0, 2, 3);
    addAresta(g, 1, 2, 4);
    addAresta(g, 1, 3, 5);
    addAresta(g, 2, 3, 1);
    addAresta(g, 2, 4, 6);
    addAresta(g, 3, 4, 7);

    printGraph(g);

    dijkstra(g, 0);

    return 0;
}

Graph *createGraph(int numVertices) {
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->numVertices = numVertices;
    g->adjacencyList = (Vertice **) malloc(sizeof(Vertice *) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        g->adjacencyList[i] = NULL;
    }
    return g;
}

void addAresta(Graph *g, int origem, int destino, int custo) {
    // Define os valores dos atributos da nova aresta, sendo o id o seu vértice
    // de destino.
    Vertice *newVertice = (Vertice *) malloc(sizeof(Vertice));
    newVertice->custo = custo;
    newVertice->id = destino;
    newVertice->next = NULL;

    // Adiciona a nova aresta em uma lista encadeada, a partir do vértice de origem.
    Vertice *aux = g->adjacencyList[origem];
    if (aux == NULL) {
        g->adjacencyList[origem] = newVertice;
    }
    else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newVertice;
    }
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertice %d: ", i);
        Vertice *aux = g->adjacencyList[i];
        
        while (aux != NULL) {
            printf("%d(%d) ", aux->id, aux->custo);
            aux = aux->next;
        }
        
        printf("\n");
    }
}

// É necessário fornecer a implementação de uma função para usar o algoritmo de ordenação
// qsort da biblioteca stdlib. A função deve retornar um número positivo, caso o primeiro
// elemento seja maior do que o segundo, um número negativo, caso o segundo elemento seja
// maior do que o primeiro, ou zero, caso os elementos sejam iguais.
int compareQueueNodes(const void *a, const void *b) {
    NodeQueue *node1 = (NodeQueue *)a;
    NodeQueue *node2 = (NodeQueue *)b;
    
    return node1->custo - node2->custo;
}

PriorityQueue *createPriorityQueue(int numVertices) {
    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->heap = (NodeQueue *) malloc(sizeof(NodeQueue) * numVertices);
    return pq;
}

// Adiciona um novo elemento a lista, a partir do seu tamanho, que inicialmente é 0.
void enqueue(PriorityQueue *pq, int id, int custo) {
    NodeQueue node;
    node.id = id;
    node.custo = custo;
    pq->heap[pq->size] = node;
    pq->size++;
    qsort(pq->heap, pq->size, sizeof(NodeQueue), compareQueueNodes);
}

// Retira um elemento da lista de prioridade, diminuindo o tamanho da lista, quando um próximo
// elemento for adicionado, ele sobrescreverá a elemento retirado.
NodeQueue dequeue(PriorityQueue *pq) {
    return pq->heap[--pq->size];
}

void dijkstra(Graph *g, int origem) {
    // O array dist representa a distancia de todos os vértices em relação a um vértice
    // origem. No caso, todos os vértices são inicializados como infinito positivo, apenas
    // o próprio vértice de origem é inicializado como sendo 0, representando a sua distância
    // até ele mesmo.
    int dist[g->numVertices];
    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = __INT_MAX__;
    }

    dist[origem] = 0;

    // Uma fila de prioridade é criada, com a quantidade de elementos igual a quantidade de vértices
    // do grafo. O vértice de origem é o primeiro adicionado a lista.
    PriorityQueue *pq = createPriorityQueue(g->numVertices);
    enqueue(pq, origem, 0);

    while (pq->size > 0) {
        NodeQueue node = dequeue(pq);
        int u = node.id;

        Vertice *aux = g->adjacencyList[u];
        while (aux != NULL) {
            int v = aux->id;
            int weight = aux->custo;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                enqueue(pq, v, dist[v]);
            }
            aux = aux->next;
        }
    }

    for (int i = 0; i < g->numVertices; i++) {
        printf("Distancia da origem ate o vertice %d: %d\n", i, dist[i]);
    }
}
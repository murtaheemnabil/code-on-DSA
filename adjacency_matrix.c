#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
    int numVertices;
    int** adjMatrix;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;
    }
}

void removeEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 0;
        graph->adjMatrix[dest][src] = 0;
    }
}

void printGraph(Graph* graph) {
    printf("\nAdjacency Matrix (%d x %d):\n\n", graph->numVertices, graph->numVertices);

    printf("    ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n   ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d | ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}
void freeGraph(Graph* graph) {
    if (!graph) return;

    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    freeGraph(graph);

    return 0;
}

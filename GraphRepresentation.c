#include <stdio.h>
#include <stdlib.h>

//Representation Of Graph

//A structure to represent an adjacency list node
typedef struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
} AdjListNode;

//A structure to represent a n adjacency list
typedef struct AdjList
{
    AdjListNode *head;
} AdjList;

//A structure to represent graph .A graph
//is an array of adjacency lists.
//Size of Array will be V(number of vertices in graph)
typedef struct Graph
{
    int V;
    AdjList *array;
} Graph;

//A utility function to create a new adjacency list node
AdjListNode *newAdjListNode(int dest)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
};

//A utility function that creates a grph of V vertices
Graph *createGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList *)malloc(V * sizeof(AdjList));
    int i;
    for (i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
    }
    return graph;
};
void addEdge(Graph *graph, int src, int dest)
{
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
};
void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("->%d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    /*   int V = 5;
    Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);*/

     return 0;
}
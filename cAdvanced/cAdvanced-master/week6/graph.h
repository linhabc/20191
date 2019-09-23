#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct{
  int *matrix; //= m[sizemax][sizemax]
  int sizemax;
}Graph;


Graph creatGraph(int sizemax);
void addEdge(Graph* graph, int v1, int v2);
int adjancent(Graph* graph, int v1, int v2);
int getAdjacentVertices(Graph* graph, int vertex, int* output);
//return the number of adjacent vertices
void printGraph(Graph graph);
void dropGraph(Graph* graph);

#endif

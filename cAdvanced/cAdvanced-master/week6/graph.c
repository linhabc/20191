#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph creatGraph(int sizemax){
  Graph newGraph;
  newGraph.sizemax = sizemax;

  newGraph.matrix = (int*)malloc(sizeof(int)*(sizemax*sizemax));
  for(int i;i<sizemax; i++){
    for(int j=0; j<sizemax; j++){
      newGraph.matrix[i][j] = 0;
    }
  }
  return newGraph;
}

void addEdge(Graph* graph, int v1, int v2){
  graph->matrix[v1][v2] = 1;
  graph->matrix[v2][v1] = 1;
}

int adjancent(Graph* graph, int v1, int v2){
  return graph->matrix[v1*graph->sizemax+v2];
}

void printGraph(Graph graph){
  for(int i;i<graph.sizemax; i++){
    for(int j=0; j<graph.sizemax; j++){
      printf("%d ", graph.matrix[i][j]);
    }
    pritnf("\n");
  }
}

int getAdjacentVertices(Graph* graph, int vertex, int* output){


}

void dropGraph(Graph* graph){


}

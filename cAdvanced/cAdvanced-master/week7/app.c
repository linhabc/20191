#include <stdio.h>
#include "graphJRB.h"

void printVertex(int v) {
  printf("%-4d", v);
}

int main(){
  int total, adj[10];
  Graph graph;
  graph = createGraph();

  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 5);
  addEdge(graph, 3, 1);

  printGraph(graph);
  

  printf("%d \n", adjacent(graph, 1, 2));
  printf("%d \n", adjacent(graph, 3, 2));
  printf("%d \n", adjacent(graph, 1, 5));


  total = getAdjacentVertices(graph, 1, adj);
  printf("total: %d\n", total);
  printf("Adjacent of v1: ");
  for(int i=0; i<total; i++){
    printf("%d ", adj[i]);
  }
  printf("\nBFS\n");
  BFS(graph, 1, -1, printVertex);
  printf("\n");

  printf("\nDFS\n");
  DFS(graph, 1, -1, printVertex);

  dropGraph(graph);
  printf("\n");
  return 0;
}

    

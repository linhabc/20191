#include <stdio.h>
#include "graphJRB.h"

int main(){
  Graph graph;
  graph = createGraph();

  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 5);
  addEdge(graph, 3, 1);

  printGraph(graph);
  dropGraph(graph);
  return 0;
}

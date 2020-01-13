#include "main.h"

int main(){
  int op;
  int numberOfVertices, numberOfEdges;
  Distances* distances = (Distances*)malloc(sizeof(Distances)*100);
  Graph g = createGraph();
  readDistanceFile("dothi.txt", distances, &numberOfEdges, &numberOfVertices);
  readInGraph(g, distances, numberOfEdges);


  do{
    printf("----------------------\n");
    printf("MENU\n");
    printf("1. Read file and print matrix\n");
    printf("2. Print castle\n");
    printf("3. List of castle\n");
    printf("4. \n");
    printf("5. \n");
    printf("6. Exit\n");
    do{
      printf("Enter: ");
      scanf(" %d", &op);
    }while(op> 6 || op<1);

    switch(op){
      case  1:
        printMatrix(g, numberOfVertices);
        break;

      case  2:
        printGraph(g);
        break;

      case  3:
        justWalkToCastle(g);
        maxInDegreeCastle(g);
        break;

      case  4:

        break;

      case  5:

        break;
    }
    
  }while(op != 5);
    
  return 0;
}

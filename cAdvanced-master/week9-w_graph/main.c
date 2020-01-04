#include "weighted_graph.h"

//check if exist in graph


//undirected
void shortest_path(Graph g){
    int v1, v2, i, path[100], length;
    printf("\nEnter v1: ");
    scanf("%d",  &v1);
    printf("\nEnter v2: ");
    scanf("%d",  &v2);
    double w = shortestPath(g, v1, v2, path, &length);
    if (w == INFINITIVE_VALUE) {
         printf("No path from %s to %s\n", getVertex(g, v1), getVertex(g, v2));
    } else {
         printf("Path from %s to %s (with total distance %lf)\n", getVertex(g, v1), getVertex(g, v2), w);
         for (i=0; i<length; i++)
             printf(" => %s", getVertex(g, path[i]));
    }
}

void print_bfs(Graph g){
    int v1, v2;
    printf("\nEnter v1: ");
    scanf("%d",  &v1);
    printf("\nEnter v2: ");
    scanf("%d",  &v2);
    BFS_checkExist(g, v1, v2, printVertex);
}

void print_dfs(Graph g){
    int v1, v2;
    printf("\nEnter v1: ");
    scanf("%d",  &v1);
    printf("\nEnter v2: ");
    scanf("%d",  &v2);
    DFS(g, v1, v2, printVertex);
}

//directed
void print_topo(Graph g){
    int n, output[100], i;
    if(DAG(g)){  //if is directed acylic graph
        n = topologicalSort(g, output);
        printf("\nThe topological order: ");
        for (i=0; i<n; i++){
            printf("%s-->", getVertex(g, output[i]));
            // printf("%5d", output[i]);
        }
    } else {
        printf("Can not make topological sort\n"); 
    }
}

void check_cycle(Graph g){
    if(DAG(g)){ 
        printf("\nDAG");
    } else {
        printf("\nNot DAG"); 
    }
}

void check_adjacent(Graph g){
    int v1, v2;
    printf("\nEnter v1: ");
    scanf("%d",  &v1);
    printf("\nEnter v2: ");
    scanf("%d",  &v2);
    if(hasEdge(g, v1, v2)){ 
        printf("\nAdjacent");
    } else {
        printf("\nNot Adjacent"); 
    }
}

int main(int argc, char const *argv[])
{
    ///////////////DECLARE VARIABLES
	Graph g = createGraph();
	int matrix[10][10];
    addVertex(g, 0, "V0");
    addVertex(g, 1, "V1");
    addVertex(g, 2, "V2");
    addVertex(g, 3, "V3");

    addVertex(g, 4, "V4");
    addEdge(g, 0, 1, 1);
    addEdge(g, 1, 2, 1);
    // addEdge(g, 2, 0, 1);
    addEdge(g, 0, 2, 3);
    addEdge(g, 1, 3, 1);
    addEdge(g, 3, 2, 1);

    addEdge(g, 4, 0, 3);
    addEdge(g, 4, 1, 5);
	//////////////// CHECK FILE
    // if(argc != 2){
    // 	printf("Error: Wrong number of arguments!\n");
    // 	exit(1);
    // }
    // FILE *fin = fopen(argv[1],"r");
    // if(fin == NULL){
    //     printf("\nError: Input file doesn't exist!\n");
    //     return 0;
    // }

    ///////////////// GET INPUT
    
    ////////////////// MENU
    int opt;
    do {
    	printf("\n--------MENU---------");
	    printf("\n1. shortest_path");
	    printf("\n2. print_bfs");
	    printf("\n3. print_dfs");
	    printf("\n4. print_topo");
	    printf("\n5. check_cycle");
	    printf("\n6. Exit");
        printf("\n7. check_adjacent");
	    printf("\nYou choose...");

	    if (scanf("%d", &opt) != 1){
	        printf("\nError: Undefined Value (not integer)");
	        scanf ("%*c");
	        continue;
	    }
        switch(opt){
            case 1:
            shortest_path(g);
            break;
            case 2:
            print_bfs(g);
            break;
            case 3:
            print_dfs(g);
            break;
            case 4:
            print_topo(g);
            break;
            case 5:
            check_cycle(g);
            break;
            case 7:
            check_adjacent(g);
            break;
            case 6:
            printf("\nExit\n");
            break;
            default:
            printf("\nError: Undefined Value!"); 
            break;
        }       
    } while (opt != 6);
	return 0;
}
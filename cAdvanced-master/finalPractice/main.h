#include <stdio.h>
#include <stdlib.h>
#include "weighted_graph.h"

typedef struct {
    int vertex1;
    int vertex2;
    double distance;
} Distances;

void readDistanceFile(char * filename, Distances distances[], int* numberOfEdges, int* numberOfVertices){
    FILE* fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Cannot open file!");
        exit(1);
    }

    fscanf(fp, "%d  %d", numberOfVertices, numberOfEdges);
    printf("%d %d\n", *numberOfVertices, *numberOfEdges);
    
    for(int i=0; i<*numberOfEdges; i++){
        fscanf(fp, "%d %d %lf", &distances[i].vertex1, &distances[i].vertex2, &distances[i].distance);
    }
}

void printMatrix(Graph g, int numberOfVertices){
    JRB node, nodeVal, tmp;
    int flag=0;
    jrb_traverse(node, g. edges){
        nodeVal = (JRB)jval_v(node->val);
        for(int i=1; i<=numberOfVertices; i++){
            jrb_traverse(tmp, nodeVal){
                if(jval_i(tmp->key) == i){
                    printf("%.0lf ", jval_d(tmp->val));
                    flag = 1;
                }
            }
            if(flag == 0) printf("0 ");
            flag = 0;
        }
        printf("\n");
    }
}

void readInGraph(Graph g, Distances distances[], int numberOfVertices){
    for(int i=0; i < numberOfVertices; i++){
        printf("%d %d %.0lf\n", distances[i].vertex1, distances[i].vertex2, distances[i].distance);

        addVertex(g, distances[i].vertex1, &distances[i].vertex1);
        addVertex(g, distances[i].vertex2, &distances[i].vertex2);
        addEdgeUndirec(g, distances[i].vertex1, distances[i].vertex2, distances[i].distance);
    }
}

void printGraph(Graph g){
    JRB node, nodeVal, tmp;
    // jrb_traverse(node, g.vertices){
    //     printf("%d- %d \n", jval_i(node->val), jval_i(node->key));
    // }

    jrb_traverse(node, g.edges){
        printf("Castle %d :", jval_i(node->key));
        nodeVal = (JRB) jval_v(node->val);
        jrb_traverse(tmp, nodeVal){
            printf("%d ", jval_i(tmp->key));
        }
        printf("\n");
    }
}

void justWalkToCastle(Graph g){
    JRB node;

    int castles[100];
    int indegreeCastle[100];
    int n, j=0, flag=0;

    jrb_traverse(node, g.vertices){
        n = indegree(g, jval_i(node->key), indegreeCastle);
        // printf("%d-node ", node->key);

        for(int i=0; i<n; i++){
            // printf("%d ", indegreeCastle[i]);
            if(getEdgeValue(g, jval_i(node->key),indegreeCastle[i]) < 50){
                flag = 1;
                break;
            }
        }
        if(flag == 0) castles[j++] = jval_i(node->key);
        flag = 0;
    }

    printf("List of castle just can go by walking: ");
    for(int i=0; i<j; i++){
        printf("%d ", castles[i]);
    }
    printf("\n");
}

void maxInDegreeCastle(Graph g){
    JRB node, nodeVal, tmp;
    int n, i=0, MAX=0;
    int indegreeCastle[100];
    int listOfMaxInDegreeCastle[100];

    jrb_traverse(node, g.vertices){
        n = indegree(g, jval_i(node->key), indegreeCastle);
        if(n > MAX) MAX = n;
    }

    jrb_traverse(node, g.vertices){
        n = indegree(g, jval_i(node->key), indegreeCastle);
        if(n == MAX)
            listOfMaxInDegreeCastle[i++] = jval_i(node->key);
    }

    printf("List Of Max InDegree Castle: ");
    for(int j=0; j<i; j++){
        printf("%d ", listOfMaxInDegreeCastle[j]);
    }
    printf("\n");
}

void shortestPathCastle(Graph g){
    int s, t;
    printf("Enter start location: ");
    scanf(" %d", &s);
    printf("Enter end location: ");
    scanf(" %d", &t);

    int path[100], length;
    double n = shortestPath(g, s, t, path, &length);
    printf("Path length: %.0lf\n", n);
    printf("Path: ");
    for(int i=0; i<length; i++){
        printf("%d ", path[i]);
    }
    printf("\n");
}
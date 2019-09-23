#include <stdio.h>
#include <stdlib.h>

#include "graphJRB.h"

#define MAX 10

typedef struct{
	int num[MAX];
} Matrix;

void readFile(Matrix *m, char *fileName, int *n);

int main(){
	int n[2];
	Matrix m[MAX];
	Graph g = createGraph();



	readFile(m, "matrix.txt", n);

	return 0;
}

void readFile(Matrix *m, char *fileName, int *n){
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("Cant read file.\n");
		return;
	}

	fscanf(fp, "%d %d\n", n, (n+1));
	for(int i=0; i<*n; i++){
		fscanf(fp, "%d %d %d %d %d", &m[i].num[0], &m[i].num[1], &m[i].num[2], &m[i].num[3], &m[i].num[4]);
		printf("%d %d %d %d %d\n", m[i].num[0], m[i].num[1], m[i].num[2], m[i].num[3], m[i].num[4]);
	}	

}

void saveToGraph(Graph g, Matrix *m, int *n){

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if()
		}
	}

}

int checkAdj(){
	
}
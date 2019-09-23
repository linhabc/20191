#include <stdio.h>
#include <stdlib.h>

#include "graphJRB.h"

#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;
#define MAX 50

typedef struct {
	int id;
	char name[MAX];
} Station;

typedef struct {
	int line[MAX];
} Lines;


void getFile(Station *station, Lines *line, char *fileName, int n);
void charIdToInt(Station *station, int n);

int main(){
	Station station[MAX];
	Lines lines[MAX];

	Graph g = createGraph();

	getFile(station, lines, "demo.txt", 9);

	for(int i=0; i<5; i++){
		for(int j=1; j<5; j++){
			addEdge(g, lines[i].line[0], lines[i].line[j]);
		}
	}

	printGraph(g);

	return 0;
}

//n is the number of station
void getFile(Station *station, Lines *line, char *fileName, int n){
	FILE* fp = fopen(fileName, "r");

	char STATION[MAX], LINES[MAX];

	fgets(STATION, MAX-1, fp);
	for(int i=1; i<=9; i++){
		fscanf(fp, "S%d\t", &station[i].id);
		fgets(station[i].name, MAX, fp);
		strcut_newline(station[i].name);

		printf("S%d %s\n", station[i].id, station[i].name);
	}
	fgets(STATION, MAX-1, fp);

	for(int i=0; i<5; i++){
		fscanf(fp, "S%d\tS%d\tS%d\tS%d\tS%d\n", &line[i].line[0], &line[i].line[1], &line[i].line[2], &line[i].line[3], &line[i].line[4]);
		printf("S%d\tS%d\tS%d\tS%d\tS%d\n", line[i].line[0], line[i].line[1], line[i].line[2], line[i].line[3], line[i].line[4]);
	}
}



#include <stdio.h>
#include <stdlib.h>
#include "weighted_graph.h"

typedef struct {
	int id;
	char name[100];
} Product;

typedef struct {
	int id;
	char name[100];
	int quantityOfProduct[100];
} Store;

void printTitle(){
	printf("C-Advanced, HK20182\n");
}

int readProduct(char *fileName, Product *products){
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("Cant open file\n");
		exit(1);
	}

	int nproducts;

	fscanf(fp, "%d", &nproducts);
	for(int i=0; i<nproducts; i++){
		fscanf(fp, "%s %d", (products+i)->name, &(products[i].id));
	}

	return nproducts;
}

void printProductList(Product products[], int nproducts) {
    for (int i = 0; i < nproducts; i++) {
        printf("%s %d\n", products[i].name, products[i].id);
    }    
    return;
}

int readStoreFile(char *fileName, Store *stores, int nproducts, Graph g){//get nlink, have nproducts
	FILE* fp = fopen(fileName, "r");
	if(fp == NULL){
		printf("Cant open file\n");
		exit(1);
	}

	int nstores;
	fscanf(fp, "%d", &nstores);
	for(int i=0; i<nstores; i++){
		fscanf(fp, "%s %d", stores[i].name, &(stores[i].id));
		//printf("%s %d\n", stores[i].name, (stores[i].id));
		for(int j=0; j<nproducts; j++){
			int currentProductId;
            int currentQuanity;
			fscanf(fp, "%d %d", &currentProductId, &currentQuanity);
			stores[i].quantityOfProduct[currentProductId] = currentQuanity;
			//printf("%d %d\n", currentProductId, currentQuanity);
		}
	}

	int nlinks; //get how many edges of graph
	fscanf(fp, "%d", &nlinks);
	for(int i=0; i<nlinks; i++){
		int store1, store2, distance;
		fscanf(fp, "%d %d %d", &store1, &store2, &distance);
		printf("%d %d %d\n", store1, store2, distance);

		addVertex(g, store1, stores[store1-1].name);//store1-1 because of the deviation of index of name and id of product
		addVertex(g, store2, stores[store2-1].name);
		addEdge(g, store1, store2, distance);

	}

	return nstores;
}

void checkoutProductInStores(Graph g, 
							Store *stores, 
							Product *products, 
							int nstores, 
							int nproducts, 
							int productId, 
							int storeId)
{
	printProductAndStoreName(stores, products, nstores, nproducts, productId, storeId);

	printf("Adjacent stores:\n");
	int output[100];
	int size;
	size = indegree(g, storeId, &output);
	//printf("%d\n", size);
	for(int i=0; i<size; i++){
		printProductAndStoreName(stores, products, nstores, nproducts, productId, output[i]);
	}

}

void printProductAndStoreName(
							Store *stores, 
							Product *products, 
							int nstores, 
							int nproducts, 
							int productId, 
							int storeId)
{
	int i,j;
	for(i=0; i<nstores; i++){
		if(stores[i].id == storeId){
			printf("%s\n", stores[i].name);
			break;
		}
	}

	for(j=0; j<nproducts; j++){
		if(products[j].id == productId)
			break;
	}

	printf("%s %d\n", products[j].name, stores[i].quantityOfProduct[productId]);
}
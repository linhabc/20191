#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "weighted_graph.h"
#include "function.h"

int main(int argc, int *argv[]){
	int nproducts, nstores;
	Product *products = (Product*)malloc(sizeof(Product)*100);
	Store *stores = (Store*)malloc(sizeof(Store)*100);

	Graph g = createGraph();

	if(argc == 2 && strcmp(argv[1], "-t")==0)
		printTitle();

	if(argc == 3 && strcmp(argv[1], "-s")==0){
		nproducts = readProduct(argv[2], products);
		printProductList(products, nproducts);
	}


	// int path[100], length;
	// double pathWeight;
	int store1, store2;
	double distance;
	if(argc == 6 && strcmp(argv[1], "-w")==0){
		store1 = atoi(argv[4]);
		store2 = atoi(argv[5]);
		nproducts = readProduct(argv[2], products);
		nstores = readStoreFile(argv[3], stores, nproducts, g);
		// pathWeight = shortestPath(g, store1, store2, path, &length);
		// if(pathWeight==INFINITIVE_VALUE)
		// 	printf("-1\n");
		// else
		// 	printf("%.1lf km\n", pathWeight);

		distance = getEdgeValue(g, store1, store2);
		if(distance==INFINITIVE_VALUE)
			printf("-1\n");
		else
			printf("%.1lf km\n", distance);
	}

	if(argc == 4 && strcmp(argv[1], "-a")==0){
		nproducts = readProduct(argv[2], products);
		nstores = readStoreFile(argv[3], stores, nproducts, g);
		for(int i=0; i<nstores; i++){
			printf("%s\n", stores[i].name);
			for(int j=0; j<nproducts; j++){
				printf("%s %d\n", products[j].name, stores[i].quantityOfProduct[j+1]);
			}
			printf("----\n");
		}
	}

	int productId;
	int storeId;
	if(argc == 6 && strcmp(argv[1], "-h")==0){
		productId = atoi(argv[4]);
		storeId	= atoi(argv[5]);

		nproducts = readProduct(argv[2], products);
		nstores = readStoreFile(argv[3], stores, nproducts, g);
		
		checkoutProductInStores(g, stores, products,
								 nstores, nproducts, 
								 productId, storeId);
	}

	return 0;
}
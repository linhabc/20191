#include <stdio.h>
#include <stdlib.h>
#include "graphJRB.h"

Graph createGraph(){
  return make_jrb();
}

void addEdge(Graph graph, int v1, int v2){
  JRB tree = make_jrb();

  Graph g1 = jrb_find_int(graph, v1);            //find if key v1 exist
  if(g1==NULL){
    tree = createGraph();                         //create new tree
    jrb_insert_int(graph, v1, new_jval_v(tree)); //insert new tree as value of key v1
  }else{
    tree = (JRB)jval_v(g1->val);                 //else, assign new tree as v1 edge tree
  }
  jrb_insert_int(tree, v2, new_jval_i(1));       //insert value for node in newtree

  Graph g2 = jrb_find_int(graph, v2);            //similar as v1
  if(g2==NULL){
    tree = createGraph();
    jrb_insert_int(graph, v2, new_jval_v(tree));
  }else{
   tree = (JRB)jval_v(g2->val);
  }
  jrb_insert_int(tree, v1, new_jval_i(1));
}

int adjacent(Graph graph, int v1, int v2){
  JRB node, adjNode;
  node = jrb_find_int(graph, v1);
  if(node != NULL){
    adjNode = jrb_find_int(node, v2);
    if(adjNode != NULL){
      return 1;
    }
  }
  return 0;
}

int getAdjacentVertices (Graph graph, int v, int* output){
  JRB node, tree, nodeTree;
  int total=0;
  tree = jrb_find_int(graph, v);
  if(tree == NULL){
    return NULL;
  }
  
  nodeTree = (JRB)jval_v(tree->val);
  jrb_traverse(node, nodeTree){
    output[total++] = jval_i(node->key);
  }
  return total;
}

void printGraph(Graph graph){
  JRB tmp, nodetmp;
  JRB tree;
  jrb_traverse(tmp, graph){
    printf("%d: ", jval_i(tmp->key));
    tree = (JRB)jval_v(tmp->val);
    jrb_traverse(nodetmp, tree){
      printf("%d ", jval_i(nodetmp->key));
    }
    printf("\n");
  }
}

void dropGraph(Graph graph){
  JRB tmp, tmpNode;
  jrb_traverse(tmp, graph){
    tmpNode = (JRB)jval_v(tmp->val);
    jrb_free_tree(tmpNode);
  }
  jrb_free_tree(graph);
}

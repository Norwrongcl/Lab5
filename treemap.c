#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)){
  TreeMap *new= (TreeMap *)malloc(sizeof(TreeMap));
  new->root= NULL;
  new->current= NULL;
  new->lower_than= lower_than;
  return new;
}


void insertTreeMap(TreeMap * tree, void* key, void * value){
	
	TreeNode * auxtree= tree->root;
  TreeNode * temp= NULL;
  if(searchTreeMap(tree,key) != NULL) return; 
  while(auxtree != NULL){
    temp= auxtree;
    int res= tree->lower_than(key,auxtree->pair->key);
    if(res == 1) auxtree= auxtree->left;
    else{
      if(res == 0) auxtree= auxtree->right;
      else return;
    }
  }
  TreeNode * newNodo= createTreeNode(key,value);
  newNodo->parent= temp;
  int res1= tree->lower_than(key,temp->pair->key);
	
  if(temp != NULL){
    if(res1 == 1) temp->left= newNodo;
    if(res1 == 0) temp->right= newNodo;
  }
	
  if(temp == NULL) tree->root= newNodo;
  tree->current= newNodo;
  return;
}

TreeNode * minimum(TreeNode * a){
  while(a->left!=NULL){
  a=a->left;
  }
  return a;

}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}

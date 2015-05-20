#include<stdlib.h>
#include "unionfind.h"

UNIONFIND *unionfind_prepareNew(int size){
    UNIONFIND* uf;
    int i;

    if(size <= 0){
        return NULL;
    }

    uf = (UNIONFIND *)malloc(sizeof(UNIONFIND));
    if(uf == NULL){
        return NULL;
    }
    
    //set size
    uf->size = size;
    uf->setCount = size;
    
    uf->parent = (int *)malloc(sizeof(int)*size);
    if(uf->parent == NULL){
        free(uf);
        return NULL;
    } else {
        //init values
        for(i = 0; i < size; i++){
            uf->parent[i] = i;
        }
    }
    
    uf->rank = (int *)malloc(sizeof(int)*size);
    if(uf->rank == NULL){
        free(uf->parent);
        free(uf);
        return NULL;
    } else {
        //init values
        for(i = 0; i < size; i++){
            uf->rank[i] = 0;
        }
    }
    
    uf->treeSize = (int *)malloc(sizeof(int)*size);
    if(uf->treeSize == NULL){
        free(uf->rank);
        free(uf->parent);
        free(uf);
        return NULL;
    } else {
        //init values
        for(i = 0; i < size; i++){
            uf->treeSize[i] = 1;
        }
    }
    
    return uf;
}

void unionfind_free(UNIONFIND* uf){
    free(uf->treeSize);
    free(uf->rank);
    free(uf->parent);
    free(uf);
}

int unionfind_findRoot(UNIONFIND* uf, int el){
    if(uf->parent[el] != el){
        uf->parent[el] = unionfind_findRoot(uf, uf->parent[el]);
    }
    return uf->parent[el];
}

void unionfind_union(UNIONFIND* uf, int el1, int el2){
    int root1 = unionfind_findRoot(uf, el1);
    int root2 = unionfind_findRoot(uf, el2);
    
    if(root1 == root2){
        return;
    } else if(uf->rank[root1] < uf->rank[root2]){
        uf->parent[root1] = root2;
        uf->treeSize[root1] += uf->treeSize[root2];
        uf->setCount--;
    } else if(uf->rank[root1] > uf->rank[root2]){
        uf->parent[root2] = root1;
        uf->treeSize[root2] += uf->treeSize[root1];
        uf->setCount--;
    } else {
        uf->parent[root1] = root2;
        uf->rank[root1]++;
        uf->treeSize[root1] += uf->treeSize[root2];
        uf->setCount--;
    }
}

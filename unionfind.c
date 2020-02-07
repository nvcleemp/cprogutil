#include<stdlib.h>
#include "unionfind.h"

UNIONFIND *unionfind_prepare_new(int size){
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
    uf->set_count = size;
    
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
    
    uf->tree_size = (int *)malloc(sizeof(int) * size);
    if(uf->tree_size == NULL){
        free(uf->rank);
        free(uf->parent);
        free(uf);
        return NULL;
    } else {
        //init values
        for(i = 0; i < size; i++){
            uf->tree_size[i] = 1;
        }
    }
    
    return uf;
}

void unionfind_free(UNIONFIND* uf){
    free(uf->tree_size);
    free(uf->rank);
    free(uf->parent);
    free(uf);
}

int unionfind_find_root(UNIONFIND* uf, int el){
    if(uf->parent[el] != el){
        uf->parent[el] = unionfind_find_root(uf, uf->parent[el]);
    }
    return uf->parent[el];
}

void unionfind_union(UNIONFIND* uf, int el1, int el2){
    int root1 = unionfind_find_root(uf, el1);
    int root2 = unionfind_find_root(uf, el2);
    
    if(root1 == root2){
        return;
    } else if(uf->rank[root1] < uf->rank[root2]){
        uf->parent[root1] = root2;
        uf->tree_size[root2] += uf->tree_size[root1];
        uf->set_count--;
    } else if(uf->rank[root1] > uf->rank[root2]){
        uf->parent[root2] = root1;
        uf->tree_size[root1] += uf->tree_size[root2];
        uf->set_count--;
    } else {
        uf->parent[root1] = root2;
        uf->rank[root1]++;
        uf->tree_size[root2] += uf->tree_size[root1];
        uf->set_count--;
    }
}

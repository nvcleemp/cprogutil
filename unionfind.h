/* 
 * File:   unionfind.h
 * Author: nvcleemp
 *
 * Created on May 20, 2015, 2:00 PM
 */

#include<stdlib.h>

#ifndef UNIONFIND_H
#define	UNIONFIND_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct uf_struct {
        int size; /* i.e., the number of elements */
        int set_count;
        
        int *parent;
        int *tree_size;
        int *rank;
    } UNIONFIND;

    UNIONFIND *unionfind_prepare_new(int size);

    void unionfind_free(UNIONFIND* uf);
    
    int unionfind_find_root(UNIONFIND* uf, int el);
    
    void unionfind_union(UNIONFIND* uf, int el1, int el2);

#ifdef	__cplusplus
}
#endif

#endif	/* UNIONFIND_H */


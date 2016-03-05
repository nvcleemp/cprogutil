#include<stdlib.h>
#include "queue.h"

INT_QUEUE *queue_prepareNew(int maxElementsAdded){
    INT_QUEUE *q;
    
    if(maxElementsAdded <= 0){
        return NULL;
    }
    
    q = (INT_QUEUE *)malloc(sizeof(INT_QUEUE));
    if(q == NULL){
        return NULL;
    }
    
    q->queue = (int *)malloc(sizeof(int)*maxElementsAdded);
    if(q->queue == NULL){
        free(q);
        return NULL;
    }
    
    q->head = q->tail = 0;
    
    return q;
}

void queue_free(INT_QUEUE *q){
    free(q->queue);
    free(q);
}

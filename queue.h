/* 
 * File:   queue.h
 * Author: nvcleemp
 *
 * Created on August 14, 2015, 2:27 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#ifdef	__cplusplus
extern "C" {
#endif
    typedef struct int_queue_struct INT_QUEUE;
    
    struct int_queue_struct {
        int head;
        int tail;
        int *queue;
    };

    INT_QUEUE *queue_prepareNew(int maxElementsAdded);
    
    void queue_free(INT_QUEUE *q);
    
#define QUEUE_IS_NOT_EMPTY(q) ((q)->tail > (q)->head)
#define QUEUE_IS_EMPTY(q) ((q)->tail == (q)->head)
    
#define QUEUE_POP(q) ((q)->queue[((q)->head)++])
#define QUEUE_PUSH(q, value) (q)->queue[((q)->tail)++] = value


#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_H */


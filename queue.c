#include "queue.h"

#include <stdlib.h>

static uint32_t succ(queue *q, uint32_t n) {
    return (n + 1) % q->size;
}

queue *newQueue(uint32_t size) {
    queue *q = (queue *) malloc(sizeof(queue));
    if (q) {
        q->head = q->tail = 0;
        q->size = size;
        q->Q = (item *) calloc(size, sizeof(item));
        if (q->Q) {
            return q;
        }
        free(q);
    }
    return (queue *) 0;
}

void delQueue(queue *q) {
    if (q) {
        free(q->Q);
        free(q);
    }
}

bool emptyQ(queue *q) {
    if (q) {
        return q->head == q->tail;
    }
    return true;
}

bool fullQ(queue *q) {
    if (q) {
        return succ(q, q->head) == q->tail;
    }
    return true;
}

bool enqueue(queue *q, item *i) {
    if (q) {
        if (fullQ(q)) {
            return false;
        }
        q->Q[q->head] = *i;
        q->head = succ(q, q->head);
        return true;
    } else {
        return false;
    }
}

bool dequeue(queue *q, item *i) {
    if (q) {
        if (emptyQ(q)) {
            return false;
        }
        *i = q->Q[q->tail];
        q->tail = succ(q, q->tail);
        return true;
    } else {
        return false;
    }
}

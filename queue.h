#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t item;

typedef struct queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    item *Q;
} queue;

queue *newQ(uint32_t);

void delQ(queue *);

bool emptyQ(queue *);

bool fullQ(queue *);

bool enqueue(queue *, item *);

bool dequeue(queue *, item *);

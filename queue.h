#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t item;

typedef struct queue {
  uint32_t head;
  uint32_t tail;
  uint32_t size;
  item *Q;
} queue;

queue *newQueue(uint32_t);

void delQueue(queue *);

bool emptyQ(queue *);

bool fullQ(queue *);

bool enqueue(queue *, item *);

bool dequeue(queue *, item *);
#endif

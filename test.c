#include "queue.h"
#include <stdio.h>

int main(void) {
  queue *q = newQueue(100);

  for (uint32_t i = 0; !fullQ(q); i += 1) {
    (void) enqueue(q, &i);
  }

  uint32_t x;
  while (!emptyQ(q)) {
    (void) dequeue(q, &x);
    printf("%d\n", x);
  }

  delQueue(q);

  return 0;
}

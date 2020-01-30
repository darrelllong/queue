#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>

#define OPTIONS "n:"

int main(int argc, char **argv) {
  uint32_t n = 100;

  int c;
  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 'n':
      n = strtol(optarg, (char **)NULL, 10);
      break;
    default:
      printf("Invalid argument\n");
      break;
    }
  }

  queue *q = newQueue(n);

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

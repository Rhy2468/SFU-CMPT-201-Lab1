#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void *sbrk(intptr_t increment);

struct header {
  uint64_t size;
  struct header *next;
};

int main() {
  // Allocate memory to heap memory
  void *heap = sbrk(256);
  // check if heap failed or not
  if (heap == (void *)-1) {
    perror("sbrk Failed");
    return 1;
  }

  // Divide memory into 2 blocks and set headers
  struct header *block1 = (struct header *)heap;
  struct header *block2 = (struct header *)((char *)heap + 128);
  block1->size = 128;
  block1->next = NULL;
  block2->size = 128;
  block2->next = block1;

  // Initialize block data
  void *data1 = (char *)block1 + sizeof(struct header);
  void *data2 = (char *)block2 + sizeof(struct header);
  size_t dataSize = 128 - sizeof(struct header);
  memset(data1, 0, dataSize);
  memset(data2, 1, dataSize);

  // print
  printf("Block 1 Address: %p\n", (void *)block1);
  printf("Block 2 Address: %p\n", (void *)block2);
  printf("Block 1 size: %lu\n", block1->size);
  printf("Block 1 next: %p\n", (void *)block1->next);
  printf("Block 2 size: %lu\n", block2->size);
  printf("Block 2 next: %p\n", (void *)block2->next);
  printf("Block 1 data:\n");
  for (size_t i = 0; i < dataSize; i++) {
    printf("%d ", ((unsigned char *)data1)[i]);
  }
  printf("\n");

  printf("Block 2 data:\n");
  for (size_t i = 0; i < dataSize; i++) {
    printf("%d ", ((unsigned char *)data2)[i]);
  }
  printf("\n");

  return 0;
};

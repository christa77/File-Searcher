// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "Vector.h"

#define N 10  // Test vector length.
#define M 4  // Initial size

// Print the elements in the vector on a line.
static void PrintIntVector(vector_t v);

int main(int argc, char *argv[]) {
  int i;
  vector_t v = VectorAllocate(M);

  if (v == NULL)
    return EXIT_FAILURE;

  for (i = 0; i < N; ++i) {  // Place some elements in the vector.
    int *x = (int*)malloc(sizeof(int));

    if (x == NULL) {
      return EXIT_FAILURE;
    }

    element_t old;
    VectorSet(v, i, x, &old);
  }

  PrintIntVector(v);
  for (i = 0; i < N; i++) {
     free(VectorGet(v, i));
  }
  VectorFree(v);
  return EXIT_SUCCESS;
}

static void PrintIntVector(vector_t v) {
  int i;
  size_t length;

  assert(v != NULL);

  length = VectorLength(v);

  if (length > 0) {
    printf("[%d", *((int*)VectorGet(v, 0)));
    for (i = 1; i < VectorLength(v); ++i)
      printf(",%d", *((int*)VectorGet(v, i)));
    printf("]\n");
  }
}

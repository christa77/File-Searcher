// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdio.h>  // for printf
#include <stdlib.h>  // for EXIT_FAILURE, EXIT_SUCCESS
#include <inttypes.h>  // for int16_t

// Point3d contains 3 fields for x,y, and z coordinates.
typedef struct point_st {
  int16_t x;
  int16_t y;
  int16_t z;
} Point3d, *Point3dPtr;

// Allocates spaces for a Point3d and return a pointer to it.
Point3dPtr AllocatePoint3d(int16_t x, int16_t y, int16_t z) {
  Point3d* retPtr = (Point3d*) malloc(sizeof(Point3d));

  // If malloc doesn't fail, assign each fields with given value.
  if (retPtr != NULL) {
    retPtr -> x = x;
    retPtr -> y = y;
    retPtr -> z = z;
  }
  return retPtr;
}

int main(int argc, char **argv) {
  Point3dPtr ptr = AllocatePoint3d(1, 2, 3);

  // Check if the malloc of AllocatePoint3d fails.
  if (ptr == NULL) {
    return EXIT_FAILURE;
  }
  // If the malloc of AllocatedPoint3d doesn't fail
  // Check the correctness of each field.
  if (ptr -> x != 1) {
    return EXIT_FAILURE;
  }
  if (ptr -> y != 2) {
    return EXIT_FAILURE;
  }
  if (ptr -> z != 3) {
    return EXIT_FAILURE;
  }

  // Free the memory which malloc was taken.
  free(ptr);
  printf("AllocatePoint3d works well. \n");
  return EXIT_SUCCESS;
}

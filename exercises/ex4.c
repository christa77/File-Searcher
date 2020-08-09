// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdio.h>  // for printf
#include <stdlib.h>  // for EXIT_FAILURE, EXIT_SUCCESS
#include <inttypes.h>  // for int16_t
#include "NthPrime.h"

int main(int argc, char **argv) {
  if (NthPrime(1) != 2) {
    return EXIT_FAILURE;
  }
  if (NthPrime(2) != 3) {
    return EXIT_FAILURE;
  }
  if (NthPrime(3) != 5) {
    return EXIT_FAILURE;
  }
  if (NthPrime(4) != 7) {
    return EXIT_FAILURE;
  }
  if (NthPrime(5) != 11) {
    return EXIT_FAILURE;
  }
  if (NthPrime(6) != 13) {
    return EXIT_FAILURE;
  }
  if (NthPrime(7) != 17) {
    return EXIT_FAILURE;
  }
  if (NthPrime(8) != 19) {
    return EXIT_FAILURE;
  }
}


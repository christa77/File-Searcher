// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdlib.h>  //  for EXIT_FAILURE
#include <inttypes.h>  // for int16_ti
#include <stdbool.h>  // for bool
#include "NthPrime.h"

// Check if a given number is prime and return a boolean value for it
bool isPrime(int64_t num);

int64_t NthPrime(int16_t order) {
  // printf("%" PRId16, INT16_MAX);

  // A counter for counting current order.
  int odCounter = 0;
  int64_t rtValue = 0;

  // Check if the given order is in a valid range.
  if (order < 1 || order > INT16_MAX) {
    return EXIT_FAILURE;
  }


  for (int64_t i = 0; i < INT16_MAX; i++) {
    if (isPrime(i)) {
      odCounter++;
      // Once odCounter reaches order, i is the result.
      if (odCounter == order) {
        rtValue = i;
      }
    }
  }
  return rtValue;
}

bool isPrime(int64_t num) {
  // Zero and One is not a prime number, and negative numbers
  if (num <= 1) {
    return false;
  }
  // Check if the given number only can be divided by itself and zero
  for (int64_t i = 2; i < num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

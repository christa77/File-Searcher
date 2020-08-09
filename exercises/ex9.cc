// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <iostream>
#include <cstdlib>
#include "IntPair.h"

// Tests to see if the parameter is passed by value or reference.
void Test(IntPair ip);

int main(int argc, char **argv) {
  int x = 3;
  int y = 4;

  IntPair intpair(x, y);
  // Tests intpair
  Test(intpair);

  intpair.Get(&x, &y);

  // If x and y increments by 1 it means it passed by value
  // otherwise it keeps unchanged.
  if (x == 4 && y == 5) {
    std::cout << "Is pass by reference\n";
  } else if (x == 3 && y == 4) {
    std::cout << "Is pass by value\n";
  }

  return EXIT_SUCCESS;
}

void Test(IntPair ip) {
  int x;
  int y;
  x = 0;
  y = 0;
  // Get is passing by reference.
  ip.Get(&x, &y);
  x++;
  y++;
  // Set is passing by value.
  ip.Set(x, y);
}

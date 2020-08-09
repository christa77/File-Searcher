// Copyright 2020 Yuxiao Cao
// yuxiao08

#include "./IntPair.h"

IntPair::IntPair(int x, int y) {
  x_ = x;
  y_ = y;
}

void IntPair::Get(int *x, int *y) {
  *x = x_;
  *y = y_;
}

void IntPair::Set(int x, int y) {
  x_ = x;
  y_ = y;
}

// Copyright 2020 Yuxiao Cao
// yuxiao08

#ifndef INTPAIR_H_
#define INTPAIR_H_

class IntPair {
 public:
  // Constructor
  IntPair(int x, int y);
  // Getter that returns the two integers through pointers.
  void Get(int *x, int *y);
  // Setter.
  void Set(int x, int y);

 private:
  int x_;
  int y_;
};

#endif  // INTPAIR_H_

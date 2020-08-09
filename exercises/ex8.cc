// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <iostream>  // for printf
#include <cstdlib>  // for EXIT_SUCCESS

int main(int argc, char **argv) {
  int num;
  // Validates user input as the argument should be one.
  if (argc > 1) {
    std::cout << "Invalid argument.\n";
    return EXIT_FAILURE;
  }

  std::cout << "Which positive integer would you like me to factorize? ";
  // Get user input.
  std::cin >> num;

  // Checks if the input is a number.
  if (!std::cin) {
    std::cout << "Input should be a number.\n";
    return EXIT_FAILURE;
  }
  // Checks if the number is a non-negative number.
  if (num <= 0) {
    std::cout <<
    "The number to be factorized cannot be negative.\n ";
    return EXIT_FAILURE;
  }

  // Prints the result out one by one.
  std::cout << 1;
  for (int i = 2; i <= num; i++) {
    if (num % i == 0) {
      std::cout << " " << i;
    }
  }
  std::cout << "\n";
  return EXIT_SUCCESS;
}

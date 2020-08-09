// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdio.h>  // for functions about File I/O
#include <stdlib.h>  // for EXIT_FAILURE, EXIT_SUCCESS

int main(int argc, char **argv) {
  FILE *file;
  size_t size;
  char ch;

  // Validate user input.
  if (argc != 2) {
    fprintf(stderr, "Invalid input.\n");
    return EXIT_FAILURE;
  }

  // open the file in binary mode.
  file = fopen(argv[1], "rb");
  if (file == NULL) {
    fprintf(stderr, "%s -- ", argv[1]);
    perror("fopen for read failed.\n");
    return EXIT_FAILURE;
  }

  // Get the file size;
  fseek(file, 0, SEEK_END);
  size = ftell(file);

  //for (int i = size - 1; i >= 0; i--) {
    // Read the file's contents
    fseek(file, size - 2, SEEK_SET);
    fread(&ch, sizeof(char), 1, file);

    printf("%c", ch);
  //}

  // Close the file.
  fclose(file);
  return EXIT_SUCCESS;
}

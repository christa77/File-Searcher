// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdio.h>  // for pintf
#include <inttypes.h>  // for PRIx8
#include <stdlib.h>  // for EXIT_SUCCESS

// Prints out the value byte by byte in hex pointed to by pData.
void DumpHex(void* pData, int byteLen);

int main(int argc, char **argv) {
  char     char_val = '0';
  int32_t  int_val = 1;
  float    float_val = 1.0;
  double   double_val  = 1.0;

  typedef struct {
    char     char_val;
    int32_t  int_val;
    float    float_val;
    double   double_val;
  } Ex2Struct;

  Ex2Struct struct_val = { '0', 1, 1.0, 1.0 };

  DumpHex(&char_val, sizeof(char));
  DumpHex(&int_val, sizeof(int32_t));
  DumpHex(&float_val, sizeof(float));
  DumpHex(&double_val, sizeof(double));
  DumpHex(&struct_val, sizeof(struct_val));

  return EXIT_SUCCESS;
}

void DumpHex(void* pData, int byteLen) {
  // Two hex digits as a group is 1 byte
  // so use uint8_t to cast.
  uint8_t *newPtr = (uint8_t *) pData;

  // Print out as the format on spec.
  printf("The %d bytes starting at %p are:", byteLen, newPtr);

  // Print out the result byte to byte.
  for (int i = 0; i < byteLen; i++) {
    printf("%02" PRIx8 " ", *(newPtr + i));
  }
  printf("\n");
}

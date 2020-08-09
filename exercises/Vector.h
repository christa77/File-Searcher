// Copyright 2020 Yuxiao Cao
// yuxiao08

#ifndef VECTOR_H_
#define VECTOR_H_

// An pointer to represent an arbitrary type of element in the vector.
typedef void* element_t;

// An expandable array of element_t.
typedef struct vector_st {
  size_t length;
  element_t *arry;
} *vector_t;

// On success, return vector_t with an initial length of n.
// On failure, returns NULL.
vector_t VectorAllocate(size_t n);

// Frees the memory allocated for the vector_t.  Assumes v != NULL.
void VectorFree(vector_t v);

// Sets the indexth element of v to be e.
// Returns the previous indexth element_t in
// prev. Freeing e is the responsibility of the user, not the vector_t.
// Returns true iff successful.  Assumes v != NULL.
bool VectorSet(vector_t v, int index, element_t e, element_t *prev);

// Returns the pointer to the element at the given index within v.
// Assumes v != NULL.
element_t VectorGet(vector_t v, int index);

// Returns the length of v.  Assumes v != NULL.
size_t VectorLength(vector_t v);

#endif  // VECTOR_H_

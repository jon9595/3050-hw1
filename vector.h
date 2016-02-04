#ifndef H_VECTOR_H
#define H_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_VECTOR_SIZE 512

enum vector_errors
{
	OUT_OF_BOUNDS = 0,
};

typedef struct vector
{
	int* data;
	int size;
	int capacity;
}Vector;

void init_vector(struct vector* v);
int access_element_vector(struct vector* v, size_t index);
void insert_element_vector(struct vector* v, int element_to_insert);
void free_vector(struct vector* v);
Vector parse_ints(FILE* file);
void compare(Vector v1, Vector v2, int size1, int size2);
void shell_sort(Vector* array, int numDigits);

#endif

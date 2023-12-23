#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
typedef struct vector vector;
struct vector{
    void** mass;
    size_t size;
};
/*Constructor of vector:
 * For the constructor, you must enter the vector for which the constructor is used, the size of its data type, and its starting size*/
void constructor(vector* main,size_t size);
/*Push back element into vector
 * For push back you should provide pointer to memory area*/
void push_back(vector* main,void* data);

void* element_at(vector* main,int* index);

void clear(vector* main);

int empty(vector* main);
#endif //VECTOR_LIBRARY_H

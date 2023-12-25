#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct vector vector;
struct vector{
    void** mass;
    size_t size;
    size_t max_size;
};




/*Constructor of vector:
 * For the constructor, you must enter the vector for which the constructor is used, the size of its data type, and its starting size*/
void constructor(vector* main,size_t size);


//Iterators

/*Returns an iterator pointing to the first element in the vector*/
void* begin(vector* main);
/*Returns an iterator pointing to the theoretical element that follows the last element in the vector*/
void* end(vector* main);
/*Returns a constant iterator pointing to the first element in the vector*/
const void* cbegin(vector* main);
/*Returns a constant iterator pointing to the theoretical element that follows the last element in the vector*/
const void* cend(vector* main);



//Capacity

/*Returns the number of elements in the vector*/
size_t size(vector* main);
/*Returns the maximum number of elements that the vector can hold*/
size_t max_size(vector* main);
/*Resizes the container so that it contains ‘new_size’ elements*/
void resize(vector* main,size_t new_size);
/*Returns whether the container is empty*/
bool empty(vector* main);



//Element access

/*Returns a reference to the element at position ‘index’ in the vector*/
void* at(vector* main,const int* index);
/*Returns a reference to the first element in the vector*/
void* front(vector* main);
/*Returns a reference to the last element in the vector*/
void* back(vector* main);
/*Returns a direct pointer to the memory array used internally by the vector to store its owned elements*/
void** data(vector* main);



//Modifiers

/*It pushes the elements into a vector from the back*/
void push_back(vector* main,void* data);
/*It is used to pop or remove elements from a vector from the back*/
void pop_back(vector* main);
/*It inserts new element before the element at the specified position*/
void insert(vector* main,const int* position,void* val);
/*t is used to remove count of elements from a container from the specified position*/
void erase(vector* main,const int* position,const int* count);
/*It is used to remove all the elements of the vector container*/
void clear(vector* main);
/*It extends the container by inserting new element at position*/
void emplace(vector* main,const int* position,void* val);
/*It is used to insert a new element into the vector container, the new element is added to the end of the vector*/
void emplace_back(vector* main,void* val);


#endif //VECTOR_LIBRARY_H

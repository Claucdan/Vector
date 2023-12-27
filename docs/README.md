# Vector in C
<div id="badges">
 <img src=https://img.shields.io/badge/CLion-grey?style=for-the-badge&logo=clion&logoColor=white></img>
 <img src=https://img.shields.io/badge/CMake-orange?style=for-the-badge&logo=cmake&logoColor=white></img>
 <img src=https://img.shields.io/badge/C-teal?style=for-the-badge&logo=c%2B%2B&logoColor=white></img>
</div>

## Some information
***
As we all know, in high-level programming languages, there is such a type of container as a vector. It makes it easier to work with expandable arrays.<br>
In the process of working on some project aimed at fine memory work, the c programming language was chosen.Unfortunately, there is no such built-in container in this programming language.
Therefore, there was a desire to implement its own vector structure.

## Information of struct vector
***
To begin with, let's talk about the structure of the vector defined as the main idea of the project.<br>
There are only three fields in the vector structure:
*   <code>void** mass</code> - An array of pointers to memory locations where objects in this vector are stored
*   <code>size_t size</code> - Count of element in an array
*   <code>size_t max_size</code> - The current size of the pointer array

```c
struct vector{
    void** mass;
    size_t size;
    size_t max_size;
};
```

## Basic methods
***

### Constructor
* ```void constructor(vector* main,size_t size)``` - Class constructor for a vector. For the constructor, you must specify the initial size of the vector

### Iterators
* ```void* begin(vector* main)``` - Returns an iterator pointing to the first element in the vector.
* ```void* end(vector* main)``` - Returns an iterator pointing to the theoretical element that follows the last element in the vector
* ```void* cbegin(vector* main)``` - Returns a constant iterator pointing to the first element in the vector
* ```void* cend(vector* main)``` - Returns a constant iterator pointing to the theoretical element that follows the last element in the vector

### Capacity
* ```size_t size(vector* main)``` - Returns the number of elements in the vector
* ```size_t max_size(vector* main)``` - Returns the maximum number of elements that the vector can hold
* ```void resize(vector* main,size_t new_size)``` - Resizes the container so that it contains ‘new_size’ elements
* ```bool empty(vector* main)``` - Returns whether the container is empty

### Element access
* ```void* at(vector* main,const int* index)``` - Returns a reference to the element at position ‘index’ in the vector
* ```void* front(vector* main)``` - Returns a reference to the first element in the vector
* ```void* back(vector* main)``` - Returns a reference to the last element in the vector
* ```void** data(vector* main)``` - Returns a direct pointer to the memory array used internally by the vector to store its owned elements

### Modifiers
* ```void push_back(vector* main,void* data)``` - It pushes the elements into a vector from the back
* ```void pop_back(vector* main)``` - It is used to pop or remove elements from a vector from the back
* ```void insert(vector* main,const int* position,void* val)``` - It inserts new element before the element at the specified position
* ```void erase(vector* main,const int* position,const int* count)``` - It is used to remove count of elements from a container from the specified position
* ```void clear(vector* main)``` - It is used to remove all the elements of the vector container
* ```void emplace(vector* main,const int* position,void* val)``` - It extends the container by inserting new element at position
* ```void emplace_back(vector* main,void* val)``` - It is used to insert a new element into the vector container, the new element is added to the end of the vector
#include "library.h"
#include "stdio.h"

void constructor(vector* main,size_t type_of_data,size_t size){
    main->type_of_data=type_of_data;
    main->size=size;
    main->mass=(void*)malloc(type_of_data*size);
}
void push_back(vector* main,void* data){
    main->size++;
    main->mass=(void*) realloc(main->mass,main->size*main->type_of_data);
}
void* element_at(vector* main,int* index){
    return &main->mass[*index];
}
#include "library.h"
#include "stdio.h"

void constructor(vector* main,size_t size){
    main->size=size;
    main->mass=(void**)malloc(size*sizeof(void*));
}
void push_back(vector* main,void* data){
    main->size++;
    main->mass=(void**) realloc(main->mass,main->size*sizeof(void*));
    main->mass[main->size-1]=data;
}
void* element_at(vector* main,int* index){
    return main->mass[*index];
}
void clear(vector* main){
    for(int i=0;i<main->size;i++){
        free(main->mass[i]);
    }
    free(main->mass);
    main->size=0;
}
int empty(vector* main){
    if(main->size==0)
        return 0;
    else
        return 1;
}
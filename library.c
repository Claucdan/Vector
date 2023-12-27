#include "library.h"




void constructor(vector* main,size_t capacity){
    main->size=0;
    main->max_size=capacity;
    main->mass=(void**)malloc(capacity*sizeof(void*));
}

//Iterators

void* begin(vector* main){
    return main->mass[0];
}
void* end(vector* main){
    return main->mass[main->size-1];
}
const void* cbegin(vector* main){
    return main->mass[0];
}
const void* cend(vector* main){
    return main->mass[main->size-1];
}
bool empty(vector* main){
    if(main->size==0)
        return true;
    else
        return false;
}

//Capacity

size_t size(vector* main){
    return main->size;
}
size_t max_size(vector* main){
    return main->max_size;
}
void resize(vector* main,size_t new_size){
    main->max_size=new_size;
    if(new_size<main->size){
        for(int i=new_size;i<main->max_size;i++)
            free(main->mass[i]);
    }
    main->mass=(void**)realloc(main->mass,new_size);
    if(main->size>new_size)
        main->size=new_size;
}

//Element access

void* at(vector* main,const int* index){
    return main->mass[*index];
}
void* front(vector* main){
    return main->mass[0];
}
void* back(vector* main){
    return main->mass[main->size-1];
}
void** data(vector* main){
    return main->mass;
}

//Modifiers

void push_back(vector* main,void* data){
    if(main->size==main->max_size){
        main->max_size++;
        main->size++;
        main->mass=(void**) realloc(main->mass,main->max_size*sizeof(void*));
        main->mass[main->max_size-1]=data;
    }
    else{
        main->mass[main->size++]=data;
    }
}
void pop_back(vector* main){
    if(main->size!=0){
        main->size--;
        free(main->mass[main->size]);
        main->mass=(void**)malloc(sizeof(void*)*main->size);
    }
}
void insert(vector* main,const int* position,void* val){
    main->size++;
    if(main->size>main->max_size) {
        main->mass = (void **) realloc(main->mass, main->size);
        main->max_size++;
    }
    for(int i=main->size;i>*position;i++){
        main->mass[i]=main->mass[i-1];
    }
    main->mass[*position]=val;
}
void erase(vector* main,const int* position,const int* count){
    for(int i=*position;i<main->size-*count;i++){
        if(i<*position+*count)
            free(main->mass[i]);
        main->mass[i]=main->mass[i+*count];
    }
    main->size-=*count;
}
void clear(vector* main){
    for(int i=0;i<main->size;i++){
        free(main->mass[i]);
    }
    free(main->mass);
    main->size=0;
    main->max_size=0;
}
void emplace(vector* main,const int* position,void* val){
    main->max_size++;
    main->size++;
    main->mass=(void**)realloc(main->mass, main->max_size);
    for(int i=main->size;i>*position;i++){
        main->mass[i]=main->mass[i-1];
    }
    main->mass[*position]=val;
}
void emplace_back(vector* main,void* val){
    main->max_size++;
    main->size++;
    main->mass=(void**)realloc(main->mass, main->max_size);
    main->mass[main->size-1]=val;
}
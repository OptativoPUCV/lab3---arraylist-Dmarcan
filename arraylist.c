#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *list=(ArrayList *)malloc(sizeof(ArrayList));
  if (list==NULL) exit(EXIT_FAILURE);
  list->data=(void *)malloc(2 * sizeof(void *));
  if (list->data==NULL)
  {
    free(list);
    exit(EXIT_FAILURE);
  }

  list->capacity=2;
  list->size=0;
  return list;
}

void append(ArrayList * l, void * data){
  
  if (l->size==l->capacity)
  {
    l->capacity*=2;
    l->data=(void *)realloc(l->data,l->capacity  * sizeof(void *));
    if (l->data==NULL)
    {
      free(l);
      exit(EXIT_FAILURE);
    }
    
    l->data[l->size]=data;
    l->size++;
  }
  else
  {
    l->data[l->size]=data;
    l->size++; 
  }
}

void push(ArrayList * l, void * data, int i){
  size_t contador=l->size; 
  if (i<=l->size)
  {
    if (l->size==l->capacity)
    {
      l->capacity*=2;
      l->data=(void *)realloc(l->data,l->capacity  * sizeof(void *));
      if (l->data==NULL)
      {
        free(l);
        exit(EXIT_FAILURE);
      }
    }
    while (contador>i)
    {
      l->data[contador]=l->data[contador-1];
      contador--;
    }
    l->data[contador]=data;
    l->size++;
  }

}

void* pop(ArrayList * l, int i){
  if (l->size>1)
  {
    void* dato=l->data[i];
    size_t contador=i;
    while (contador<l->size)
    {
      l->data[contador]=l->data[contador+1];
      contador++; 
    }
    l->size--;
    return dato;
  }
  return NULL;
}

void* get(ArrayList * l, int i){
  if (i>=l->size)return NULL;
  if (i>=0) return l->data[i];
  else
  {
    i+=l->size;
    return l->data[i];
  }
  
}

int get_size(ArrayList * l){
    return l->size;
}
//remove elements
void clean(ArrayList * l){
  free(l->data);
  l->capacity=2;
  l->size=0;
  l->data=(void *)malloc(l->capacity * sizeof(void *));
  if (l->data==NULL)
  {
    free(l);
    exit(EXIT_FAILURE);
  }
}

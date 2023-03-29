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
/*Implemente la función `ArrayList *createList()`. Esta función crea un nuevo dato de tipo ArrayList inicializando sus variables. Considere que la capacidad incial es de 2 casillas para el arreglo.
   > Recuerde reservar memoria para el ArrayList y también para el arreglo dinámico `data`.
*/
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

}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}

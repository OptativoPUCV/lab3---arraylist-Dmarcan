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
/*
Implemente la función `void append(ArrayList * l, void * data)`. Esta función agrega el dato al final de la lista (es decir, en la posición `size`). 

    > Si el arreglo está lleno aumente la capacidad al **doble** usando la función `realloc` así:
    `data = realloc(data, nueva_capacidad)`

    > Recuerde aumentar el valor de la variable `size`.
*/
void append(ArrayList * l, void * data){
  
  if (l->size==l->capacity)
  {
    l->data=(void *)realloc(l->data,(l->capacity * 2) * sizeof(void *));
    if (l->data==NULL)
    {
      free(l);
      exit(EXIT_FAILURE);
    }
    
    l->data[l->size]=data;
    l->size++;
    l->capacity*=2;
  }
  else
  {
    l->data[l->size]=data;
    l->size++; 
  }
}
/*
Implemente la función `void push(ArrayList * l, void * data, int i)`. Esta función ingresa el dato en la `i`-ésima posición de la lista (`i=0` es la primera posición). 

    > Si el arreglo está lleno, primero debe aumentar su capacidad al doble.

    > Recuerde mover los elementos siguientes una casilla a la derecha.

    > Si `i` es mayor a `size`, la función no debe hacer nada.
*/

void push(ArrayList * l, void * data, int i){
  size_t contador=l->size; 
  if (i<=l->size)
  {
    if (l->size==l->capacity)
    {
      l->data=(void *)realloc(l->data,(l->capacity * 2) * sizeof(void *));
      if (l->data==NULL)
      {
        free(l);
        exit(EXIT_FAILURE);
      }
      l->capacity*=2;
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
    return NULL;
}
/*
  Implemente la función `void* get(ArrayList * l, int i)`. Esta función retorna el dato de la posición `i` de la lista. Si `i>=size`, entonces retorna NULL. Además, si `i<0` los valores son obtenidos desde el final hacia el principio de la lista.
*/
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
    
}

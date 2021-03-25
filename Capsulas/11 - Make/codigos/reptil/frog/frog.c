// Incluimos los header files correspondientes
#include "frog.h"

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Definimos el inicializador de Frog
Frog* frog_init(char* name, float speed, int age, int jump_height)
{
  // Pedimos memoria para Frog
  Frog* frog = malloc(sizeof(Frog));

  // Lo inicializamos
  *frog = (Frog){
    .parent = reptil_init(name, speed, age),
    .jump_height = jump_height
  };

  // Lo retornamos
  return frog;
}

// Definimos el impresor de Frog
void frog_print(Frog* frog)
{
  printf("Frog %s:\n", frog->parent->name);
  printf("\tage         = %i yrs\n", frog->parent->age);
  printf("\tspeed       = %f m/s\n", frog->parent->speed);
  printf("\tjump_heihgt = %i m\n", frog->jump_height);
}

// Definimos el destructor de Frog
void frog_destroy(Frog *frog)
{
  // Primero liberamos a Reptil
  reptil_destroy(frog->parent);

  // Luego a Frog
  free(frog);
}
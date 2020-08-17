// Incluimos los header files correspondientes
#include "reptil.h"

// Incluimos standard I/O y standard library
#include <stdlib.h>

// Definimos el inicializador de Reptil
Reptil* reptil_init(char* name, float speed, int age)
{
  // Pedimos memoria para Reptil
  Reptil* reptil = malloc(sizeof(Reptil));

  // Lo inicializamos
  *reptil = (Reptil){
    .name = name,
    .speed = speed,
    .age = age
  };

  // Lo retornamos
  return reptil;
}


// Definimos el destructor de Reptil
void reptil_destroy(Reptil *reptil)
{
  free(reptil);
}
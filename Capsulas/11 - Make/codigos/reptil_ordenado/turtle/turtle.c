// Incluimos los header files correspondientes
#include "turtle.h"

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Definimos el inicializador de turtle
Turtle* turtle_init(char* name, float speed, int age, int shell_hardness)
{
  // Pedimos memoria para turtle
  Turtle* turtle = malloc(sizeof(Turtle));

  // Lo inicializamos
  *turtle = (Turtle){
    .parent = reptil_init(name, speed, age),
    .shell_hardness = shell_hardness
  };

  // Lo retornamos
  return turtle;
}

// Definimos el impresor de Turtle
void turtle_print(Turtle* turtle)
{
  printf("Turtle %s:\n", turtle->parent->name);
  printf("\tage            = %i yrs\n", turtle->parent->age);
  printf("\tspeed          = %f m/s\n", turtle->parent->speed);
  printf("\tshell_hardness = %i m\n", turtle->shell_hardness);
}

// Definimos el destructor de turtle
void turtle_destroy(Turtle *turtle)
{
  // Primero liberamos a Reptil
  reptil_destroy(turtle->parent);

  // Luego a turtle
  free(turtle);
}
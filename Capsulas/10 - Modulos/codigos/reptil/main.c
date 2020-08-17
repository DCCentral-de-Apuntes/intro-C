// Instrucciones de uso:
//
// En este caso tenemos una modelacion mucho mas compleja, pero para efectos
// de probar su funcionamiento podemos compilar directamente todos los .c
//
// gcc reptil.c frog.c snake.c turtle.c main.c -o main
// ./main

// Incluimos a los reptiles
#include "frog.h"
#include "snake.h"
#include "turtle.h"

// Incluimos standard library
#include <stdio.h>


int main(int argc, char** argv)
{
  // Creamos uno de cada reptil
  Frog* frog = frog_init("Charly", 12.25, 1, 10);
  Turtle* turtle = turtle_init("Fred", 0.005, 250, 1000);
  Snake* snake = snake_init("Snek", 5, 2, 2);

  // Imprimimos sus datos
  frog_print(frog);
  turtle_print(turtle);
  snake_print(snake);

  // Liberamos memoria
  frog_destroy(frog);
  turtle_destroy(turtle);
  snake_destroy(snake);

  return 0;
}

// Instrucciones de uso:
//
// make
// ./main

// Incluimos a los reptiles con path relativo
#include "frog/frog.h"
#include "snake/snake.h"
#include "turtle/turtle.h"

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

// Instrucciones de uso:
//
// Este ejemplo es exactamente el mismo que reptil_ordenado, solo que con una
// diferencia clave. El "#pragma once" en reptil.h esta comentado, por lo cual
// no podremos compilar.
//
// Este error puede ser dificil de entender si no se ha visto antes, por lo cual
// siempre hay que recordar usar "#pragma once" en los header files
//
// gcc reptil/reptil.c frog/frog.c snake/snake.c turtle/turtle.c main.c -o main
// F

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

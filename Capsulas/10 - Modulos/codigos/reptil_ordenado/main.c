// Instrucciones de uso:
//
// Tene todos los archivos en la misma carpeta es en extremo desordenado y poco
// escalable, asi que usualmente se tiene una carpeta por .c y .h, o por grupo
// de .c y .h relacionados
//
// Nuevamente, lo mas correcto seria compilar individualmente cada object file
// pero para efectos de probar el programa podemos compilar directamente
//
// gcc reptil/reptil.c frog/frog.c snake/snake.c turtle/turtle.c main.c -o main
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

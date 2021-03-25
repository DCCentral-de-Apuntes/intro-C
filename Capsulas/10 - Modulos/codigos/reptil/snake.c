// Incluimos los header files correspondientes
#include "snake.h"

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Definimos el inicializador de Snake
Snake* snake_init(char* name, float speed, int age, int length)
{
  // Pedimos memoria para Snake
  Snake* snake = malloc(sizeof(Snake));

  // Lo inicializamos
  *snake = (Snake){
    .parent = reptil_init(name, speed, age),
    .length = length
  };

  // Lo retornamos
  return snake;
}

// Definimos el impresor de Snake
void snake_print(Snake* snake)
{
  printf("Snake %s:\n", snake->parent->name);
  printf("\tage    = %i yrs\n", snake->parent->age);
  printf("\tspeed  = %f m/s\n", snake->parent->speed);
  printf("\tlength = %i m\n", snake->length);
}

// Definimos el destructor de Snake
void snake_destroy(Snake *snake)
{
  // Primero liberamos a Reptil
  reptil_destroy(snake->parent);

  // Luego a Snake
  free(snake);
}
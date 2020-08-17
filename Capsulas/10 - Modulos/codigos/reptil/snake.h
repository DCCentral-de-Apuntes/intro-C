// Empezamos el header file con pragma once
#pragma once

// Inlcuimos reptil
#include "reptil.h"

// Definimos el struct snake
typedef struct snake {
  Reptil* parent;  // Esto es para simular herencia
  int length;
} Snake;

// Definimos las funciones de uso externo
Snake* snake_init(char* name, float speed, int age, int length);
void snake_print(Snake* snake);
void snake_destroy(Snake *snake);
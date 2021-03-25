// Empezamos el header file con pragma once
#pragma once

// Inlcuimos reptil con path relativo
#include "../reptil/reptil.h"

// Definimos el struct turtle
typedef struct turtle {
  Reptil* parent;  // Esto es para simular herencia
  int shell_hardness;
} Turtle;

// Definimos las funciones de uso externo
Turtle* turtle_init(char* name, float speed, int age, int shell_hardness);
void turtle_print(Turtle* turtle);
void turtle_destroy(Turtle *turtle);

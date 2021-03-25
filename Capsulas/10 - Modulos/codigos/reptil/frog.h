// Empezamos el header file con pragma once
#pragma once

// Inlcuimos reptil
#include "reptil.h"

// Definimos el struct frog
typedef struct frog {
  Reptil* parent;  // Esto es para simular herencia
  int jump_height;
} Frog;

// Definimos las funciones de uso externo
Frog* frog_init(char* name, float speed, int age, int jump_height);
void frog_print(Frog* frog);
void frog_destroy(Frog *frog);

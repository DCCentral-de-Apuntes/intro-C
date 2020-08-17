// Empezamos el header file con pragma once
// #pragma once

// Definimos el struct reptil
typedef struct reptil {
  char* name;
  float speed;
  int age;
} Reptil;

// Definimos las funciones de uso externo
Reptil* reptil_init(char* name, float speed, int age);
void reptil_destroy(Reptil *reptil);

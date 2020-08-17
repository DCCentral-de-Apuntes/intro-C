// Empezamos el header file con pragma once
#pragma once

// Incluimos standard I/O, standard library y standard bool
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// En este archivo veremos un ejemplo de uso de structs con modelacion orientada
// a objetos (OOM)

// Primero debemos definir el struct
typedef struct dog
{
  char* name;
  int age;
  bool good_boy;
  struct dog* friend;
} Dog;
// El nombre final es Dog

// Declaramos funciones de uso externo
Dog* dog_init(char* name, int age);
void dog_print(Dog* dog);
void dog_bark(Dog* dog);
void dog_meet(Dog* dog, Dog* friend);
void dog_destroy(Dog* dog);
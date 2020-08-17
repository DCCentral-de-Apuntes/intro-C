// Instrucciones de uso:
//
// gcc leak_def.c -g -o leak_def
// valgrind --leak-check=full ./leak_def

// Incluimos standard library
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Aqui pedimos 1337 bytes
  char* A = malloc(1337 * sizeof(char));

  // Como el programa termina sin liberarlo, el puntero se pierde
  // y tenemos 1337 bytes perdidos definitivamente en un bloque

  return 0;
}
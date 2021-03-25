// Instrucciones de uso:
//
// gcc leak_pos.c -g -o leak_pos
// valgrind --leak-check=full ./leak_pos

// Incluimos standard library
#include <stdlib.h>

// Definimos C como una variable global
int *C;

int main(int argc, char** argv)
{
  // Guardamos en C un puntero modificado que apunta a 40 bytes
  C = malloc(10 * sizeof(int)) + 1;

  // Aqui valgrind no tiene ni la más mínima idea de si la memoria esta
  // perdida o no, por lo cual nos dira que tenemos 40 bytes posiblemente
  // perdidos en un bloque

  return 0;
}

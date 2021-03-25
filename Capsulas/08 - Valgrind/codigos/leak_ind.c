// Instrucciones de uso:
//
// gcc leak_ind.c -g -o leak_ind
// valgrind --leak-check=full ./leak_ind

// Incluimos standard library
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Pedimos 80 bytes (punteros son de tamaño 8)
  int** B = malloc(10 * sizeof(int*));

  // Iteramos de 0 a 9
  for(int i = 0; i < 10; i+=1)
  {
    // Pedimos 40 bytes, en total 400, ya que iteramos 10 veces.
    B[i] = malloc(10 * sizeof(int));
  }

  // Como no liberamos B se pierden esos 80 bytes definitivamente en un bloque.
  // Como B tenia punteros en el heap, estos perdieron su unica referencia, asi
  // que perdimos esos 400 bytes indirectamente en 10 bloques

  return 0;
}
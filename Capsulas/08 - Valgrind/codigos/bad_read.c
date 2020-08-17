// Instrucciones de uso:
//
// gcc bad_read.c -g -o bad_read
// valgrind ./bad_read

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Pedimos 40 bytes
  int* G = malloc(10 * sizeof(int));

  // Iteramos de 0 a 9
  for(int i = 0; i < 10; i+=1)
  {
    // Aqui ocurre un bad read, ya que cuando i=0, estamos indexando G[-1]
    G[i] = i * i + G[i - 1];
  }

  // Liberamos los 40 bytes
  free(G);

  return 0;
}
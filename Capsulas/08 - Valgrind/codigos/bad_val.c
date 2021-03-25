// Instrucciones de uso:
//
// gcc bad_val.c -g -o bad_val
// valgrind ./bad_val

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Pedimos 4 bytes
  int* E = malloc(sizeof(int));

  // Aqui estamos accediento a E antes de inicializarlo
  if (*E > 10)
  {
    printf("Hi there!\n");
  }

  // Liberamos 4 bytes
  free(E);

  return 0;
}
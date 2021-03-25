// Instrucciones de uso:
//
// gcc bad_write.c -g -o bad_write
// valgrind ./bad_write

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  // Pedimos 40 bytes
  int* F = calloc(10, sizeof(int));

  // Iteramos de 0 a 10 debido al <=, por lo cual nos salimos del arreglo
  for(int i = 0; i <= 10; i+=1)
  {
    // En la última interación haremos una escritura inválida a F[10] de 
    // tamaño 4, ya que estamos escribiendo un int
    F[i] = i * i;
  }

  // Libreamos 40 bytes
  free(F);

  return 0;
}
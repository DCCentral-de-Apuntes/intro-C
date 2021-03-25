// Instrucciones de uso:
//
// gcc argumentos_2.c -o argumentos_2
// ./argumentos_2 HelloWorld! 4

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Este programa recibe un string y un numero e imprime el string esa cantidad
// de veces
int main(int argc, char** argv)
{
  // Es buena costumbre extraer en variables argv

  // Un string puede ser extraido directamente
  char *string = argv[1]; // Ojo, que el indice 0 es el nombre del ejecutable

  // Para un int debemos utilizar atoi
  int times = atoi(argv[2]);

  // Iteramos times veces
  for (int i = 0; i < times; i+=1)
  {
    // Imprimimos el string
    printf("%s ", string);
  }
  printf("\n");

  return 0;
}

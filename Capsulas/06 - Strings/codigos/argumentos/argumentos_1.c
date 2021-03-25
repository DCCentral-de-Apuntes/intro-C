// Instrucciones de uso:
//
// gcc argumentos_1.c -o argumentos_1
// ./argumentos_1 argumentos de ejemplo

// Incluimos standard I/O
#include <stdio.h>

// Recordar lo más simple que podemos hacer con los argumentos
// iterarlos haciendo uso de argc
int main(int argc, char** argv)
{
  // Imprimimos la cantidad de argumentos
  printf("Arguments (%i):\n", argc);

  // Iteramos de 0 a argc - 1
  for (int i = 0; i < argc; i+=1)
  {
    // Imprimimos cada argumento
    printf("\t%s\n", argv[i]);
  }

  return 0;
}
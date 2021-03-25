// Instrucciones de uso:
//
// gcc leak_stl.c -g -o leak_stl
// valgrind --leak-check=full --show-leak-kinds=all ./leak_stl

// Incluimos standard library
#include <stdlib.h>

// Definimos C como una variable global
int *C;

int main(int argc, char** argv)
 {
   // Guardamos en C un puntero de 40 bytes
   C = malloc(10 * sizeof(int));

   // Como no liberamos C y este es una variable global, valgrind detectará
   // que todavía tenemos una referencia a ella, por lo cual es 40 bytes
   // still reachable en un bloque
  
   return 0;
 }

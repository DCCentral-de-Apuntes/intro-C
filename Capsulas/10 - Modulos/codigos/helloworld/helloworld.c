// Instrucciones de uso:
// 
// Este es el programa mas simple que podemos llegar a tener. No tiene nignuna
// dependencia local asi  que podemo compilarlo directamente.
//
// gcc helloworld.c -o helloworld
// ./helloworld

// Incluimos standard I/O
#include <stdio.h>

// Función main, es la que se ejecuta cuando el programa es ejecutado.
int main(int argc, char** argv)
{
  // Función de stdio que nos permite mostrar cosas en consola.
  printf("Hello world!\n");

  // Código de retorno del programa.
  return 0;
}

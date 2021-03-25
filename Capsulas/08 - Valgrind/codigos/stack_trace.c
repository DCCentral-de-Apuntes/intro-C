// Instrucciones de uso:
//
// gcc stack_trace.c -g -o stack_trace
// valgrind --leak-check=full ./stack_trace

// Incluimos standard library
#include <stdlib.h>

// En esta funcion ocurre un leak de 4 bytes, sera la penultima funcion
// del trace, la última usualmente es calloc o malloc
int* p()
{
  return malloc(sizeof(int));
}

// Esta funcion llama a la funcion con leak, estara a la mitad del trace
int* q()
{
  return p();
}

// El main siempre es la primera funcion, po lo cual siempre esta al inicio
// del trace
int main(int argc, char** argv)
{
  int* H = q();
  return 0;
}
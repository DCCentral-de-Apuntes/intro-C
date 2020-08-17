// Instrucciones de uso:
//
// gcc heap.c -o heap
// ./heap

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  // En términos prácticos, usar el heap en C, se reduce a pedir memoria con
  // calloc y malloc y liberarla con free. Como estas funciones nos retornan
  // punteros, podemos interactuar con ellas como si fueran arrays comunes y
  // corrientes

  // Ejemplo de malloc
  // Pidamos memoria para un solo int
  int *a = malloc(sizeof(int));

  // En el caso de malloc, antes de utilizarlo hay que inicializarlo
  *a = 5;


  // Ejemplo de calloc
  // Pidamos memoria para un solo int
  int *b = calloc(1, sizeof(int));

  // A diferencia de malloc, es inicializado en 0
  // Comparemos
  printf("Malloc v/s Calloc:\n");
  printf("\ta = %i\n", *a);
  printf("\tb = %i\n", *b);

  // Hay que recordar liberar la memoria pedida
  free(a);
  free(b);


  // Arrays
  // Para arrays se prefiere con creces calloc ya que la nomenclatura es mas
  // clara en cuantos elementos tiene el array y lo inicializa en 0
  float *C = calloc(5, sizeof(int));
  C[2] = 1.25345321;
  C[4] = 2141.123123;

  printf("\nCalloc:\n\tC = [");
  for (int i = 0; i < 5; i+=1)
  {
    printf("%f, ", C[i]);
  }
  printf("]\n");

  // Hay que recordar liberar la memoria pedida
  free(C);


  // Arrays de arrays
  // Arrays de arrays no es mas un array de punteros donde esos punteros son
  // los arrays que acabamos de ver

  // Primero pedimos memoria para un array de punteros
  int **D = calloc(2, sizeof(int*));

  // Segundo, por cada puntero en el array pedimos memoria para el sub array
  D[0] = calloc(3, sizeof(int));
  D[1] = calloc(3, sizeof(int));

  // Finalmente, funciona exactamente que un arreglo de arreglos en el stack
  D[0][2] = 1;
  D[1][0] = 12;
  D[1][1] = 27;

  printf("\nArray de Arrays:\n\tD = [\n");
  for (int i = 0; i < 2; i+=1)
  {
    printf("\t\t[");
    for (int j = 0; j < 3; j++)
    {
      printf("%i, ", D[i][j]);
    }
    printf("]\n");
  }
  printf("\t]\n");

  // Hay que recordar liberar la memoria pedida
  // Primero los sub arrays
  free(D[0]);
  free(D[1]);

  // Despues el array principal
  free(D);

  return 0;
}
// Instrucciones de uso:
//
// gcc heap_y_funciones.c -o heap_y_funciones
// ./heap_y_funciones

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Funcion que recibe un arreglo de numeros y retorna una copia exacta en el
// heap
int *array_copy(int *array, int n)
{
  // Creamos la copia
  int *copy = calloc(n, sizeof(int));

  // La reellenamos
  for (int i = 0; i < n; i+=1)
  {
    copy[i] = array[i];
  }

  // La retornamos
  return copy;
}

int main(int argc, char** argv)
{
  // Gracias al heap podemos hacer funciones que nos retornen arreglo lo cual
  // hace que nuestras posibilidades sean aún mayores

  // Ejemplo de uso de array_copy
  // Definimos el arreglo original
  int A[5] = {12, 25, 3, 2, 15};

  // Guardamos el retorno en un puntero
  int *B = array_copy(A, 5); 

  // Imprimimos el resultado
  printf("Array copy:\n\tA = [");
  for (int i = 0; i < 5; i+=1)
  {
    printf("%i, ", A[i]);
  }
  printf("]\n");  

  printf("\tB = [");  
  for (int i = 0; i < 5; i+=1)
  {
    printf("%i, ", B[i]);
  }
  printf("]\n");  

  // Podemos ver que efectivamente se creo una copia exacta!
  // Hay que recordar hacer free por supuesto
  free(B);

  // Gracias al heap se nos abre la posibilidad de retornar un puntero
  // a lo que queramos dentro de uan funcion, lo cual hace que estas sean
  // extremadamente flexibles, solo hay que recordar los free.

  return 0;
}
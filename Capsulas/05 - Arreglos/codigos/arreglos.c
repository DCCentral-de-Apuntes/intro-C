// Instrucciones de uso:
//
// gcc arreglos.c -o arreglos
// ./arreglos

// Incluimos standard I/O 
#include <stdio.h>


int main(int argc, char** argv)
{
  // Ejemplo de declaracion de arreglos
  // Arreglo de ints
  int A[3] = {0, 2, 5};

  // Arreglo de arreglos de ints
  int B[3][2] = {{1, 2}, {3, 2}, {1, 5}}; 

  // Arreglo de arreglos de arreglos de ints
  int C[3][2][2] = {
    {{1, 2}, {15, 3}},  
    {{7, 5}, {25, -5}},  
    {{12, 45}, {0, 5}},  
  };

  // Etc. Sigue exactamente el mismo patrón que Python.
  
  // Ejemplo de indexación
  // La indexación es bastante directa
  printf("A[0]:       %i, A[2]:       %i\n", A[0], A[2]);
  printf("B[0][1]:    %i, B[1][0]:    %i\n", B[0][1], B[1][0]);
  printf("C[2][1][1]: %i, C[0][1][0]: %i\n", C[2][1][1], C[0][1][0]);

  // La iteración tambien
  // Imprimimos A
  printf("\nA = [");
  for (int i = 0; i < 3; i+=1)
  {
    printf("%i, ", A[i]);
  }
  printf("]\n");

  // Imprimimos B
  printf("\nB = [\n");
  for (int i = 0; i < 3; i+=1)
  {
    printf("\t[");
    for (int j = 0; j < 2; j+=1)
    {
      printf("%i, ", B[i][j]);
    }
    printf("],\n");
  }
  printf("]\n");

  // Imprimimos C
  printf("\nC = [\n");
  for (int i = 0; i < 3; i+=1)
  {
    printf("\t[\n");
    for (int j = 0; j < 2; j+=1)
    {
      printf("\t\t[");
      for (int k = 0; k < 2; k+=1)
      {
        printf("%i, ", C[i][j][k]);
      }
      printf("],\n");
    }
    printf("\t],\n");
  }
  printf("]\n");

  // ¿Que pasa si iteramos mal?
  printf("Iterando A de 0 a 30:\n");
  for (int i = 0; i <= 30; i+=1)
  {
    printf("\tA[%i] = %i\n", i, A[i]);
  }
  
  // Podemos ver que imprimimos tanto A como B como C, ya que estan contiguos
  // en el stack, y despues de eso imprimimos solo ruido. Ojo, que podrian haber
  // direcciones entre A y B y C con ruido, ya que el compilador puede hacer
  // algunas optimizaciones de espacio.
  return 0;
}
// Instrucciones de uso:
//
// gcc arreglos_cursed.c -o arreglos_cursed
// ./arreglos_cursed

// Incluimos standard I/O
#include <stdio.h>


int main(int argc, char** argv)
{
  int A[3] = {0, 2, 5};
  int B[3][2] = {{1, 2}, {3 , 2}, {1, 5}}; 
  int C[3][2][2] = {
    {{1, 2}, {15, 3}},  
    {{7, 5}, {25, -5}},  
    {{12, 45}, {0, 5}},  
  };

  // El operador "[]" es conmutativo ;)
  printf("A[0]:       %i, A[2]:       %i\n", 0[A], 2[A]);
  printf("B[0][1]:    %i, B[1][0]:    %i\n", 0[B][1], 1[B][0]);
  printf("C[2][1][1]: %i, C[0][1][0]: %i\n", 2[C][1][1], 0[C][1][0]);

  printf("\nA = [");
  for (int i = 0; i < 3; i+=1)
  {
    printf("%i, ", i[A]);
  }
  printf("]\n");

  printf("\nB = [\n");
  for (int i = 0; i < 3; i+=1)
  {
    printf("\t[");
    for (int j = 0; j < 2; j+=1)
    {
      printf("%i, ", i[B][j]);
    }
    printf("],\n");
  }
  printf("]\n");

  printf("\nC = [\n");
  for (int i = 0; i < 3; i+=1)
  {
    printf("\t[\n");
    for (int j = 0; j < 2; j+=1)
    {
      printf("\t\t[");
      for (int k = 0; k < 2; k+=1)
      {
        printf("%i, ", i[C][j][k]);
      }
      printf("],\n");
    }
    printf("\t],\n");
  }
  printf("]\n");

  printf("Iterando A de 0 a 30:\n");
  for (int i = 0; i <= 30; i+=1)
  {
    printf("\tA[%i] = %i\n", i, i[A]);
  }
  
  return 0;
}
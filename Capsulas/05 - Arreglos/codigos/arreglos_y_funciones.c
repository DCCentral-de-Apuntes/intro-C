// Instrucciones de uso:
//
// gcc arreglos_y_funciones.c -o arreglos_y_funciones
// ./arreglos_y_funciones

// Incluimos standard I/O
#include <stdio.h>

// Funcion que imprime un arreglo como una lista
void array_print(int* A, int n)
{
  printf("[");
  for (int i = 0; i < n - 1; i+=1)
  {
    printf("%i, ", A[i]);
  }
  printf("%i]\n", A[n - 1]);
}

// Funcion recibe dos arreglos del mismo largo y nos calcula el 
// promedio de su diferencia
float avg_diff(int* A, int* B, int n)
{
  float diff = 0;  // Ojo, si fuera int no funcionaría!
  for (int i = 0; i < n; i+=1)
  {
    diff += A[i] - B[i];
  }
  return diff / n;
}

// Funcion que recibe dos arreglos y copia el contenido de uno al otro.
// Si bien no podemos retornar arreglos al stack, si podemos modificarlo
// en la función.
void array_copy(int* from, int* to, int n)
{
  for (int i = 0; i < n; i+=1)
  {
    to[i] = from[i];
  }
}

int main(int argc, char** argv)
{
  // Si bien las restricciones de no poder retornar areglos en funciones
  // parece algo duro, es solo Python malcriandonos, de todas formas
  // podemos obtener código limpio y eficiente a pesar de esto.

  // Definamos dos arreglos y declaremos uno
  int A[5] = {2, -1, 15, 4, 12};
  int B[5] = {7, 2, -12, 5, 11};
  int C[5];

  // Imprimamos los tres arreglos
  array_print(A, 5);
  array_print(B, 5);
  array_print(C, 5); // ¿Que va a pasar?

  // Como vemos, A y B se imprimen bien mientras que C al no estar inciializado
  // contiene ruido.

  // Probemos nuestra funciones ahora
  printf("\nAVG DIFF A B: %f\n", avg_diff(A, B, 5));

  printf("Copying B to C...\n");
  array_copy(B, C, 5);
  
  printf("AVG DIFF A C: %f\n", avg_diff(A, C, 5));

  return 0;
}

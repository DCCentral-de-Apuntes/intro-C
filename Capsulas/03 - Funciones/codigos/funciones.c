// Instrucciones de uso:
//
// gcc funciones.c -o funciones
// ./funciones

// Incluimos standard I/O
#include <stdio.h> 

// Imprime Hello World! y no retorna nada.
void hello()
{
  printf("Hello World!\n");
}

// Imprime números pares menores a n y no retrona nada.
void even_less_n(int n) 
{
  for (int i = 0; i < n; i += 2)
  {
    printf("%d ", i);
  }
  printf("\n");
}

// Calcula promedio entre 3 float.
float avg_3(float a, float b, float c)
{
  return (a + b + c) / 3;
}

int main(int argc, char** argv)
{
  hello();  // Imprimimos Hello World!
  even_less_n(7);  // Imprimimos pares menores a 7.
  
  // Podemos guardar el resultado de una funcion en una variable y
  // también podemos pasarla directamente a otra función.
  // Esta función recibe floats y hará casting implicito de los parámetros que le demos
  float n = avg_3(12.5, 2, 5.2);
  printf("%f = %f\n", n, avg_3(12.5, 2, 5.2));  // Podemos ingresar el llamado a la funcion directamente.

}

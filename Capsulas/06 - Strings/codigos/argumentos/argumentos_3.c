// Instrucciones de uso:
//
// gcc argumentos_3.c -o argumentos_3
// ./argumentos_3 12 3.5 1 0.5 -2 15.2 -5.325

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Este programa recibe una serie de numeros y calcula el promedio entre ellos
// pueden ser tanto ints como floats
int main(int argc, char** argv)
{
  // Necesitamos un array de tamaño argc - 1 y como el input puede ser float
  // o int, utilizamos float
  float numbers[argc - 1];

  // Luego, iteramos la parte de argv que contiene los numeros y los guardamos
  for (int i = 1; i < argc; i+=1)
  {
    // Como el input es float o int, utilizamos atof
    numbers[i - 1] = atof(argv[i]);
  }
  
  // Finalmente calculamos el promedio
  // Si queremos ser completamente correctos, podriamos hacer esto dentro de
  // una funcion
  float avg = 0;
  for (int i = 0; i < argc - 1; i+=1)
  {
    avg += numbers[i];
  }
  avg /= argc - 1;
  printf("AVG IS %f\n", avg);

  return 0;
}
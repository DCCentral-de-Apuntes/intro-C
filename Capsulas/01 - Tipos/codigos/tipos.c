// Instrucciones de uso:
//
// gcc tipos.c -o tipos
// ./tipos

// Incluimos standard I/O
#include <stdio.h>

int main(int argc, char** argv)
{
  // Ejemplo de uso de printf
  printf("Hola! Mi nombre es %s tengo %d años y mido %f centímetros.\n\n", "Javier", 22, 1.76);

  printf("Si no pongo '\\n'");
  printf("Los printf estarán pegados.\n\n");

  // Ejemplo de uso de int
  int a = 15;
  int b = a * 2;
  printf("%d < %d\n\n", a, b);

  // Ejemplo de uso de float
  float c = 1.25;
  float d = 1.3;
  printf("c + d = %f\n\n", c + d);

  // Ejemplo de uso de double
  double e = 1.123456789;
  printf("%lf\n\n", e);

  // Ejemplo de uso de char
  char f = 'f';
  f = f - 32;  // Por casting implicito podemos tratar char como un número
  printf("%c\n\n", f);

  // Ejemplo de uso de casting
  double g = 5 / 2;
  double h = (double) 5 / 2;
  printf("%lf v/s %lf\n", g, h);

  // El formato de printf fuerza casting
  char F_char = 'F';
  int F_int = 70;
  printf("%d == %c\n", F_char, F_int);

  return 0;
}

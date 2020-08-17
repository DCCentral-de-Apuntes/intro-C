// Instrucciones de uso:
//
// gcc stack.c -o stack
// ./stack

// Incluimos standard I/O y standard int
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv)
{
  // Definamos dos variables en el stack
  char a = 'a';
  char b = 'b';

  // Podemos obserbar que efectivamente se encuentran una después de otra
  // en el stack.
  printf("char y STACK:\n");
  printf("\tDirecciones:\n\t\ta: %p\n\t\tb: %p\n", &a, &b);
  
  // Esto nos quiere decir que estan a una dirección de memoria de distancia.
  printf("\tDiferencia: %ld\n", &b - &a);
  
  // Veamos a cuantos bytes de distancia están.
  printf("\tDiferencia en bytes: %ld (%zu)\n\n", (uint64_t) &b - (uint64_t) &a, sizeof(char));

  // Efectivamente los números calzan. Probemos con int:
  int c = 2;
  int d = 7;
  printf("int y STACK:\n");
  printf("\tDirecciones:\n\t\tc: %p\n\t\td: %p\n", &c, &d);
  printf("\tDiferencia: %ld\n", &d - &c);
  printf("\tDiferencia en bytes: %ld (%zu)\n\n", (uint64_t) &d - (uint64_t) &c, sizeof(int)); 

  // Tambien calzan los números!, Probemos finalmente con double:
  double e = 1.25;
  double f = 2.35;
  printf("double y STACK:\n");
  printf("\tDirecciones:\n\t\te: %p\n\t\tf: %p\n", &e, &f);
  printf("\tDiferencia: %ld\n", &f - &e);
  printf("\tDiferencia en bytes: %ld (%zu)\n\n", (uint64_t) &f - (uint64_t) &e, sizeof(double)); 

  // Más aún, podemos ver que entre b y c, y d y e tambien calza
  printf("Diferencia b, c: %ld (%zu)\n", (uint64_t) &c - (uint64_t) &b, sizeof(char)); 
  printf("Diferencia d, e: %ld (%zu)\n\n", (uint64_t) &e - (uint64_t) &d, sizeof(int)); 

  // b y c estan a sizeof(char) bytes de distancia, por que b es un char.
  // e y d estan a sizeof(int) bytes de distancia pooroque e es un int.

  // ¿Que pasara si imprimimos la dirección de la función main?
  printf("Direccion función main: %p\n", &main);
  // Está antes que el stack, tal como debiése ser!

  return 0;
}
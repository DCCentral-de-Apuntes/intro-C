// Instrucciones de uso:
//
// gcc strings_1.c -o strings_1
// ./strings_1

// Incluimos standard I/O
#include <stdio.h>

int main(int argc, char** argv)
{
  // Definamos algunos strings mal
  
  // Explicitamente sin null terminator
  char a[5] = {'V', 'o', 'y', ' ', 'a'};
  char b[5] = {'p', 'a', 's', 'a', 'r'};

  // Implicitamente sin null terminator
  char c[8] = "de largo";
  char d[16]  = "lamentablemente.";

  // Ahora definamos algunos strings bien

  // Explicitamente con null terminator
  char e[23] = {
    'E', 's', 't', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', 'e', 's', ' ',
    'v', 'a', 'l', 'i', 'd', 'o', '.', '\0'
  };

  // Implicitamente con null terminator
  char f[] = "Este string tamien es valido!";

  // Imprimamoslos uno por uno para ver que pasa
  printf("Strings y Null Terminator:\n");
  printf("\ta: %s\n", a);
  printf("\tb: %s\n", b);
  printf("\tc: %s\n", c);
  printf("\td: %s\n", d);
  printf("\te: %s\n", e);
  printf("\tf: %s\n", f);

  // Podemos ver que a b, c y d pasan de largo hasta e porque recien este tiene
  // null terminator. En cambio, e y f se imprimen correctamente.

  return 0;
}
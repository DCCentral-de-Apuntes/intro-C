// Instrucciones de uso:
//
// gcc punteros.c -o punteros
// ./punteros

// Incluimos standard I/O
#include <stdio.h>


// Cambia un int por valor, recibe y retorna int.
int change_by_value(int n, int delta)
{
  return n + delta;
}


// Cambia un int por "referencia" recibe un int* y un int y no retorna nada.
void change_by_reference(int* n, int delta)
{
  *n += delta;
}


int main(int argc, char** argv)
{
  // Definamos una varible, un puntero a esta y un puntero a ese puntero.
  int a = 5;
  int *b = &a;
  int **c = &b;

  // Podemos ver que b efectivamente apunta hacia a y c hacia b.
  printf("b -> a:      %p = %p\n", b, &a);
  printf("c -> b:      %p = %p\n", c, &b);
  printf("c -> b -> a: %p = %p\n", *c, &a);  // Nótese que el valor de c es un puntero.

  // Podemos ver también que el contenido es correcto.
  printf("\na   = %d\n*b  = %d\n**c = %d\n", a, *b, **c);

  // Como tanto c y b apuntan hacia a, podemos modificar a dede ambos.
  *b = -7;
  **c += 17;
  printf("\na   = %d\n*b  = %d\n**c = %d\n", a, *b, **c);

  // Usualmente para modificar a mediante una funcion hariamos un paso por valor.
  a = change_by_value(a, 10);
  printf("\na   = %d\n", a);

  // Pero gracias a punteros podemos hacerlo por "referencia".
  // Podemos utilizar tanto la direccion de a directamente, o un puntero
  change_by_reference(&a, -10);  // &a es la dir de a.
  change_by_reference(b, -5);    // b apunta hacia a.
  change_by_reference(*c, -5);   // c apunta hacia b, quien apunta hacia a.
  printf("a   = %d\n", a);

  return 0;
}
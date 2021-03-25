// Instrucciones de uso:
//
// gcc aritmetica.c -o aritmetica
// ./aritmetica

// Incluimos standard I/O y standard int
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv)
{
  // Definamos una serie de varibales
  char a = 'a';
  char b = 'b';
  int c = 2;
  int d = 7;
  double e = 1.25;
  double f = 2.35;

  // Por como estas están definidas, están todas contiguas en el stack,
  // a y b, c y d, e y f están a "distancia" uno entre ellas, mientras que
  // las demás distancias no son claras.
 
  // Veamos esto con aritmética de punteros:
  printf("Aritmética, sumar 1:\n");
  printf("\t&a + 1, &b = %p, %p\n", &a + 1, &b);
  printf("\t&c + 1, &d = %p, %p\n", &c + 1, &d);
  printf("\t&e + 1, &f = %p, %p\n", &e + 1, &f);

  // Podemos ver que se cumple lo que dijimos, al sumarle 1 a a, b y c,
  // caemos correctamente en la siguiente direccion.


  // Ahora podemos hacer lo mismo, pero extrayendo los valores:
  printf("\t*(&a + 1), b = %c, %c\n", *(&a + 1), b);
  printf("\t*(&c + 1), d = %d, %d\n", *(&c + 1), d);
  printf("\t*(&e + 1), f = %lf, %lf\n", *(&e + 1), f);


  // ¿Que pasaría si intentaramos lo mismo entre b y c, y d y e?
  printf("\nAritmética, sumar 1 entre tipos distntos:\n");
  printf("\t&b + 1, &c = %p, %p\n", &b + 1, &c);
  printf("\t&d + 1, &e = %p, %p\n", &d + 1, &e);

  // Podemos ver que tambien calzan.
  // Esto hace sentido, porque como b es char y c es int, b esta a sizeof(char)
  // bytes de c. Luego, cuando hacemos &b + 1, la aritmética de punteros traduce
  // el 1 a sizeof(char).


  // Es claro que los valores también funcionaran:
  printf("\t*(&b + 1), c = %d, %d\n", *(&b  + 1), c);
  printf("\t*(&d + 1), e = %lf, %lf\n", *(&d + 1), e);

  // ¿Que pasó?, Si bien &d + 1 efectivamente llega a &e, los printf estan
  // erroneos. Sucede que &d es un int*, mientras que en la direccion &d + 1
  // hay un float, pero C va a intentar interpretarlo como int debido al tipo de 
  // d. Para solucionar esto debemos castear d desde un int* a un double*.
  printf("\t*(&d + 1), e = %lf, %lf\n", *(double *)(&d + 1), e);

  // Esto no pasó para &b + 1 porque resulta ser que un char, en términos 
  // prácticos es manejado como un int por detrás.


  // Finalmente, ¿Que pasaría si sumaramos dos en vez de 1?
  printf("\nAritmética y direcciones erroneas:\n");
  printf("\t&a + 2, &b = %p, %p\n", &a + 2, &b);
  printf("\t&c + 2, &d = %p, %p\n", &c + 2, &d);
  printf("\t&e + 2, &f = %p, %p\n", &e + 2, &f);

  // Si se dan cuenta, caemos solo en direcciones erroneas!!!!
  // Esto se debe a que como entre b y c el tipo cambia, &a + 2 no lo considera.
  // Debido a esto caemmos en direcciones que estan entre los valores, o en el 
  // caso de e de lleno nos salimos del sector inicializado del stack.

  // Es por esto que en la mayoría de los casos es mejor dejar la aritmética 
  // de punteros a C.
  
  return 0;
}
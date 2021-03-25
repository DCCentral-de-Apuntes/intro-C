// Instrucciones de uso:
//
// gcc flujo.c -o flujo
// ./flujo

// Incluimos standard bool y standard I/O
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv)
{
  // Ejemplos de bool
  bool a = true;
  bool b = false;
  bool c = a && b;
  bool d = c || !b;
  printf("El resultado es %d\n\n", d); // Recordar que los booleanos son 0 o 1.


  // Ejemplos de if/else if/else
  if (true)
  {
    printf("Este es un bloque de código, ya que está entre llaves.\n\n");
  }
  
  if (true)
    printf("Podemos omitir los corchetes si solo utilizaremos una linea.\n\n");

  if (!a) 
  {
    printf("Bloque 1.\n\n");
  } 
  else if (b)
  {
    printf("Bloque 2.\n\n");
  }
  else 
  {
    printf("Bloque 3.\n\n");
  }


  // Ejemplo de while, imprimir números pares
  int i = 0;
  while (i < 10)
  {
    printf("%d ", i);
    i += 2;
  }
  printf("\n\n");


  // Ejemplo de for, imprimir números pares
  for (int i = 0; i < 10; i+=2)
  {
    printf("%d ", i);
  }
  printf("\n\n");


  // Ejemplo continue, imprimir todos los pares distintos (a, b)
  for (int i = 0; i < 10; i+=1)  // Iteramos de 0 a 9
  {
    for (int j = 0; j < 10; j+=1)  // Iteramos de 0 a 9
    {
      if (i == j) continue;   // Omitimos el caso a == b
      printf("(%d, %d) ", i, j);
    }
  }
  printf("\n\n"); 

  // Ejemplo sin continue
  for (int i = 0; i < 10; i+=1)  // Iteramos de 0 a 9
  {
    for (int j = 0; j < 10; j+=1)  // Iteramos de 0 a 9
    {
      if (i != j)
      {
        // Agregamos un nivel de indentación más de forma innecesaria.
        printf("(%d, %d) ", i, j);
      } 
    }
  }
  printf("\n\n"); 


  // Ejemplo break, while hasta que el número sea divisible por 4 y 6
  int n = 0;
  while (true)
  {
    n += 1;
    if (n % 4 == 0 && n % 6 == 0) break;  // Salimos del ciclo si se cumple
  }
  printf("%d\n\n", n);


  // Ejemplo de switch, catalogar un char
  // switch solo funciona con tipos basicos (char, int, float, double)
  char boton = 'x';
  switch (boton)  // Aqui debe ir la variable a evaluar, no una expresion logica.
  {
    case 'a':  // En cada case puede ir una expresion constante.
      printf("Aceptar!\n");
      break;
    case 'b':
      printf("Cancelar!\n");
      break;
    default:
      printf("Boton desconocido\n");
      break;
  }

  return 0;
}

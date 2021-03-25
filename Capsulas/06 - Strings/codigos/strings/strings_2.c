// Instrucciones de uso:
//
// gcc strings_2.c -o strings_2
// ./strings_2

// Incluimos standard I/O
#include <stdio.h>

// Funcion que recibe dos strings de largo arbitrario y nos dice en cuantos
// caracteres se diferencian, indice por indice
int string_compare(char* A, int n, char* B, int m)
{
  // Nos quedamos con el largo menor y guardamos la diferencia en largo para
  // contabilizarla al final
  int k;
  int diff;
  if (n < m) 
  {
    k = n;
    diff = m - n;
  }
  else 
  {
    k = m;
    diff = n - m;
  }

  // Iteramos los arrays usando k y contamos
  int count = 0;
  for (int i = 0; i < k; i+=1)
  {
    // Si los caracteres son distindos sumamos
    if (A[i] != B[i]) 
    {
      count += 1;
    }
  }
  
  // Retornamos la diferencia
  return count + diff;
}

// Funcion que recibe tres strings y se guarda en el tercero la concatenacion
// de los primeros. El largo del tercer string debe ser igual o mayor a la suma
// del largo de los dos primeros
void string_concat(char* A, int n, char* B, int m, char *C)
{
  // Guardamos A en C
  for (int i = 0; i < n; i+=1)
  {
    C[i] = A[i];
  }

  // Guardamos B en C a partir del indice n
  for (int i = 0; i < m; i+=1)
  {
    C[n + i] = B[i];
  }
}

int main(int argc, char** argv)
{
  // Como los strings no son nada más que arrays de char, podemos aplicar
  // funciones para organizar nuestro codigo y sacarle el mayor provecho
  // posible al lenguaje

  // Comparemos strings
  int diff_1 = string_compare("Hola", 5, "Hola", 5);
  int diff_2 = string_compare("Alas", 5, "Adios", 6);
  int diff_3 = string_compare("Dos Strings", 12, "Muy Diferentes", 15);
  printf("Differences: %i, %i, %i\n", diff_1, diff_2, diff_3);
  
  // Cabe recalcar que estamos considerando el null terminator para calcular
  // la diferencia. Como estamos iterando en funcion del largo, podemos
  // omitirlo sin correr ningún peligro
  int diff_4 = string_compare("Hola", 4, "Hola", 4);
  int diff_5 = string_compare("Alas", 4, "Adios", 5);
  int diff_6 = string_compare("Dos Strings", 11, "Muy Diferentes", 14);
  printf("Differences: %i, %i, %i\n", diff_4, diff_5, diff_6);
  printf("\n");

  // Ahora concatenemos dos strings
  // Primero definimos los strings a concatenar y el string objetivo
  char A[7] = "Hello ";
  char B[7] = "World!";
  char C[14]; // Debe tener tantos char como a y b combinados

  // Ahora hagamos la concatenacion
  string_concat(A, 7, B, 7, C);

  // Imprimamos C
  printf("A concat B = %s\n", C);

  //¿¿¿¿QUE PERO QUE????, C nos imprime "Hello"!!!!
  //
  // Sin embargo, esto esta bien. Si observamos detenidamente, estamos agregando
  // A con null terminator y todo, por lo cual el array C se ve asi:
  //
  // char C[14] = {'H', 'e', 'l', 'l', 'o' , ' ', '\0', 'W', 'o', 'r', 'l', 'd', '!', '\0'}
  //
  // Es decir, C termina en "Hello ", ya que despues de este hay un null
  // terminator, no importa si hay más cosas despues de este 
  //
  // Como string_concat no le importa los null terminator, podemos omitirlo
  // para A, pasandole 6, en vez de 7, veamos si sirve

  char D[13]; // Ojo que que ahora necesitamos un char menos
  string_concat(A, 6, B, 7, D);

  // Aqui acabamos de omitir el null terminator de A, pero no el de B, asi que
  // D debiese seguir siendo un string valido. Probemos!
  printf("A concat B = %s\n", D);

  // Y voilá!
  
  // Al fin y al cabo tenemos tanta flexibilidad con strings como tenemos con
  // arreglos, solo que tenemos que ser conscientes del null terminator

  return 0;
}

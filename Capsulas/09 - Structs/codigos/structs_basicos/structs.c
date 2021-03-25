// Instrucciones de uso:
//
// gcc structs.c -o structs
// ./structs

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Definamos un struct normalmente
struct house
{
  char *street;
  double price;
  int number;
};

// Podemos acortarlo con typedef
typedef struct house House;

int main(int argc, char** argv)
{
  // Formas de inicializar un struct en el stack

  // Hay multiples formas de crear un struct en el stack, quedese con la que le
  // parezca más legible y explicita en el contexto

  // Directamente sin nombre de variables
  House a = {"Nueva Providencia", 250, 12};

  // Directamente con nombre de variables
  House b = {
    .street = "Nueva Providencia",
    .number = 12,
    .price = 250,
  };

  // Directamente mediante casting con o sin nombre de variables
  House c;
  c = (House){"Nueva Providencia", 250, 12};
  c = (House){
    .street = "Nueva Providencia",
    .number = 12,
    .price = 250,
  };

  // Punto por punto
  House d;
  d.street = "Nueva Providencia";
  d.price = 250;
  d.number = 12;


  // Acceder a un struct en el stack

  // Bastante simple, se hace con . al igual que las clases en Python
  printf("Casa Original (STACK):\n");
  printf("\tcalle  = %s\n", d.street);
  printf("\tnumber = %d\n", d.number);
  printf("\tprice  = %lf\n", d.price);
  printf("\n");

  // Tambien acepta modificacion
  d.street = "Pedro de Valdivia";
  d.number = 18;
  d.price *= 1.12406;

  printf("Casa Modificada (STACK):\n");
  printf("\tcalle  = %s\n", d.street);
  printf("\tnumber = %d\n", d.number);
  printf("\tprice  = %lf\n", d.price);
  printf("\n");

  // Formas de inicializar un struct en el heap

  // Primero debemos pedir memoria para las casas
  House *e = malloc(sizeof(House));
  House *f = malloc(sizeof(House));

  // Directamente mediante casting con o sin variables
  *e = (House) {
    "Pedro de Valdivia",
    12,
    250.1245,
  };
  *e = (House) {
    .price = 250.1245,
    .street = "Pedro de Valdivia",
    .number = 12,
  };

  // Flecha por flecha
  f->street = "Vicuña Mackenna";
  f->number = 2005;
  f->price = 500.1244235;

  
  // Acceder a un struct en el heap

  // Bastante simple, se hace con ->.
  printf("Casa Original (HEAP):\n");
  printf("\tcalle  = %s\n", e->street);
  printf("\tnumber = %d\n", e->number);
  printf("\tprice  = %lf\n", e->price);
  printf("\n");

  // Tambien acepta modificacion
  e->street = "Greacia";
  e->number = 18;
  e->price *= 0.2406;

  printf("Casa Modificada (HEAP):\n");
  printf("\tcalle  = %s\n",e->street);
  printf("\tnumber = %d\n",e->number);
  printf("\tprice  = %lf\n",e->price);

  // Debemos recordar liberar la memoria
  free(e);
  free(f);

  return 0;
}

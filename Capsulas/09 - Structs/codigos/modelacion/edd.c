// Instrucciones de uso:
//
// gcc edd.c -o edd
// ./edd

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// En este archivo veremos un ejemplo de uso de structs para definir estructuras
// de datos, en especifico, una lista ligada

// Primero debemos definir el struct
typedef struct list {
  int value;
  struct list* next;
} List;
// El nombre final es List

// Definimos el inicializador de la lista, recibe el valor a guardar
List* list_init(int value)
{
  // Pedimos memoria para la lista
  List* list = malloc(sizeof(List));

  // Inicializamos la lista directamente
  *list = (List) {
    .value = value,
    .next = NULL, // como no tiene siguiente lista y es un puntero, debe partir en NULL
  };

  // Tambien podemos inicializar flecha por flecha, de la sig forma
  // list->value = value;
  // list->next = NULL;

  // Retornamos la lista
  return list;
}

// Definimos una función para imprimir los datos de la lista
void list_print(List* list)
{
  printf("%i -> ", list->value);

  // Revisamos si sigue
  if (!list->next)
  {
    printf("NULL\n");
  }
  else
  {
    // Hacemos llamado recursivo
    list_print(list->next);
  }
}

// Definimos una funcion para agregar un valor a la lista
void list_append(List* list, int value)
{
  // Aqui podemos apreciar la utilidad de esta modelacion, el código queda
  // super ordenado y legible

  // Debemos ir al final de la lista, para esto podemos utilizar un while
  List *last = list;
  while (last->next) {
    last = last->next;
  }

  // Creamos el nuevo nodo
  List *new_list = list_init(value);

  // Lo agregamos como el nodo siguiente al ultimo nodo de la lista
  last->next = new_list;
}

// Definimos una funcion que nos retorne el valor en un indice de la lista
int list_at_index(List* list, int index)
{
  // Nos ubicamos en el indice correspondiente
  List* node = list;
  for (size_t i = 0; i < index; i++)
  {
    node = node->next;
  }

  // Retornamos el valor
  return node->value;
}

// Definimos el destructor de la lista
int list_destroy(List *list)
{
  // Si hay un nodo en la sig posicion, llamamos recursivamente a la funcion
  if (list->next)
  {
    list_destroy(list->next);
  }
  
  // Luego, liberamos la lista
  free(list);
}

int main(int argc, char** argv)
{
  // Creamos una lista
  List* list = list_init(5);

  // Agregamos algunos valores
  list_append(list, 2);
  list_append(list, 4);
  list_append(list, -2);
  list_append(list, -5);
  list_append(list, 3);
  list_append(list, 12);

  // Imprimos la lista
  list_print(list);

  // Indexamos la lista
  int result = list_at_index(list, 4);
  printf("list[4] = %i\n", result);

  // Liberamos memoria
  list_destroy(list);

  // Como podemos ver esta modelacion para realizar estructuras de datos nos 
  // permite diseñar una interfaz clara y simple de utilizar que ademas se
  // asegura de que no ocurran leaks

  return 0;
}

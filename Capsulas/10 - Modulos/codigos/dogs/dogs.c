// Este es el archivo .c del struct dog por lo cual tiene la definicion de
// todas las funciones relacionadas a este, tanto la sde uso interno como las
// de uso externo

// Incluimos dogs.h, sumamente importante
#include "dogs.h"

// Definimos el inicializador del perro, recibe su nombre y la edad y el resto 
// se inicia con valores por defecto
Dog* dog_init(char* name, int age)
{
  // Pedimos memoria para el perro
  Dog* dog = malloc(sizeof(Dog));

  // Inicializamos el perro directamente
  *dog = (Dog) {
    .name = name,
    .age = age,
    .good_boy = true, // of course
    .friend = NULL, // como no tiene amigo al inicio, y es un puntero, debe partir en NULL
  };

  // Tambien podemos inicializar flecha por flecha, de la sig forma
  // dog->name = name;
  // dog->age = 0;
  // dog->good_boy = true;
  // dog->frined = NULL;

  // Retornamos el perro
  return dog;
}

// Definimos una funcion para imprimir los datos del perro
void dog_print(Dog* dog)
{
  printf("Dog %s:\n", dog->name);
  printf("\tgood_boy -> %i\n", dog->good_boy);

  // Corroboramos que tenga amigo
  if (dog->friend)
  {
    printf("\tfriend   -> %s\n", dog->friend->name);
  }
  else
  {
    printf("\tfriend   -> :(\n");
  }

  printf("\tage      -> %i\n", dog->age);  
}

// Definimos una funcion para que el perro ladre
void dog_bark(Dog* dog)
{
  printf("Dog %s:\n", dog->name);
  if (dog->friend)
  {
    printf("\tWOOF WOOF!!!\n");
  }
  else
  {
    printf("\twoof...\n");
  }
}

// Definimos una funcion para que el perro haga un amigo
void dog_meet(Dog* dog, Dog* friend)
{
  printf("%s and %s are now friends!\n", dog->name, friend->name);
  dog->friend = friend;
  friend->friend = dog;
}

// Definimos el destructor del perro
void dog_destroy(Dog* dog)
{
  // Liberamos el perro
  free(dog);

  // Puede parecer exagerado tener una funcion solo para el free, pero la gracia
  // de esta modelacion es que en caso de que nuestro struct se vuelva mas 
  // complejo podemos tirar toda la lógica de liberación aquí
}
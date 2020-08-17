// Instrucciones de uso:
//
// gcc oom.c -o oom
// ./oom

// Incluimos standard I/O, standard library y standard bool
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// En este archivo veremos un ejemplo de uso de structs con modelacion orientada
// a objetos (OOM)

// Primero debemos definir el struct
typedef struct dog {
  char* name;
  int age;
  bool good_boy;
  struct dog* friend;
} Dog;
// El nombre final es Dog

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


int main(int argc, char** argv)
{
  // Creamos perros
  Dog* chola = dog_init("chola", 7);
  Dog* beto = dog_init("beto", 12);

  // Imprimos un perro
  dog_print(chola);
  printf("\n");

  // El perro ladra
  dog_bark(chola);
  printf("\n");

  // El perro hace un amigo
  dog_meet(chola, beto);
  printf("\n");

  // El perro ladra de nuevo
  dog_bark(chola);
  printf("\n");

  // Imprimimos a los perros
  dog_print(chola);
  dog_print(beto);

  // Liberamos memoria
  dog_destroy(chola);
  dog_destroy(beto);

  // Como podemos ver, esta modelacion orientada a objetos, si bien un poco 
  // dificil de programar en principio, nos permite un orden increible cuando 
  // queremos modelar entidades

  return 0;
}

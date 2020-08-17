// Instrucciones de uso:
//
// gcc struct_de_structs.c -o struct_de_structs
// ./struct_de_structs

// Incluimos standard I/O y standard library
#include <stdio.h>
#include <stdlib.h>

// Primero definimos los structs
typedef struct dog {
  char* name;
  int age;
} Dog;
// Nombre final es Dog

typedef struct kid {
  char* name;
  Dog dog;  // Solo tiene un perro
} Kid;
// Nombre final es Kid

typedef struct adult {
  char* name;
  Dog* dogs;  // Tiene un array de perros
  int dog_count;  // Hay que tener el largo del array
} Adult;


int main(int argc, char** argv)
{
  // struct con struct

  // Para crear un struct que contiene un struct lo podemos hacer directamente
  // tambien podemos usar puntos
  Kid kid = {
    .name = "Roberto",
    .dog = {  // Dog es un struct, asi que seguimos
      .name = "Spotty",
      .age = 5,
    }
  };

  // Para acceder a la informacion usamos puntos
  printf("Kid:\n");
  printf("\tname = %s\n", kid.name);
  printf("\tdog  =\n");
  printf("\t\tname = %s\n", kid.dog.name);
  printf("\t\tage  = %d\n", kid.dog.age);


  // struct con structs

  // Para crear un struct que contiene muchos structs debemos pedir memoria
  // directamente en la incicializacion. Podría crearse un arreglo de antemano
  // en el STACK, pero no se recomienda
  Adult adult = {
    .name = "Pedro",
    .dog_count = 3,
    .dogs = calloc(3, sizeof(Dog))
  };

  // Ahora debemos inicializar cada uno de los perros. Esto se puede hacer de
  // forma directa
  adult.dogs[0] = (Dog){.name = "Apollo", .age = 2};
  adult.dogs[1] = (Dog){.name = "Baggy", .age = 7};
  adult.dogs[2] = (Dog){.name = "Kiki", .age = 12};

  // Para acceder se hace de igual forma, con puntos para ya que adult esta en
  // el stack. Si estuviera en el heap, deberíamos acceder con flecha para
  // todo

  printf("\nAdult:\n");
  printf("\tname = %s\n", adult.name);
  printf("\tdogs = [\n");
  for (int i = 0; i < adult.dog_count; i+=1)
  {
    printf("\t\tname = %s, ", adult.dogs[i].name);
    printf("age  = %d\n", adult.dogs[i].age);
  }
  printf("\t]\n");
  

  return 0;
}

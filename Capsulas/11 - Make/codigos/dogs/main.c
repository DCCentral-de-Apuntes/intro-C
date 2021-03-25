// Instrucciones de uso:
//
// make
// ./dogs

// Incluimos 11_dogs.h
#include "dogs.h"


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
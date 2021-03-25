// Instrucciones de uso:
//
// gcc structs_y_arrays.c -o struct_y_arrays
// ./struct_y_arrays

// Incluimos standard I/O y standard library 
#include <stdio.h>
#include <stdlib.h>

// Declaramos structs
struct hero;
struct cell;

// Definimos alias
typedef struct hero Hero;
typedef struct cell Cell;

// Definimos structs
struct hero {
  int hp;
  int mp;
};

struct cell {
  int difficulty;
  int gold;
};

int main(int argc, char** argv)
{
  // Es posible tener arrays de structs en el stack, pero usualmente no se
  // recomienda, porque podría tomarse demasiado espacio y arriesgar un
  // StackOverflow™ 

  // Array de structs

  // Caso de uso extremadamente comun, todo esta en el heap a excepción de la
  // referencia al arreglo, que esta en el stack

  // Primero debemos pedir memoria para el array
  Hero** heroes = calloc(3, sizeof(Hero*));

  // Luego, por cada indice pedimos memoria para el struct
  heroes[0] = malloc(sizeof(Hero));
  heroes[1] = malloc(sizeof(Hero));
  heroes[2] = malloc(sizeof(Hero));

  // Finalmente definimos cada struct
  *heroes[0] = (Hero){.hp=150, .mp=200};
  *heroes[1] = (Hero){.hp=200, .mp=100};
  *heroes[2] = (Hero){.hp=500, .mp=25};
  
  // Para acceder, es indexacion y flechas.
  printf("Heroes:\n");
  for (int i = 0; i < 3; i+=1)
  {
    printf("\tHero %i: %i HP, %i MP\n", i, heroes[i]->hp, heroes[i]->mp);
  }

  // Debemos recordar liberar la memoria
  // Primero los structs
  free(heroes[0]);
  free(heroes[1]);
  free(heroes[2]);

  // Luego el array
  free(heroes);


  // Matriz de structs

  // Este caso tambien es comun, es muy similar a arrays normal, solo que esta
  // vez es un triple puntero, un arreglo de arreglos de structs, nuevamente,
  // todo en el heap a excepcion de la referencia a la matriz

  // Primero pedimos memoria para la matriz
  Cell ***dungeon = calloc(2, sizeof(Cell**));

  // Luego pedimos memoria para cada fila de la matriz
  dungeon[0] = calloc(3, sizeof(Cell*));
  dungeon[1] = calloc(3, sizeof(Cell*));

  // Después pedimos memoria para cada celda de la matriz
  dungeon[0][0] = malloc(sizeof(Cell));
  dungeon[0][1] = malloc(sizeof(Cell));
  dungeon[0][2] = malloc(sizeof(Cell));

  dungeon[1][0] = malloc(sizeof(Cell));
  dungeon[1][1] = malloc(sizeof(Cell));
  dungeon[1][2] = malloc(sizeof(Cell));

  // Finalmente, inicializamos todas las celdas
  *dungeon[0][0] = (Cell){.difficulty = 0, .gold = 25};
  *dungeon[0][1] = (Cell){.difficulty = 2, .gold = 200};
  *dungeon[0][2] = (Cell){.difficulty = 1, .gold = 120};

  *dungeon[1][0] = (Cell){.difficulty = 2, .gold = 235};
  *dungeon[1][1] = (Cell){.difficulty = 2, .gold = 192};
  *dungeon[1][2] = (Cell){.difficulty = 1, .gold = 93};

  // El acceso es lo mismo, dos indices seguidos por una flecha:
  printf("Map:\n");
  printf("\t╔═══╦═══╦═══╗\n");
  for (int i = 0; i < 2; i+=1)
  {
    printf("\t");
    for (int j = 0; j < 2; j+=1)
    {
      printf("║ %i ", dungeon[i][j]->difficulty);
    }
    printf("║ %i ║", dungeon[i][2]->difficulty);
    if (i < 1)
    {
      printf("\n\t╠═══╬═══╬═══╣\n");
    }  
  }
  printf("\n\t╚═══╩═══╩═══╝\n");

  // Debemos recordar liberar la memoria
  // Primero los structs
  free(dungeon[0][0]);
  free(dungeon[0][1]);
  free(dungeon[0][2]);

  free(dungeon[1][0]);
  free(dungeon[1][1]);
  free(dungeon[1][2]);

  // Luego las filas
  free(dungeon[0]);
  free(dungeon[1]);

  // Finalmente la matriz
  free(dungeon);


  return 0;
}

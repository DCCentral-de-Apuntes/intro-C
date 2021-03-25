// Instrucciones de uso:
//
// gcc com.c -o com
// ./com

// Incluimos standard I/O y standard library 
#include <stdio.h>
#include <stdlib.h>

// En este archivo veremos un ejemplo de uso de structs para definir tipos
// compuestos, donde no nos interesa utilizar referencias

// Primero debemos definir el struct
typedef struct vector3d {
  double x;
  double y;
  double z;
} Vec3D;
// El nombre final es Vec3D

// Definimos el create del tipo compuesto
Vec3D vec3d_create(double x, double y, double z)
{
  // Como no nos interesa pedir memoria, podemos retornar el vector directamente
  return (Vec3D){
    .x = x,
    .y = y,
    .z = z
  };
}

// Definimos funcion para imprimir un vector
void vec3d_print(Vec3D v)
{
  printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}

// Definimos el producto punto entre dos vectores
double vec3d_dot_prod(Vec3D v1, Vec3D v2)
{
  // Nuevamente, podemos retornar directamente
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Definimos el producto cruz entre dos vectores
Vec3D vec3d_cross_prod(Vec3D v1, Vec3D v2)
{
  // Calculamos nuevas coordenadas
  double x = v1.y * v2.z - v1.z * v2.y;
  double y = v1.z * v2.x - v1.x * v2.z;
  double z = v1.x * v2.y - v1.y * v2.x;

  // Nuevamente, podemos retornar directamente
  return vec3d_create(x, y, z);
}


int main(int argc, char** argv)
{
  // Creamos dos vectores
  Vec3D v1 = vec3d_create(1.5, 2.5, 0.002);
  Vec3D v2 = vec3d_create(12.2, 0.5, 20);

  // Los imprimimos
  vec3d_print(v1);
  vec3d_print(v2);

  // Calculamos producto punto y lo imprimimos
  double dot = vec3d_dot_prod(v1, v2);
  printf("v1 dot v2 = %lf\n", dot);

  // Calculamos el producto cruz y lo imprimimos
  Vec3D v3 = vec3d_cross_prod(v1, v2);
  vec3d_print(v3);

  // Como en ningún momento hemos utilizado el heap, no es necesario liberar
  // memoria. Nuevamente vemos que el codigo queda ordenado y legible
  
  return 0;
}

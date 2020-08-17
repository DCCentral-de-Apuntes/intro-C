// Instrucciones de uso:
//
// gcc flujo_cursed.c -o flujo_cursed
// ./flujo_cursed

// Solo son necesarios los includes, los ;, las llaves y los espacios 
// despues de los tipos ;)
#include <stdbool.h>
#include <stdio.h>
int main(int argc, char** argv){bool a=true;bool b=false;bool c=a&&b;bool d=c||!b;printf("El resultado es %d\n\n",d);if(true){printf("Este es un bloque de código, ya que está entre llaves.\n\n");}if(true)printf("Podemos omitir los corchetes si solo utilizaremos una linea.\n\n");if(!a){printf("Bloque 1.\n\n");} else if(b){printf("Bloque 2.\n\n");}else{printf("Bloque 3.\n\n");}int i=0;while(i<10){printf("%d ",i);i+=2;}printf("\n\n");for(int i=0;i<10;i+=2){printf("%d ",i);}printf("\n\n");for(int i=0;i<10;i+=1){for(int j=0;j<10;j+=1){if(i==j)continue;printf("(%d, %d) ",i,j);}}printf("\n\n");for(int i=0;i<10;i+=1){for(int j=0;j<10;j+=1){if(i!=j){printf("(%d, %d) ",i,j);}}}printf("\n\n");int n=0;while(true){n+=1;if(n%4==0&&n%6==0)break;}printf("%d\n\n",n);char tipo='x';switch(tipo){case'a':printf("Tipo a!\n");break;case'b':printf("Tipo b!\n");break;default:printf("Tipo desconocido.\n");break;}return 0;}

###############################
#   Makefile reptil ordenado  #
###############################

# El problema con el makefile actual es que nos queda colapsada la carpeta
# donde hacemos make con object files. Por lo tanto, vamos a crear una carpeta
# llamada obj a donde vamos a compilar todos los object files.
#
# Para que esto funcione, el output de todas las reglas .o debe compilar a 
# esta carpeta, y las reglas y dependencias .o debemos agregarles el obj/

# Linkeamos los object files y obtenemos el ejecutable
main: obj/main.o obj/reptil.o obj/frog.o obj/snake.o obj/turtle.o
	gcc obj/main.o obj/reptil.o obj/frog.o obj/snake.o obj/turtle.o -o main

# Compilamos el main y todas sus dependencias (los reptiles)
obj/main.o: main.c frog/frog.h snake/snake.h turtle/turtle.h reptil/reptil.h
	gcc main.c -c -o obj/main.o

# Compilamos reptil y su header file
obj/reptil.o: reptil/reptil.c reptil/reptil.h
	gcc reptil/reptil.c -c -o obj/reptil.o

# Compilamos frog, su header file y su dependencia reptil
obj/frog.o: frog/frog.c frog/frog.h reptil/reptil.h
	gcc frog/frog.c -c -o obj/frog.o

# Compilamos snake, su header file y su dependencia reptil
obj/snake.o: snake/snake.c snake/snake.h reptil/reptil.h
	gcc snake/snake.c -c -o obj/snake.o 

# Compilamos turtle, su header file y su dependencia reptil
obj/turtle.o: turtle/turtle.c turtle/turtle.h reptil/reptil.h
	gcc turtle/turtle.c -c -o obj/turtle.o 
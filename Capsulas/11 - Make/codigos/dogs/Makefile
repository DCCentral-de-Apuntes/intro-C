#####################
#   Makefile dogs   #
#####################

# En este makefile tenemos una única dependencia, main.c <- dogs.h

# Debemos recordar que cuando hay dependencias en nuestro proyecto
# vamos a generar una regla por cada archivo .c para obtener su .o
# luego, tenemos siempre como primera regla la compilacion final

# Linkeamos los object files y obtenemos el ejecutable
main: main.o dogs.o
	gcc main.o dogs.o -o dogs

# Recompilamos main si cambia su código base o su dependencia
main.o: main.c dogs.h
	gcc main.c -c -o main.o

# Recompilamos dogs si cambia su código base o su header file
dogs.o: dogs.c dogs.h
	gcc dogs.c -c -o dogs.o
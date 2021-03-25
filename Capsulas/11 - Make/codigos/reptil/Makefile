#######################
#   Makefile reptil   #
#######################

# Como cada par .c .h esta en su propia carpeta, debemos incluir esta cada vez
# que tengamos como dependencia uno de estos archivos o lo compilemos con gcc
#
# Ademas debemos considerar las dependencias de cada object file

# Linkeamos los object files y obtenemos el ejecutable
main: main.o reptil.o frog.o snake.o turtle.o
	gcc main.o reptil.o frog.o snake.o turtle.o -o main

# Compilamos el main y todas sus dependencias (los reptiles)
main.o: main.c frog/frog.h snake/snake.h turtle/turtle.h reptil/reptil.h
	gcc main.c -c -o main.o

# Compilamos reptil y su header file
reptil.o: reptil/reptil.c reptil/reptil.h
	gcc reptil/reptil.c -c -o reptil.o

# Compilamos frog, su header file y su dependencia reptil
frog.o: frog/frog.c frog/frog.h reptil/reptil.h
	gcc frog/frog.c -c -o frog.o

# Compilamos snake, su header file y su dependencia reptil
snake.o: snake/snake.c snake/snake.h reptil/reptil.h
	gcc snake/snake.c -c -o snake.o 

# Compilamos turtle, su header file y su dependencia reptil
turtle.o: turtle/turtle.c turtle/turtle.h reptil/reptil.h
	gcc turtle/turtle.c -c -o turtle.o 

test: main.c vector.c manifold.c
	gcc main.c vector.c manifold.c -I ./include/ -lm 

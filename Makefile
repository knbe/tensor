simfiles = tensor.c
mgl_libs = -lmgl2-qt5 -lmgl2

main : $(simfiles)
	gcc $(simfiles) -lm 

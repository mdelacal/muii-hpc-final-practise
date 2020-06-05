CC=gcc
CFLAGS=-fopenmp

hpc:
	$(CC) discretizo.c -o discretizo

openmp:
	$(CC) -o discretizo $(CFLAGS) discretizo.c  
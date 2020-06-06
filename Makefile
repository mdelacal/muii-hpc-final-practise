# Makefile para el proyecto final HPC - UCLM
# Desarrollado por: Felix Angel Martinez Muela y Miguel de la Cal Bravo

# Variables de directorios
DIROBJ := obj/
DIREXE := exec/
DIRSRC := src/
# Variables de librerias y compilacion
CFLAGS := -fopenmp -c -Wall -ansi
LDFLAGS := -fopenmp
CC := gcc

all: dirs discretizo

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

discretizo: $(DIROBJ)discretizo.o
	$(CC) -o $(DIREXE)$@ $^ $(LDFLAGS)


$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRSRC)*~

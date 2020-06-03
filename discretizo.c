/********************************************************************************
 * Práctica final: Solución de un problema mediante técnicas de paralelización  *
 * Asignatura: Computación de Altas Prestaciones (High Performance Computing)   *
 * Autores:                                                                     *
 *   - Miguel de la Cal Bravo                                                   *
 *   - Félix Ángel Martínez Muela                                               *
 * Fecha de entrega: 07/06/2020                                                 *
 * Máster Universitario en Ingeniería Informática - UCLM                        *
 *******************************************************************************/

/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    /* VARIABLES */
    int i;
    int N = 100; /* tamaño N del vector de edades */
    int v[N]; /* vector de edades */

    /* Inicializamos el vector de N elementos de forma aleatoria, 
        con edades entre 0 y 95 años */
    for(i=0;i<N;i++){
        v[i]=(rand()%96);
    }

    /* Imprimir valores del vector creado */
    for(i=0;i<N;i++){
        printf("%d\n", v[i]);
    }
}
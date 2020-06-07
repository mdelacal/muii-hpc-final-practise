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
#include <omp.h>

/* CONSTANTES */
#define GRUPO_1 1             /* grupo de edad [0, 14] años */
#define GRUPO_2 2             /* grupo de edad [15, 24] años */
#define GRUPO_3 3             /* grupo de edad [25, 64] años */
#define GRUPO_4 4             /* grupo de edad [65, 95] años */

void checkintegrity(int vector_size ,int * grupo1, int * grupo2, int * grupo3, int * grupo4){
    int suma_elementos_grupos = *grupo1 + *grupo2 + *grupo3 + *grupo4;
    if(suma_elementos_grupos == vector_size){
        printf("Integridad correcta\n");
    }else{
        printf("Integridad INCORRECTA\n");
    }
}

int main()
{
    /* VARIABLES */
    long vector[] = {1000, 10000, 100000, 1000000, 10000000};
    int vector_size = sizeof(vector) / sizeof(vector[0]);
    long n;
    int i, actual_threads, k;
    int total_threads = 4;                  /* número de threads a utilizar */
    int n_per_thread;                       /* número de elementos por cada thread */
    unsigned char *v;                       /* vector de edades */
    unsigned char *solution;                /* vector con la solución, grupo al que pertenece cada edad */
    int group1, group2, group3, group4 = 0; /* elementos por grupo */
    /* Cores */
    omp_set_dynamic(0);     /* Desactivamos el número de hilos dinámicos */
    omp_set_num_threads(4); /* Seleccionamos el número de hilos */

    /* Time */
    double t_ini, t_fin;
    double secs;

    /* Probaremos con un conjunto de hilos */
    for (k = 0; k < vector_size; k++)
    {
        n = vector[k];
        /* Reservar espacio en memoria para los vectores v y solution */
        v = (unsigned char *)malloc(sizeof(unsigned char) * n);

        srand(time(NULL)); /* para generar elementos aleatorios diferentes */

        /* Inicializamos el vector de N elementos de forma aleatoria,
        con edades entre 0 y 95 años */
        #pragma omp parallel for 
            for (i = 0; i < n; i++)
            {                    
                v[i] = rand() % 96;
            }
        for (actual_threads = 1; actual_threads <= total_threads; actual_threads++)
        {   
        group1 = 0, group2 = 0, group3 = 0, group4 = 0; /* Reiniciamos los valores de los grupos*/
      
        solution = (unsigned char *)malloc(sizeof(unsigned char) * n);
        /* Determinar nº de threads y con cuantos elementos trabajará cada proceso */
        omp_set_num_threads(actual_threads);
        n_per_thread = n / actual_threads;
        
        #pragma omp parallel num_threads(actual_threads)
        {
            t_ini = omp_get_wtime(); /* Inicio del contador de tiempo */
        
        #pragma omp barrier
            /* Clasificación discretización por grupos de edades */
            #pragma omp for private(i) schedule(static, n_per_thread) reduction(+: group1, group2, group3, group4) 
            for (i = 0; i < n; i++)
            {
                if (v[i] <= 14)
                {
                    solution[i] = GRUPO_1;
                    group1++;
                }
                else if (v[i] >= 15 && v[i] <= 24)
                {
                    solution[i] = GRUPO_2;
                    group2++;
                }
                else if (v[i] >= 25 && v[i] <= 64)
                {
                    solution[i] = GRUPO_3;
                    group3++;
                }
                else
                {
                    solution[i] = GRUPO_4;
                    group4++;
                }
            }
            t_fin = omp_get_wtime(); /* Fin del contador de tiempo */
        }

        /* COMPROBACIÓN INTEGRIDAD VECTOR RESULTANTE */ 
        checkintegrity(n, &group1, &group2, &group3, &group4);
    
        /* RESULTADOS */
        printf("Iteracción para: %d hilos y un tamaño de vector de: %ld \n", actual_threads, n);

        printf("Grupo 1: %i elementos\n", group1);
        printf("Grupo 2: %i elementos\n", group2);
        printf("Grupo 3: %i elementos\n", group3);
        printf("Grupo 4: %i elementos\n", group4);

        /* Salida tiempo */
        secs = (float)((t_fin - t_ini)* 1000.0); /* CLOCKS_PER_SEC */
        printf("El tiempo estimado en realizar el trabajo es de: %.16g ms\n\n", secs);

        /* Para finalizar, liberamos la memoria del vector v y solution */ 
        free(solution);
        }
        free(v);
        printf("------------------------\n");
    }
    return 0;
}
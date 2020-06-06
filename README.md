# Práctica Final
Repositorio para el ejercicio final de la asignatura de "Computación de Altas Prestaciones" (High Performance Computing) del Máster Universitario en Ingeniería Informática en la UCLM.

Autores:
Miguel de la Cal Bravo
Félix Ángel Martínez Muela

## Memoria
Consultar la memoria incluida dentro de la carpeta doc/, la cual contiene un documento en formato .pdf con toda la información de dicho trabajo y conclusiones de éste.

## Compilación y ejecución
Para la compilación del programa, lo que debemos hacer es dirigirnos a la carpeta raiz del proyecto, donde nos encontraremos un archivo llamado "Makefile". En dicha carpeta deberemos de abrir un terminal y ejecutar:

Para compilar el programa discretizo.c, hemos creado un Makefile que podemos ejecutar con el siguiente comando:
```
$ make all
```
Al ejecutar dicho comando, en el directorio obj/ se nos habrá creado el código objeto y en el directorio exec/ el ejecutable.

Esto nos generará el programa compilado llamado discretizo, el cual ejecutaremos con el comando:
```
$ ./exec/discretizo
```

Si deseamos eliminar todo aquello que se ha generado en la compilación del proyecto, simplemente deberemos ejecutar:
```
$ make clean
```

## Licencia:
Proyecto bajo licencia [LICENSE](LICENSE)
---
_Proyecto realizado por:_
* **Miguel de la Cal Bravo** - [Miguel de la Cal Bravo](https://github.com/miguelcal97)
* **Félix Ángel Martínez Muela** - [Félix Ángel Martínez](https://github.com/FelixAngelMartinez)


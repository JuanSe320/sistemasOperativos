#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc , char* argv[]) {
    //variables
    pid_t pid;
    int status;

    //generar un numero aleatorio
    srand(time(NULL)) ;
    int num_random = rand();

    //crear un hijo
    pid = fork();

    //verficar si el hijo es el padre o el hijo
    if (pid == -1) {
    printf("hubo un error al crear el proceso hijo\n");
    }
    else if (pid == 0) {
    printf("[%d] proceso hijo\n", getpid());
    return num_random;
    }
    else {

    printf("[%d] es el padre\n", getpid());

    //esperar a que el hijo termine
    wait(&status);

    //validar si el hijo termino bien y mostras su id
    if (WIFEXITED(status)) {
    printf("[%d] el hijo termino bien\n", getpid());
    }
    else {
    printf("[%d] el hijo termino mal\n",  getpid());
    }
    
    //mostrar el numero aleatorio generado por el hijo
    printf("[%d] el hijo termino con el codigo %d\n", getpid() , WEXITSTATUS(status));
    }
    

    return 0;
}
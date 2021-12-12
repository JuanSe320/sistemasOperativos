#include <stdio.h>
#include <unistd.h>

int main(int argc , char* argv[]) {
    //variables
    int contador = 1;
    pid_t pid;

    //crear proceso hijo
    pid = fork();

    //verficar si es el proceso padre o el hijo
    if (pid == -1) {
    printf("hubo un error al crear el proceso hijo\n");
    }
    else if (pid == 0) {
     contador += 5;
    }
    else {
     contador += 2;
    }

    //imprimir resultado
    printf("El valor de contador es de:%d \n",contador);
    return 0;
}
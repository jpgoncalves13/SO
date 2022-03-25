#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

pid_t pid = fork();

if (pid==0){
    //Código do filho
    printf("O meu pid é %d\n", getpid());
    printf("O pid do meu pai é %d\n", getppid());
    printf("O pid é %d\n",pid);
}
else{
    //Código do pai
    printf("O meu pid é %d\n", getpid());
    printf("O pid do meu pai é %d\n", getppid());
    printf("O pid do meu filho é %d\n",pid);
}

//sleep(10);

}

#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>

int main(){

pid_t pid = fork();

if (pid==0){
    //Código do filho
    printf("O meu pid é %d\n", getpid());
    printf("O pid do meu pai é %d\n", getppid());
}
else{
    //Código do pai
    printf("O meu pid é %d\n", getpid());
    printf("O pid do meu pai é %d\n", getppid());
    printf("O pid do meu filho é %d\n",pid);
}

sleep(10);

}

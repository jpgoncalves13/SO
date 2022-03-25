#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>

int main(){
    int i,a;
    int status;
    for(i=0; i<10; i++){
        int pid = fork();
        if (pid==0){
            printf("Proc %d - O meu pid é %d\n", i, getpid());
            printf("Proc %d - O pid do meu pai é %d\n", i, getppid());
            sleep(10-i);
            _exit(i);
        }
    }

    for(a=0;a<10;a++){
        wait(&status);
        printf("%d\n",WEXITSTATUS(status));
    
    }
}
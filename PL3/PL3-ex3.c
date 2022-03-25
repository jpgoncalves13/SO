#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>

int main(){
    int i;
    int status;
    for(i=0;i<10;i++){
        pid_t pid = fork();
        if (pid==0){
            printf("O meu pid é %d\n", getpid());
            printf("O pid do meu pai é %d\n", getppid());
            if (i==1) sleep(10);
            _exit(i+1);
        }
        else {
            wait(&status);
            printf("%d\n",WEXITSTATUS(status));
        }
        
    }
}
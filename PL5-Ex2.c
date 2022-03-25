#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    int status,exec_ret;
    pid_t pid = fork();
    if (pid==0){
        exec_ret = execlp("ls","ls","-l",NULL);
        printf("Correu mal\n");
        _exit(exec_ret);
    }
    else {
        wait(&status);
        if (WIFEXITED(status)){
            printf("O filho retornou %d\n",WEXITSTATUS(status));
        }
        else {
            printf("O filho não terminou\n");
        }
    }
}
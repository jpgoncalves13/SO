#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mysystem(char* comando){
    int status,i=0,exit_rec;
    char* aux;
    char* cons = strtok(comando," ");
    char* guarda[50];
    guarda[i] = strdup(cons); 
    for(i=1; (aux = strtok(NULL," ")); i++){
        guarda[i] = strdup(aux);
    }
    pid_t pid;
        pid = fork();
        if (pid==0){
            exit_rec = execvp(guarda[0],guarda);
            exit(exit_rec);
        }
        waitpid(pid,&status,0);
        return exit_rec;
}

int main(int argc, char** argv){
    char comando1[] = "ls -l -a -h";
    char comando2[] = "sleep 10";
    int ret = mysystem(comando2);
    printf("ret: %d\n",ret);
}
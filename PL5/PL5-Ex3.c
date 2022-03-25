#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    int status,i,exit_rec;
    pid_t pid;
    for(i = 0; i<argc-1; i++){
        pid = fork();
        if (pid==0){
        exit_rec = execlp(argv[i+1],argv[i+1],NULL);
        _exit(exit_rec);
    }
    }
    for(i=0;i<argc-1;i++){
        wait(&status);
    }
}
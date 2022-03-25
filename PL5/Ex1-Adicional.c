#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*ssize_t readln1(int fd, char *line, size_t size){
    int bytes_read = 0;
    int i = 0;
    while(bytes_read<size && (bytes_read += read(fd,&line[i],1)) > 0){
        if (line[i] == '\n') break;
        i++;
    }
    return bytes_read;
}*/

int mysystem(char* comando){
    int status,i=0,exit_rec=0;
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

int main(int argc, char **argv){
    char * buffer = malloc(sizeof(char)*100);
    char *aux;
   // pid_t pid = 0;
    /*if (strcmp(argv[argc-1],"&") == 0){
        for(i=1; i<argc; i++){
        pid = fork();
        if (pid < 0) printf("Falha ao criar o processo filho");
        if (pid > 0){
            return 0;
        }
        if (pid == 0) {
            if (strcmp(argv[i],"exit")==0) exit(0);
            mysystem(argv[i]);
        }
        }
    }
    else {
    for(i=1; i<argc; i++){
        if (strcmp(argv[i],"exit")==0) exit(0);
        mysystem(argv[i]);
    }
    }*/
    
    free(buffer);
    buffer = malloc(sizeof(char) * 100);

    while(read(0,buffer,100) > 1){
        aux = strtok(buffer,"\n");

        if (strcmp(aux,"exit")==0) exit(0);
        mysystem(aux);

        free(buffer);
        buffer = malloc(sizeof(char) * 100);
    }                    
    return 0;
}


#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100000

int main(int argc, char* argv[]){
    int r;
    srand(time(NULL));
    int mat[10][MAX], status, i, j;
    for (i = 0; i < 10 ; i++){
        for(j = 0; j < MAX; j++){
            mat[i][j] = rand()%10000;
        }
    }
    pid_t pid;
    if (argc == 2){
    for(i = 0; i < 10; i++){
        pid = fork();
        //É o filho
        if (pid==0){
            r=0;
            for(j=0; j<MAX; j++){
                if (mat[i][j] == atoi(argv[1])) {
                    printf("Está presente\n");
                    _exit(1);
            }
        }
        _exit(0);
    }
    }

    for(i=0; i<10; i++){
        wait(&status);
    }
    
}
}
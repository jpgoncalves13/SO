#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */

#define MAX 100000

int main(int argc, char* argv[]){
    int fd;
    char buf[MAX];
    srand(time(NULL));
    int mat[10][MAX], status, i, j;
    for (i = 0; i < 10 ; i++){
        for(j = 0; j < MAX; j++){
            mat[i][j] = rand()%10000;
        }
    }
    if ((fd = open("matriz.bin", O_APPEND | O_CREAT | O_RDWR, 0700)) == -1) perror("erro no open origem");
    
    if (write(fd,mat,sizeof(mat)) == -1) perror("Erro no write");

    pid_t pid;

    for(i=0;i<10;i++){
        pid = fork();
        //É o filho
        if (pid==0){
            for(j=0; j<MAX; j++){
                if(read(fd,&buf[j],1) == -1) perror("Erro");
                if ((int) buf[j] == atoi(argv[1])) {
                    printf("Está presente\n");
            }
        }
        _exit(0);
    }
        waitpid(pid,&status,0);
    }
}

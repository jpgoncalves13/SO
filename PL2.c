#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_BUF 1000

typedef struct pessoa{
    char nome[200];
    int idade;
}PESSOA;

PESSOA acrescentaPessoa(char* nome, int idade, PESSOA p){
    p.idade = idade;
    strcpy(p.nome,nome);
    return p;
}

ssize_t readEnd(int fd, char *file,int size){
    int bytes_read = 0;
    int i = 0;
    while((bytes_read += read(fd,&file[i],1)) >= 0 && bytes_read < size){
        i++;
    }
    return bytes_read;
}

/*int person_change_age_v2(long pos, int age){
    PESSOA p;
    int fd = open(FILENAME,O_RDWR,)
}*/

int main(int argc, char* argv[]){
    int fd,i;
    PESSOA p;
    char buffer[MAX_BUF];
    int bytes_read;
    if (argc == 4){
    if ((fd = open("pessoas.bin",O_APPEND | O_CREAT | O_WRONLY,0600)) == -1){
        perror("erro no open origem");
    }
    }
    else exit(1);

    if (strcmp(argv[1],"-i") == 0){
        p = acrescentaPessoa(argv[2],atoi(argv[3]),p);
        if (write(fd,&p,sizeof(PESSOA)) == -1) perror("Erro no write");
    }
    else if (strcmp(argv[1],"-u") == 0){        
        while((bytes_read += read(fd,&p,sizeof(PESSOA))) > 0){
            if (strcmp(argv[2],p.nome) == 0) {
                i=1;
                p.idade = atoi(argv[3]);
                lseek(fd,bytes_read-sizeof(p),SEEK_CUR);
                if (write(fd,&p,sizeof(PESSOA)) == -1) perror("Erro no write");
                break;
            }
        }
        if(i!=1) {
            p = acrescentaPessoa(argv[2],atoi(argv[3]),p);
            if (write(fd,&p,sizeof(PESSOA)) == -1) perror("Erro no write");
        }
    }
    close(fd);
}

//Ex7


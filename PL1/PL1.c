#include <sys/types.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <fcntl.h> /* O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF 1000

ssize_t readln1(int fd, char *line, size_t size){
    int bytes_read = 0;
    int i = 0,count = 0;
    while(bytes_read<size && (bytes_read += read(fd,&line[i],1)) > 0){
        if (line[i] == '\n') break;
        i++;
    }
    return bytes_read;
}

/*ssize_t readln(int fd, char *line, size_t size){
    
}*/

int main(int argc, char* argv[]){

    int fd_origem, fd_destino;
    int bytes_read;
    char buffer[MAX_BUF];
    char line[1024];


    if (argc == 3){

    if ((fd_origem = open(argv[1],O_RDONLY)) == -1){
        perror("erro no open origem");
    }
    if ((fd_destino = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0640)) == -1){
        perror("erro no open destino");
        return 1;
    }

    //mycp

  /*while((bytes_read = read(fd_origem,buffer,MAX_BUF)) > 0){
        if (write(fd_destino,buffer,bytes_read) == -1) perror("Erro na função write");
    }*/

    int num_line = 0;
    int i = 1,bw;
    char *buf;

    //mynl

    while ((bytes_read = readln(fd_origem,buffer,MAX_BUF)) > 0 && i<MAX_BUF){
        if (bytes_read != 1){ 
        bw = snprintf(line,1024,"   %d  ",i);
        i++;
        if (write(1,line,bw) == -1) perror("Erro na função write");
        if (write(fd_destino,line,bw) == -1) perror("Erro na função write");
        }
        if (write(1,buffer,bytes_read) == -1) perror("Erro na função write");
        if (write(fd_destino,buffer,bytes_read) == -1) perror("Erro na função write");

    }
    }

    else if (argc == 1){

    int num_line = 0;
    int i = 1,bw;
    char *buf;

    //mycat

    while((bytes_read = read(0,buffer,MAX_BUF)) > 0){
        if (write(1,buffer,bytes_read) == -1) perror("Erro na função write");
    }

    while ((bytes_read = readln1(0,buffer,MAX_BUF)) > 0 && i<MAX_BUF){
        if (bytes_read != 1){ 
        bw = snprintf(line,1024,"   %d  ",i);
        i++;
        if (write(1,line,bw) == -1) perror("Erro na função write");
        }
        if (write(1,buffer,bytes_read) == -1) perror("Erro na função write");
    }
    }

    close(fd_destino);
    close(fd_origem);

    return 0;
}

//Se diminuirmos o tamnho do buffer para um numero muito pequeno o tempo aumenta visto que
//vamos buscar um caracter de cada vez ao disco 

//Principio fundamental - otimizar os acessos

//ctrl + d - imprime o end of file

//off_t lseek(int fildes, off_t offset, int whence);
//whence - SEEK_SET, SEEK_CUR, SEEK_END,...
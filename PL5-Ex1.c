#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int cond;
    execlp("ls","ls","-l",NULL);
    printf("Correu mal\n");
}
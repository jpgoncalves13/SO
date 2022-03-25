#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]){
    int cond;
    if (execlp("ls","ls","-l",NULL) == -1) exit(1);
}
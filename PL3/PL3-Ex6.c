#include <sys/wait.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int line[MAX];
    int mat[10][MAX], status, i, j, a;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }
    if (argc == 2)
    {
        for (i = 0; i < 10; i++)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                for (j = 0; j < MAX; j++)
                {
                    if (mat[i][j] == atoi(argv[1]))
                    {
                        printf("Está presente\n");
                        for (a = 0; a < MAX; a++)
                        {
                            line[a] = mat[i][a];
                        }
                        quick_sort(line, 0, MAX - 1);
                        a = 0;
                        while (a < MAX)
                        {
                            printf("%d\n", line[a]);
                            a++;
                        }
                        break;
                    }
                }
                _exit(0);
            }
            else
                wait(&status);
        }
    }
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    int M=3;
    int N=4;
    int x=1, y=100;
 
    int **a = (int**)malloc(M * sizeof(int*));
    srand(time(NULL));
    for (int i = 0; i < N; i++)  // генерировать матрицу
    {
        a[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < M; j++)
        {
            a[i][j] =rand()% (y-x + 1)+x;
        }
    }

    printf("Random matrix:\n");
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
            {
                printf (" %d ", a[i][j]);
            }
        printf ("\n");
    }

    int *mins = malloc(N * sizeof(int*));
    int index_j;
    for (int i = 0; i < N; i++)    
    {
        mins[i]=a[i][0];
        index_j = 0;
        for (int j = 0; j < M; j++)
            if (a[i][j]<mins[i])
                {
                    mins[i] = a[i][j];
                    index_j = j;
                }
    }
    for (int i = 0; i < N; i++)    
        printf (" %d ", mins[i]);

    int max = mins[0];
    int index_i = 0;
    for (int i = 0; i < N; i++)
        {
           if (mins[i]>max)
           {
               max = mins[i];
               index_i = i;
           }
        }

    printf("\nMax from mins: %d, column=%d, row=%d\n", a[index_i][index_j], index_i, index_j);

    // for (int i=0;i<N;i++)
    // for (int j=0;j<M;j++)
    // free(a[i][j]);    
    free(a);
        
    return 0;
}

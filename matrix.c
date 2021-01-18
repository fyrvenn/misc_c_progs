#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    int x=1, y=100;
    if (argc != 3)
    {
        printf("Specify the dimension of the matrix (n*m)\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
 
    // int **a = (int**)malloc(M * sizeof(int*));
    int a[N][M];
    srand(time(NULL));
    for (int i = 0; i < N; i++)  // генерировать матрицу
    {
        // a[i] = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < M; j++)
        {
            a[i][j] =rand()% (y - x + 1) + x;
        }
    }

    printf("\nThe matrix of random variables %d*%d:\n", N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            {
                printf ("%d\t", a[i][j]);
            }
        printf ("\n");
    }

    int mins[N];
    int index_j[N];
    for (int i = 0; i < N; i++)    
    {
        mins[i]=a[i][0];
        index_j[i] = 0;
        for (int j = 0; j < M; j++)
            if (a[i][j]<mins[i])
                {
                    mins[i] = a[i][j];
                    index_j[i] = j;
                }
    }

    printf("\nMinimal values by row:\n");
    for (int i = 0; i < N; i++)    
        printf ("%d\t", mins[i]);

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
    int j = index_j[index_i];
    printf("\nThe maximum variables from the minimums: %d, row=%d, column=%d\n", a[index_i][j], index_i + 1, j + 1);
        
    return 0;
}

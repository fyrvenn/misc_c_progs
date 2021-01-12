#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    int M;
    int N;
    int x=1, y=100;
    if (argc!=3)
    {
        printf("Укажите размерность матрицы (n*m)\n");
        return 1;
    }

    N = atoi(argv[1]);
    M = atoi(argv[2]);
 
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

    printf("Матрица случайных чисел размерности %d*%d:\n", N, M);
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
            {
                printf (" %d ", a[i][j]);
            }
        printf ("\n");
    }

    int *mins = malloc(N * sizeof(int*));
    int *index_j = malloc(N * sizeof(int*));
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

    printf("Минимальные значения по строкам:\n");
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
    int j = index_j[index_i];
    printf("\nМаксимальное из минимумов: %d, строка=%d, столбец=%d\n", a[index_i][j], index_i+1, j+1);

    for (int i=0;i<N;i++)
    free(a[i]);    
    free(a);
    free(index_j);
        
    return 0;
}

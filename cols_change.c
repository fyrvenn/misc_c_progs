#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    int M;
    int N;
    int x=-10, y=100;
    if (argc!=3)
    {
        printf("Укажите размерность матрицы (n*m)\n");
        return 1;
    }

    N = atoi(argv[1]);
    M = atoi(argv[2]);
 
    int a[N][M];
    srand(time(NULL));
    for (int i = 0; i < N; i++)  // генерировать матрицу
    {
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
                printf ("%d\t", a[i][j]);
            }
        printf ("\n");
    }
        
    return 0;
}

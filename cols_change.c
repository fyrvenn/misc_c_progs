#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void reformat_arr(int n, int m, int arr[][m]);

int main(int argc, char* argv[]) {
    
    int x = -10, y = 100;
    if (argc != 3)
    {
        printf("Specify the dimension of the matrix (n*m)\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
 
    int a[N][M];
    srand(time(NULL));
    for (int i = 0; i < N; i++)  // генерировать матрицу
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = rand() % (y - x + 1) + x;
        }
    }


    for (int i = 0; i < N; i++)  // переопределить матрицу
    {   
        int num = N + 1;
        int max = a[i][0];
        for (int j = 0; j < M; j++)
        {
            if (j > num)
                a[i][j] = max;
            if (a[i][j] < 0)
                num = j;
            if (a[i][j] > max)
                max = a[i][j];
        }
    }

    printf("\nThe matrix of random variables %d*%d:\n", N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
        
    reformat_arr(N, M, a);

    return 0;
}


void reformat_arr(int n, int m, int arr[][m])
{   
    _Bool flag[m];
    for (int j = 0; j < m; j++)
    {
        flag[j] = 1;
        for (int i = 0; i < n; i++)
            if (arr[i][j] % 2 == 0) // проверка на чётность
                flag[j] = 0; 
    }

    printf("\nReformated:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (flag[j] == 0)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }   
}
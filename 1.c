#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define M 5
#define N 10
int main()
{
  int a[M][N];
  int i, j;

  for(i = 0; i < M; i++)
    for(j = 0; j < N; j++)
      a[i][j] = rand()%100;

  for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
        printf("%5d", a[i][j]);
      printf("\n");
    }
  int min[N];
  for(i = 0; i < N; i++)
    min[i]=INT_MAX;
  for(i = 0; i < M; i++)
    {
     for(j = 0; j < N; j++)
        if (a[i][j]<min[j])
            min[j]=a[i][j];
    };
      for(i = 0; i < N; i++)
    printf ("min = %d\n", min[i]);
  return 0;
}

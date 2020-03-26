#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define M 5
#define N 10
int main()
{
  int a[M][N];
  int i, j, tml;

  for(i = 0; i < M; i++)
    for(j = 0; j < N; j++)
      a[i][j] = rand()%100;

  for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
        printf("%5d", a[i][j]);
      printf("\n");
    }
  int min[M], mini[M], max[M], maxi[M], minj[N], maxj[N];
  for(i = 0; i < M; i++)
  {
      min[i]=INT_MAX;
      max[i]=INT_MIN;
  };
  for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
      {
        if (a[i][j]<min[i])
        {
            min[i]=a[i][j];
            minj[i]=j;
        }
        if (a[i][j]>max[i])
        {
            max[i]=a[i][j];
            maxj[i]=j;
        }
      }
    }
  for(i = 0; i < M; i++)
        printf ("min=%d\nmax=%d\n\n", min[i], max[i]);
  for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
      {
        if (a[i][j]<min[i])
        {
            min[i]=a[i][j];
            minj[i]=j;
        }
        if (a[i][j]>max[i])
        {
            max[i]=a[i][j];
            maxj[i]=j;
        }
      }
      tml=min[i];
      min[i]=max[i];
      max[i]=tml;
      a[i][minj[i]]=max[i];
      a[i][maxj[i]]=min[i];
   }
   for(i = 0; i < M; i++)
    {
      for(j = 0; j < N; j++)
        printf("%5d", a[i][j]);
      printf("\n");
    }
  return 0;
}

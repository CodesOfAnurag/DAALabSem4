#include<stdio.h>
#include<stdlib.h>
int a[100][100], v[100], w[100], item[100];
void disp(int row, int col)
{
    int i,j;
    for (i=0; i<=row; i++)
    {
        for (j=0; j<=col; j++)
        printf("%d\t", a[i][j]);
        printf("\n");
    }
}
void main()
{
    int n, cap, i, j;
    
    printf("N(Items) : ");
    scanf("%d", &n);

    printf("Enter Values : ");
    for(i=1; i<=n; i++)
        scanf("%d", &v[i]);

    printf("Enter Weights : ");
    for(i=1; i<=n; i++)
        scanf("%d", &w[i]);
    
    printf("N(Capacity) : ");
    scanf("%d", &cap);

    for (i=1; i<=n; i++)
        for (j=1; j<=cap; j++)
            if (j-w[i]>=0 && a[i-1][j-w[i]]+v[i] > a[i-1][j])
                a[i][j] = a[i-1][j-w[i]]+v[i];
            else
                a[i][j] = a[i-1][j];


    disp(n,cap);
    int max = a[n][cap];
    i=n;
    j=cap;
    int k=0;
    while(max!=0)
    {
        if (a[i-1][j]!=a[i][j])
        {
            item[k++]=v[i];
            max-=v[i];
            j-=w[i];
        }
        i--;
    }
    printf("MaxCap : %d\nItems : ",a[n][cap]);
    for(i=0; i<k; i++)
        printf("->%d ", item[i]);
    printf("\n");
}

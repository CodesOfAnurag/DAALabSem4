#include<stdio.h>
#include<stdlib.h>
int a[20][20];

void disp(int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void wars(int n)
{
    int i,j,k;
    for(k=0; k<n; k++)
    for(i=0; i<n; i++)
    for(j=0; j<n; j++)
    if (a[i][j] || a[i][k] && a[k][j])
        a[i][j]=1;
}

void main()
{
    int i, j, k, n;
    
    printf("------------------------------\n");
    printf("\tMatrix\n");
    printf("------------------------------\n");
    printf(" Enter Rank of Matrix: ");
    scanf("%d", &n);
    printf(" Enter Matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);
    printf("------------------------------\n");
    printf("\tEntered Matrix\n");
    printf("------------------------------\n");
    disp(n);
    printf("------------------------------\n");
    printf("\tWarshall Matrix\n");
    printf("------------------------------\n");
    wars(n);
    disp(n);
    printf("------------------------------\n");
}

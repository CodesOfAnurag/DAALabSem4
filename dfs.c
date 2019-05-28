#include<stdio.h>
#include<stdlib.h>

int a[20][20], reach[20], visord[20], count=0, n;

void dfs(int v)
{
    int i;
    count++;
    reach[v]=count;
    for(i=1; i<=n; i++)
        if(a[v][i] && !reach[i])
        {
            printf("%c -> %c\n", v+64, i+64);
            dfs(i);
        }
}

void main()
{
    int src, i, j, nc=0;

    printf("n(Vertex) : ");
    scanf("%d", &n);

    printf("Adj Matrix : \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    printf("Source : ");
    scanf("%d", &src);
    
    dfs(src);

    for(i=1; i<=n; i++)
        if (!reach[i])
        {
            printf("\n");
            dfs(i);
            nc=1;
        }

    for (i=1; i<=n; i++)
        visord[reach[i]]=i;

    printf("\nDFS Traversal : ");
    for (i=1; i<=n; i++)
        printf("%c ",visord[i]+64);

    if(nc)
        printf("\nNot Connected Graph\n");
    else
        printf("\nConnected Graph\n");
}

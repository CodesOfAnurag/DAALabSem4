#include<stdio.h>
#include<stdlib.h>

int n, count=0, a[20][20], visord[20], reach[20], q[20];

void bfs(int src)
{
    int f=0, r=-1, u, v;
    count++;
    reach[src]=count;
    q[++r]=src;
    while(f<=r)
    {
        u=q[f++];
        for(v=1; v<=n; v++)
        if(a[u][v] && !reach[v])
        {
            count++;
            reach[v]=count;
            q[++r]=v;
            printf("%c -> %c\n", u+64, v+64);
        }
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

    bfs(src);

    for (i=1; i<=n; i++)
    if (!reach[i])
    {
        printf("\n");
        bfs(i);
        nc=1;
    }

    for (i=1; i<=n; i++)
        visord[reach[i]]=i;

    printf("\nBFS Traversal : ");
    for (i=1; i<=n; i++)
        printf("%c ",visord[i]+64);

    if(nc)
        printf("\nNot Connected Graph\n");
    else
        printf("\nConnected Graph\n");
}
#include<stdio.h>

int visited[20], cost[20][20], mincost=0, n, ne=1, min, a, b;

void printline()
{
    printf("-------------------------\n");
}

void basic()
{
    int i,j;
    printline();
    printf("N(vertex) : ");
    scanf("%d", &n);
    printline();
    printf("Cost matrix :\n");
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j]==0)  cost[i][j]=999;
        }
    printline();
}


void main()
{
    basic();
    int i, j;
    visited[1]=1;
    printf("Minimum spamming tree : \n");
    printline();
    while(ne<n)
    {
        for(i=1, min=999; i<=n; i++)
            for(j=1; j<=n; j++)
                if (cost[i][j]<min && visited[i]!=0)
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
        if (visited[b]==0)
        {
            printf("%d : %c -> %c : %d\n", ne++, a+64, b+64, min);
            visited[b]=1;
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printline();
    printf("MinCost : %d\n", mincost);
    printline();
}


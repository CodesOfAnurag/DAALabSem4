#include<stdio.h>
#include<math.h>
int board[20], count=1;

int place(int row, int col)
{
    int i;
    for(i=1; i<=row-1; i++)
        if (board[i]==col)
            return 0;
        else if(abs(board[i]-col)==abs(i-row))
            return 0;
    return 1;
}

void print_sol(int n)
{
    int i, j;
    printf("\nSolution - %d\n", count++);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            if (board[i]==j)    
                printf("Q ");
            else    
                printf("~ ");
        printf("\n");
    }
}

void queen(int row, int n)
{
    int col;
    for(col=1; col<=n; col++)
    if (place(row,col))
    {
        board[row]=col;
        if (row==n)
            print_sol(n);
        else
            queen(row+1, n);        
    }
}

void main()
{
    int n;
    printf("N(Queens) : ");
    scanf("%d", &n);
    if (n>3)
        queen(1,n);
    else
        printf("No Solution\n");
    printf("\n");
}
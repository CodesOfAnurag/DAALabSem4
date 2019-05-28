#include<stdio.h>

void heapify(int h[], int n)
{
    int i, j, k, heap=0, v;

    for(i=n/2; i>=1; i--)
    {
        k=i;
        v=h[k];
        heap=0;
        if(2*k<=n && !heap)
        {
            j=2*k;
            if (j<n)
                if (h[j]<h[j+1])
                    j++;
            if (v > h[j])
                heap=1;
            else
            {
                h[k]=h[j];
                k=j;
            }
            h[k]=v;
        }
    }
}

void main()
{
    int h[7]={15, 12, 9, 20, 55, 1, 0};
    
    int n=6, size=6, i;

    for(i=n; i>=1; i--)
    {
        int t=h[i];
        h[i]=h[1];
        h[1]=t;
        size=i-1;
        heapify(h,size);
    }

    for(i=1; i<=n; i++)
        printf("%d ",h[i]);
    printf("\n");



}
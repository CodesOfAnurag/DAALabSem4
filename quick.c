#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp= *a;
    *a= *b;
    *b=temp;
}

int part(int a[], int l, int r)
{
    int i=l+1, j=r, piv=l;
    while(i<j)
    {
        while(a[i]<=a[piv] && i<r)
            i++;
        while(a[j]>=a[piv] && j>l)
            j--;
        swap(&a[i], &a[j]);
    }
    swap(&a[i], &a[j]);
    swap(&a[piv], &a[j]);
    return j;
}

void quick(int a[], int l, int r)
{
    if (l<r)
    {
        int piv = part(a, l, r);
        quick(a, l, piv-1);
        quick(a, piv+1, r);
    }
}

void disp(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void assign(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=rand() % 10000;
}

int main()
{
    int a[1000000], n, i;
    printf("----------------------------------------\n");
	printf("\ttesting : quick sort\n");
    printf("----------------------------------------\n");
	printf("Enter Size: ");
	scanf("%d", &n);
    assign(a, n);

	printf("Unsorted Array: ");
	disp(a,n);

	quick(a,0,n-1);

	printf("Sorted Array: ");
	disp(a,n);

    printf("----------------------------------------\n");
	printf("\tgraph : quick sort\n");
    printf("----------------------------------------\n");
    printf(" Size\t\t -  Time\n");
    printf("----------------------------------------\n");
	clock_t start, end;
	double total;

	for(i=100000; i<=1000000; i+=100000)
	{
		start=clock();
		assign(a,i);
		quick(a,0,i-1);
		end=clock();
		total=(double)(end-start)/(CLOCKS_PER_SEC);
		printf("  %d\t   %lf\n", i, total);
	}

    printf("----------------------------------------\n");
    return 0;
}
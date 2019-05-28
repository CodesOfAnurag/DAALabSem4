#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void assign(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		a[i]=rand() % 10000;
}

void sel(int a[], int n)
{
	int i,j,min;
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
			if(a[j]<a[min])		
				min=j;
		swap(&a[min], &a[i]);
	}
}

void main()
{
	int a[100000], n, i;
	printf("---- testing ----\n");
	printf("Enter Size: ");
	scanf("%d", &n);
	/*
	printf("Enter Array: ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	*/
	assign(a, n);

	printf("Unsorted Array: ");
	disp(a,n);

	sel(a,n);

	printf("Sorted Array: ");
	disp(a,n);

	printf("---- graph ----\n");
	clock_t start, end;
	double total;

	for(i=10000; i<=100000; i+=10000)
	{
		start=clock();
		assign(a,i);
	    sel(a,i);
		end=clock();
		total=(double)(end-start)/(CLOCKS_PER_SEC);
		printf("%d - %lf\n", i, total);
	}
	
}
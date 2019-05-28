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

void assign(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
		a[i]=rand() % 10000;
}

void bub(int a[], int n)
{
	int i,j,temp;
	for(i=0; i<n; i++)
	{	for(j=0; j<n-i-1; j++)
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				//disp(a,n);
			}
	//printf("\n");
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

	bub(a,n);

	printf("Sorted Array: ");
	disp(a,n);

	printf("---- graph ----\n");
	clock_t start, end;
	double total;

	for(i=10000; i<=100000; i+=10000)
	{
		start=clock();
		assign(a,i);
		bub(a,i);
		end=clock();
		total=(double)(end-start)/(CLOCKS_PER_SEC);
		printf("%d - %lf\n", i, total);
	}

}
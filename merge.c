#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high)
{
    int i=low, j=mid+1, k=0, size=(high-low+1);
    int c[size];
    while(i<=mid & j<=high)
        if (a[i]>a[j])
            c[k++]=a[j++];
        else
            c[k++]=a[i++];
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    k=0;
    for(i=low; i<=high; i++)
        a[i]=c[k++];
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a,low, mid, high);
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
    
	printf("---- testing ----\n");
	printf("Enter Size: ");
	scanf("%d", &n);
    assign(a, n);

	printf("Unsorted Array: ");
	disp(a,n);

	mergesort(a,0,n-1);

	printf("Sorted Array: ");
	disp(a,n);

	printf("---- graph ----\n");
	clock_t start, end;
	double total;

	for(i=100000; i<=1000000; i+=100000)
	{
		start=clock();
		assign(a,i);
		mergesort(a,0,i-1);
		end=clock();
		total=(double)(end-start)/(CLOCKS_PER_SEC);
		printf("%d - %lf\n", i, total);
	}

    return 0;
}
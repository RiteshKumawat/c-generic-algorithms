#include <stdio.h>
void selectionSort(int *arr,int n)
{
	int e,f,g,m,si;
	e=0;
	while(e<=n-2)
	{
		si = e;
		f=e+1;
		while(f<=n-1)
		{
		if(arr[f]<arr[si])
		{
			si = f;
		}
		f++;
		}
		g = arr[e];
		arr[e] = arr[si];
		arr[si] = g;
		e++;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the requirement : ");
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		printf("Enter the number\n");
		scanf("%d",&arr[i]);
	}

	selectionSort(arr,n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
#include<stdio.h>
void linearSort(int *arr,int n)
{
	int e,f,g,es,os;

	os = n-2;
	es = n-1;
	e = 0;
	while(e<=os)
	{
		f = e+1;
		while(f<=es)
		{
			if(arr[f]<arr[e])
			{
				g = arr[e];
				arr[e] = arr[f];
				arr[f] = g;
			}
			f++;
		}
		e++;
	}
}

int main()
{
	int n;
	printf("Enter the requirement : ");
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
	printf("Enter the number  : ");
	scanf("%d",&arr[i]);
	}

	linearSort(arr,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
}
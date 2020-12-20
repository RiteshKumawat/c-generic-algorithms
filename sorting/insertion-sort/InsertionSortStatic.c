#include <stdio.h>


void InsertionSort(int *x,int n)
{
	int y,z,num;
	y =1;
	while(y<=n-1)
	{
		z=y-1;
		num = x[y];
		while(z>=0 && num<x[z])
		{
			x[z+1] = x[z];
			z--;
		}
		x[z+1] = num;
		y++;
	}
}

int main(int argc, char const *argv[])
{
	int arr[10];
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",&arr[i]);
	}

	
	InsertionSort(arr,10);

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
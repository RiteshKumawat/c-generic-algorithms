#include <stdio.h>
#include <stdlib.h>

void merge(int *x,int low,int mid,int high)
{
	int i1,i2,i3,lb1,lb2,lb3,ub1,ub2,ub3;
	int n = (high-low)+1;
	int *temp;
	temp = (int*)malloc(sizeof(int)*n);
	lb1 = low;
	ub1 = mid;
	lb2 = mid+1;
	ub2 = high;
	lb3 = 0;
	ub3 = ub2;
	i1 = lb1;
	i2 = lb2;
	i3=0;
	while(i1<=ub1 && i2<=ub2)
	{
		if(x[i1]<x[i2])
		{
			temp[i3] = x[i1];
			i1++;
		}
		else
		{
			temp[i3] = x[i2];
			i2++;
		}
		i3++;
	}
	while(i1<=ub1)
	{
		temp[i3] = x[i1];
		i1++;
		i3++;
	}
	while(i2<=ub2)
	{
		temp[i3] = x[i2];
		i2++;
		i3++;
	}

	i3=0;
	i1 = lb1;
	i2 = lb2;
	while(i1<=ub1)
	{
		x[i1] = temp[i3];
		i1++;
		i3++;
	}
	while(i2<=ub2)
	{
		x[i2] = temp[i3];
		i2++;
		i3++;
	}
free(temp);
}


void mergeSort(int *x,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid = (high+low)/2;
		mergeSort(x,low,mid);
		mergeSort(x,mid+1,high);
		merge(x,low,mid,high);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}
	free(arr);
	return 0;
}

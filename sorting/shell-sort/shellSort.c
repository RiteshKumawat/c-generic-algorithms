#include <stdio.h>

void radixSort(int *x,int n)
{
	int y,num,z,diff,lb,ub,size;
	lb = 0;
	ub = n-1;
	y = 1;
	size = (ub-lb)+1;
	diff = size/2;
	while(diff>=1)
	{
	y = lb+diff;
	while(y<=ub)
	{
		num = x[y];
		z=y-diff;
		while(z>=0 && x[z]>num)
		{
			x[z+diff] = x[z];
			z = z - diff;
		}
		x[z+diff] = num;
		y = y+diff;
	}
	diff = diff / 2;
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i) scanf("%d",&arr[i]);

	radixSort(arr,n);

	for (int i = 0; i < n; ++i) printf("%d\n",arr[i]);
	return 0;
}
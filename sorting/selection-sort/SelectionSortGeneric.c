#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selectionSort(void *arr,int cs,int es,int (*p2f)(void*,void*))
{
	int e,f,si,w;
	void *a,*b,*c;
	c = malloc(es);
	e=0;
	while(e<=cs-2)
	{
		si = e;
		f=e+1;
		while(f<=cs-1)
		{
		a = arr + (f*es);
		b = arr + (si*es);
		w = p2f(a,b);
		if(w<0)
		{
			si = f;
		}
		f++;
		}

		a = arr  + (e*es);
		b = arr  + (si*es);

		memcpy(c,(const void*)a,es);
		memcpy(a,(const void*)b,es);
		memcpy(b,(const void*)c,es);
		e++;
	}
}

int myComparator(void *left,void *right)
{
	int *a,*b;
	a = (int*)left;
	b = (int*)right;
	return (*a) - (*b);
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

	selectionSort(arr,n,sizeof(int),myComparator);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}
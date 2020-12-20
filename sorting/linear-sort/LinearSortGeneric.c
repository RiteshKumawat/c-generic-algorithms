#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void linearSort(void *arr,int cs,int es,int (*p2f)(void*,void*))
{
	int e,f,w,ep,op;
	void *a,*b,*c;
	c = malloc(es);
	op = cs-2;
	ep = cs-1;
	e = 0;
	while(e<=op)
	{
		f = e+1;
		while(f<=ep)
		{
			a = arr + (f*es);
			b = arr + (e*es);
			w = p2f(a,b);
			if(w<0)
			{
				memcpy(c,(const void*)a,es);
				memcpy(a,(const void*)b,es);
				memcpy(b,(const void*)c,es);
			}
			f++;
		}
		e++;
	}
}

int myComparator(void *left,void *right)
{
	int *a,*b;
	a = (int*)left;
	b = (int*) right;
	return (*a) - (*b);
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

	linearSort(arr,n,sizeof(int),myComparator);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
}
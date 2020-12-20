#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubbleSort(void *arr,int cs,int es, int (*p2f)(void*,void*))
{
	int e,f,w,m;
	void *a,*b,*c;
	c = malloc(es);
	m = cs-2;

	while(m>=0)
	{
		e=0;
		f=1;
		while(e<=m)
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
			e++;
			f++;
		}
		m--;
	}
	free(c);
}

int myComparator(void *left,void *right)
{
	int *a,*b;
	a = (int *)left;
	b= (int *)right;
	return (*a)-(*b);
}


int main(int argc, char const *argv[])
{
	int req;
	int *arr;
	printf("Enter the req : ");
	scanf("%d",&req);
	arr = (int *)malloc(sizeof(int)*req);
	if(arr==NULL)
	{
		printf("Cannot able to allocate memory");
		return 0;
	}
	for (int i = 0; i < req; ++i)
	{
		printf("Enter the number : ");
		scanf("%d",&arr[i]);
	}

	bubbleSort(arr,req,sizeof(int),myComparator);

	for (int i = 0; i < req; ++i)
	{
		printf("%d ",arr[i]);
	}
	free(arr);
	return 0;
}
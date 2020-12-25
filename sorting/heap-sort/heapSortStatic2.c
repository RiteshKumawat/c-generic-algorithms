#include <stdio.h>
#include <stdlib.h>

void heapSort(int *x,int lb,int ub)
{
	//Convert to max heap
	int ri,ci,swi,g,lci,rci,y;
	y=lb+1;
	while(y<ub)
	{
	ci = y;
	while(ci<ub)
	{
		ri = (ci-1)/2;
		if(x[ci]>x[ri])
		{
			g = x[ci];
			x[ci] = x[ri];
			x[ri] = g;
			ci=ri;
		}
		else
		{
			break;
		}
	}
	y++;
	}
//heapSort implementation

y=ub;
while(y>lb)
{
//swaping last and first;
g=x[lb];
x[lb] = x[y];
x[y] = g;
y--;
//
ri = lb;
while(ri<y)
{
	lci = (ri*2)+1;
	if(lci>y)break;
	rci = lci+1;
	if(rci>y)
	{
		swi=lci;
	}
	else
	{
		if(x[lci]>x[rci])
		{
			swi = lci;
		}
		else
		{
			swi = rci;
		}
	}
	if(x[swi]>x[ri])
	{
		g = x[swi];
		x[swi] = x[ri];
		x[ri] = g;
		ri = swi;
	}
	else
	{
		break;
	}
}
}
}


int main()
{
	int n;
	scanf("%d",&n);
	int *temp;
	temp = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&temp[i]);
	}
	heapSort(temp,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",temp[i]);
	}

	free(temp);

	return 0;
}
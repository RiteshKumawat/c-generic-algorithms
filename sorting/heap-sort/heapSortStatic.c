#include<stdio.h>
void heapSort(int *x,int n)
{
	int lci,rci,y,ri,g,swp;
	y = n-1;
	while(y>0)
	{
		g=x[0];
		x[0]=x[y];
		x[y]=g;
		y--;
		//-------------
		ri=0;
		while(ri<y)
		{
			lci = (ri*2)+1;
			if(lci>y) break;
			rci = lci+1;
			if(rci>y)
			{
				swp = lci;
			}
			else
			{
				if(x[lci]>x[rci])
				{
					swp = lci;
				}
				else
				{
					swp = rci;
				}
			}
			if(x[swp]>x[ri])
			{
				g=x[swp];
				x[swp] = x[ri];
				x[ri] = g;
				ri = swp;
			}
			else
			{
				break;
			}
		}
	}
}


void maxHeap(int *x,int n)
{
	int y,g,ci,ri;

	y=1;
	while(y<=n-1)
	{
		ci=y;
		while(ci>0)
		{
			ri = (ci-1)/2;
			if(x[ci]>x[ri])
			{
				g = x[ri];
				x[ri] = x[ci];
				x[ci] = g;
				ci = ri;
			}
			else break;
		}
		y++;
	}

}


void displayContents(int *arr,int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}	
	maxHeap(arr,n);
	displayContents(arr,n);
	printf("__________________________\n");
	heapSort(arr,n);
	displayContents(arr,n);

	return 0;
}
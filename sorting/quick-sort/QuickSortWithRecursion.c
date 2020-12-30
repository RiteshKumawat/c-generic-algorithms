#include<iostream>

int partitionPoint(int *x,int lb,int ub)
{
int e,f,g,num;
e=lb;
f=ub;
num = x[lb];
while(e<f)
{
while(e<=ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb])f--;
if(e<f)
{
	g = x[e];
	x[e] = x[f];
	x[f]=g;
}
else
{
	g = x[lb];
	x[lb] = x[f];
	x[f] = g;
}
}
return f;
}



void quickSort(int *x,int lb,int ub)
{
int pp;
if(lb>=ub) return;
pp = partitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int *x;
	x = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x[i]);
	}

	quickSort(x,0,n-1);

	for (int i = 0; i < n; ++i) printf("%d\n",x[i]);
	free(x);
	return 0;
}
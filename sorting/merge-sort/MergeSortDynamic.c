#include <stdio.h>

void merge(int *x,int lb1,int lb2,int ub1,int ub2)
{
	int i1,i2,i3,lb3,ub3;
	int n = ((ub1-lb1)+1) + ((ub2-lb2)+1);
	int temp[n];
	lb3 = lb1;
	ub3 = ub2;

	i1 = lb1;
	i2 = lb2;
	i3 = 0;

	//three fingers at 3 sections logic
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

	//i2 section crossed the ub2, 
	//now remaining elements from i1 section copy to temp array
	while(i1<=ub1)
	{
		temp[i3] = x[i1];
		i1++;
		i3++;
	}

//i1 section crossed the ub1, 
	//now remaining elements from i2 section copy to temp array
	while(i2<=ub2)
	{
		temp[i3] = x[i2];
		i2++;
		i3++;
	}


	i1 = lb1;
	i2 = lb2;
	i3 = 0;


//Copy back at given sections
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
	

}

void mergeSort(int *x,int lb,int ub)
{
	int top1,top2,a,b,mid,n,lb1,lb2,ub1,ub2;
	
	n = (ub-lb)+1;
	int stack1[n][2];
	int stack2[n][2];
	
	top1=top2=n;

	top1--;
	stack1[top1][0] = lb;
	stack1[top1][1] = ub;

	//Generating series
	while(top1!=n)
	{
		a = stack1[top1][0];
		b = stack1[top1][1];
		top1++;

		top2--;
		stack2[top2][0]=a;
		stack2[top2][1]=b;
		mid = (a+b)/2;
		if(a<mid)
		{
			top1--;
			stack1[top1][0] = a;
			stack1[top1][1] = mid;
		}
		if(mid+1<b)
		{
			top1--;
			stack1[top1][0] = mid+1;
			stack1[top1][1] = b;
		}
	}

	while(top2!=n)
	{


		lb1 = stack2[top2][0];
		ub2 = stack2[top2][1];
		top2++;

		ub1 = (ub2+lb1)/2;
		lb2 = ub1+1;

		merge(x,lb1,lb2,ub1,ub2);

	}



}

int main()
{
	int n;
	printf("Enter the requirement :  ");
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		printf("Enter the number : ");
		scanf("%d",&arr[i]);
	}

	mergeSort(arr,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",arr[i]);
	}

}

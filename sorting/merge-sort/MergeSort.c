#include<stdio.h>
int main()
{

	int stack1[10][2];
	int stack2[10][2];
	int i,i1,i2,i3,top1,top2,mid,temp[10],arr[10],a,b,lb1,lb2,lb3,ub1,ub2,ub3;

	top1=top2 = 10;
	for(i=0;i<10;i++)
	{
		printf("Enter the number : ");
		scanf("%d",&arr[i]);
	}

	printf("done\n");

	top1--;
	stack1[top1][0] = 0;
	stack1[top1][1] = 9;

	while(top1!=10)
	{
		a = stack1[top1][0];
		b = stack1[top1][1];
		top1++;


		top2--;
		stack2[top2][0] = a;
		stack2[top2][1] = b;

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

		//breaking logic ends we have genrated our series in stack2

		while(top2!=10)
		{
			lb1 = stack2[top2][0];
			ub2 = stack2[top2][1];
			top2++;
			ub1 = (lb1+ub2)/2;
			lb2 = ub1+1;

			lb3 = lb1;
			ub3 = ub2;

			i1 = lb1;
			i2 = lb2;
			i3 = lb3;
			while(i1<=ub1 && i2<=ub2)
			{
				if(arr[i1]<arr[i2])
				{
					temp[i3] = arr[i1];
					i1++;
				}
				else
				{
					temp[i3] = arr[i2];
					i2++;
				}
				i3++;
			}
			while(i1<=ub1)
			{
				temp[i3] = arr[i1];
				i1++;
				i3++;
			}
			while(i2<=ub2)
			{
				temp[i3] = arr[i2];
				i2++;
				i3++;
			}
			//copy back

			i3 = lb3;
			while(i3<=ub3)
			{
				arr[i3] = temp[i3];
				i3++; 
			}
		}
	for (i = 0; i < 10; ++i)
	{
		printf("%d  ",arr[i]);
	}
	return 0;
	}
#include <stdio.h>
void bubbleSort(int *arr,int n)
{
int e,f,g,m;
m = n-2;
while(m>=0)
{
	e=0;
	f=1;
	while(e<=m)
	{
		if(arr[f]<arr[e])
		{
			g = arr[e];
			arr[e] = arr[f];
			arr[f] = g;
		}
		e++;
		f++;
	}
	m--;
}
}
int main(int argc, char const *argv[])
{
int arr[10];
for (int i = 0; i < 10; ++i)
{
	printf("Enter the Number : ");
	scanf("%d",&arr[i]);
}
bubbleSort(arr,10);
for (int i = 0; i < 10; ++i)
{
	printf("%d ", arr[i]);
}
return 0;
}

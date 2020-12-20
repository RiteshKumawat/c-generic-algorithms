#include<stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr,int size)
{
	int e,f,g,m;
	m = size - 2;
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


int main()
{
  int req;
  int *arr;
  printf("Enter the requiremnts : ");
  scanf("%d",&req);
  if(req<1)
  {
    printf("Requirement is not valid");
    return 0;
  }
  
  arr = (int *)malloc(sizeof(int)*req);
  for(int i = 0;i<req;i++)
  {
    printf("Enter the number : ");
 	scanf("%d",&arr[i]);
  }
  
  bubbleSort(arr,req);

  for(int i = 0;i<req;i++)
  {
 	printf("%d ",arr[i]);
  }

  free(arr);
}

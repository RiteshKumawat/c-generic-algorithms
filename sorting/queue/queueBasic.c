#include <stdio.h>

int queue[10];
int rear = 0;
void add(int data)
{
queue[rear]=data; 
rear++;
}
int remove()
{
int num;
int e;
num=queue[0];
while(e<rear)
{
queue[e] = queue[e+1];
e++;
}
rear--;
return num;
}

int isQueueEmpty()
{
return rear==0;
}

int isQueueFull()
{
	return rear==10;
}

int main()
{
int ch,num;
while(1)
{
	printf("1.Add to queue\n");
	printf("2.Remove to queue\n");
	printf("3.Exit\n");
	printf("Enter your Choice : ");
	scanf("%d",&ch);
	

	if(ch==1)
	{
			printf("Enter the number : ");
			scanf("%d",&num);
			if(isQueueFull())printf("Queue is full \n");
			else
			{
			add(num);
			printf("%d added to queue \n",num);
			}
	}
	if(ch==2)
	{
		if(isQueueEmpty())printf("Queue is empty \n");
		else
		{
			printf("Remove from queue : %d\n",remove());
		}
	}
	if(ch == 3) break;
}

}
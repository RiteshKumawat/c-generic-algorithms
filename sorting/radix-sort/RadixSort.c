#include <stdlib.h>
#include <stdio.h>

typedef struct _queue_node_
{
	int num;
	struct _queue_node_ *next;
}QueueNode;


typedef struct _queue_
{
	QueueNode *start;
	QueueNode *end;
	int size;
}Queue;

void initQueue(Queue *queue)
{
	queue->start = NULL;
	queue->end = NULL;
	queue->size=0;
}

void addToQueue(Queue *queue,int num)
{

	QueueNode *node;
	node = (QueueNode*)malloc(sizeof(QueueNode));
	node->num = num;
	node->next = NULL;
	if(queue->start==NULL)
	{
		queue->start=node;
		queue->end=node;
	}
	else
	{
		queue->end->next = node;
		queue->end = node;
	}
	queue->size++;
}



int removeFromQueue(Queue *queue)
{
	int num;
	QueueNode *node;
	num = queue->start->num;
	node = queue->start;
	queue->start = queue->start->next;
	if(queue->start==NULL) queue->end = NULL;
	free(node);
	queue->size--;
	return num;
}

int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}


void clearQueue(Queue *queue)
{
QueueNode *node;

while(queue->start!=NULL)
{
node = queue->start;
queue->start = queue->start->next;
queue->size--;
free(node);
}
queue->end = NULL;
queue->size = 0;
}

void radixSort(int *x,int n)
{
	int largest,dc,e,f,k,y,num,i;
	Queue queues[10];

	for (i = 0; i < n; ++i) initQueue(&queues[i]);
	
	largest = x[0];
	for (i = 1; i < n; ++i)
	{
		if(x[i]>largest)largest = x[i];
	}

	dc = 1;
	while(largest>9)
	{
		largest = largest/10;
		dc++;
	}

	//Spread 10 queues
	e = 10;
	f = 1;
	k=1;
	while(k<=dc)
	{
		y = 0 ;
		while(y<=9)
		{
			num = x[y];
			i = num%e/f;
			addToQueue(&queues[i],num);
			y++;	
		}
		y=0;
		i=0;
		while(y<=9)
		{
			while(!isQueueEmpty(&queues[y]))
			{
			x[i] = removeFromQueue(&queues[y]);
			i++;
			}
			y++;
		}
		k++;
		e = e*10;
		f = f*10;
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
	radixSort(arr,n);
	for(int i=0;i<n;i++)printf(" %d ",arr[i]);
	return 0;
}



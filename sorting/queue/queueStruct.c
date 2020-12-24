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

int main()
{
int ch,num;
Queue queue;
initQueue(&queue);
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
		addToQueue(&queue,num);
		printf("Added to queue : %d\n",num);
	}
	if(ch==2)
	{
		if(isQueueEmpty(&queue))
		{
			printf("Queue is Empty\n");
		}
		else
		{
			num = removeFromQueue(&queue);
			printf("Remove from queue : %d\n",num);
		}
	}

	if(ch==3) break;
}
clearQueue(&queue);
return 0 ;
}
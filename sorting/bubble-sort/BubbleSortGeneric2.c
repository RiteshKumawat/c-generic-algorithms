#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bubbleSort(void *arr,int cs,int es, int (*p2f)(void*,void*))
{
	int e,f,w,m;
	void *a,*b,*c;
	c = malloc(es);
	m = cs-2;

	while(m>=0)
	{
		e=0;
		f=1;
		while(e<=m)
		{
		a = arr + (f*es);
		b = arr + (e*es);
		w = p2f(a,b);
		if(w<0)
		{
			memcpy(c,(const void*)a,es);
			memcpy(a,(const void*)b,es);
			memcpy(b,(const void*)c,es);
		}
			e++;
			f++;
		}
		m--;
	}
	free(c);
}

struct Student
{
	int rollNumber;
	char name[21];
};

int myComparator(void *left,void *right)
{
	struct Student *a,*b;
	a = (struct Student*)left;
	b= (struct Student*)right;
	return (a)->rollNumber - (b)->rollNumber;
}


int main(int argc, char const *argv[])
{
	int req;
	struct Student *s;
	printf("Enter the req : ");
	scanf("%d",&req);
	s = (struct Student*)malloc(sizeof(struct Student)*req);
	if(s==NULL)
	{
		printf("Cannot able to allocate memory");
		return 0;
	}
	for (int i = 0; i < req; ++i)
	{
		printf("Enter the rollNumber number : ");
		scanf("%d",&(s[i].rollNumber));
		printf("Enter the name : ");
		scanf("%s",s[i].name);			
	}

	bubbleSort(s,req,sizeof(struct Student),myComparator);

	for (int i = 0; i < req; ++i)
	{
		printf("roll num : %d , name : %s \n",s[i].rollNumber,s[i].name);

	}
	free(s);
	return 0;
}
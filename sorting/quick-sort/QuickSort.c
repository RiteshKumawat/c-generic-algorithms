#include<stdio.h>


int partitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f = ub;
while(e<f)
{
  while(e<ub && x[e]<=x[lb])e++;
  while(x[f]>x[lb])f--;
  if(e<f)
  {
    g = x[e];
    x[e] = x[f];
    x[f] = g;
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

void quickSort(int *x,int n)
{

int stack[n][2];
int pp,top,lb,ub;
top = n;
top--;
stack[top][0] = 0;
stack[top][1] = n-1;
while(top!=n)
{
  lb = stack[top][0];
  ub = stack[top][1];
  top++;
  pp = partitionPoint(x,lb,ub);
  if(pp-1>lb)
  {
    top--;
    stack[top][0] = lb;
    stack[top][1] = pp-1;
    
  }
  if(pp+1<ub) 
  {

    top--;
    stack[top][0] = pp+1;
    stack[top][1] = ub;
    
  }
}

}


int main()
{
  int n;
  printf("Enter the requirement : ");
  scanf("%d",&n);
  int num[n];
  for(int i=0;i<n;i++)
  {
   printf("Enter the number : ");
    scanf("%d",&num[i]);
  }
  quickSort(num,n);
  for(int i=0;i<n;i++)
  {
    printf("%d\n",num[i]);
  }
 

  return 0;
}

#include<stdio.h>
void linearSort(int *arr,int n)
{
int e,f,g,is,os;
os = n-2;
is = n-1;
e = 0;
while(e<=os)
{
  f = e+1;
  while(f<=is)
  {
    if(arr[f]<=arr[e])
    {
      g=arr[f];
      arr[f] = arr[e];
      arr[e] = g;
    }
    f++;
  }
  e++;
}


}
int main()
{
  int arr[10];
  for(int i = 0;i<10;i++)
  {
    printf("Enter the number : ");
    scanf("%d",&arr[i]);
  }

  linearSort(arr,10);
   for(int i = 0;i<10;i++)
  {
    printf("%d ",arr[i]);
  }



}

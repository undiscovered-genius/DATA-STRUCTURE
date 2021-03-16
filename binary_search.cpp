#include<stdio.h>
void binarysearch(int a[],int n,int m)     
{
	int beg,end,mid,flag=0;
	beg=0;
	end=n-1;
	while(beg<=end) //stopping cond.
	{
		mid=(beg+end)/2;
		if(a[mid]==m)  // case-1
		{
	printf("\nElement found at Index %d",mid);
			flag=1;
			//getch ();
			return;
		}
		if(a[mid]>m) // case-2

		{
			end=mid-1;
		}
		if(a[mid]<m) // case-3

		{
			beg=mid+1;
		}
	}
	if(flag==0)
	     printf("\nElement not found");
	}
 int main(){
 	int a[15];
 	int n,m,i;
 	printf("\n Enter the length of array : ");
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		printf(" Enter %d Element : ",i+1);
 		scanf("%d",&a[i]);
 	}
 	printf("\n Enter the Element to be Searched : ");
 	scanf("%d",&m);
 	binarysearch(a,n,m);
 }

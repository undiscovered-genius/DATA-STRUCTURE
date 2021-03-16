#include<stdio.h>

void search(int a[5],int n,int m){
	int i, flag=0,z;
	for(i=0; i<5;i++){
		if(a[i]==m){
			
			printf("element found at pos %d",i+1);
			break;
		}
	}
	if (i == n){
		printf("\n element not found");
	}
}
int main(){
	int a[5], i;
	for(i=0;i<5;i++){
		printf("\n enter number : ");
		scanf("%d",&a[i]);
	}
	int m, n=5;
	printf("\n Enter a number to search (1-5) : ");
	scanf("%d",&m);
	search(a,n,m);
}

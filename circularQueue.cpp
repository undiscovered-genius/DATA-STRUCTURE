#include<stdio.h>
#include <stdlib.h>

int queue[10], front =-1,rear =-1,count=0;
int enqueue();
int dequeue();
int display();
int main(){
	int ch, st=1;
	printf("\n Enter the length of Queue : ");
	scanf("%d",&count);
	
	while(st==1){
	printf("\n Operation : ");
	printf("\n 1.enqueue ");
	printf("\n 2.dequeue ");
	printf("\n\n Enter your Choice : ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		default:
			printf("\n Enter valid choice");
	}
	printf("\nWant to continue? 1-YES : ");
	scanf("%d",&st);
	printf("\n\n");
	}
}

int enqueue(){
	int x, i;
	printf("\n Enter an element to be inserted : ");
	scanf("%d",&x);
	if((front==0 && rear==count-1) || (rear==(front-1)%(count-1))){
		printf("\n Queue is Full");
		return 0;
	}
	else if(front==-1){
		front = 0;
		rear = 0;
		queue[rear] = x;
	}
	else if(rear==count-1 && front!=0){
		rear = 0;
		queue[rear]=x;
	}
	else{
		rear = rear + 1;
		queue[rear] = x;
	}
	printf("\n Updated queue : ");
	display();
}

int dequeue(){
	int i,x;
	if(front==-1){
		printf("\n Queue is Empty");
	}
	x = queue[front];
	queue[front]=-1;
	if(front == rear){
		front = -1;
		rear = -1;
	}
	else if(front == count-1){
		front = 0;
	}
	else{
		front = front +1;
	}
	printf("\n Deleted element : %d",x);
	printf("\n Updated queue : ");
	display();
}

int display(){
	int  i;
	i = front;
	if(front<=rear)
	{
		while(i<=rear){
			printf("%d ",queue[i++]);
		}
	}
	else{
		while(i<=count-1){
			printf("%d ",queue[i++]);
		}
		i=0;
		while(i<=rear){
			printf("%d ",queue[i++]);
		}
	}
	printf("\n");
}

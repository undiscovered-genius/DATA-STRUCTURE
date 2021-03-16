#include<stdio.h>
#include <stdlib.h>

int queue[10], front =-1,rear =-1,count=0;
int enqueue();
int enqueue_front();
int dequeue_front();
int dequeue_rear();
int display();
int main(){
	int ch, st=1;
	printf("\n Enter the length of Queue : ");
	scanf("%d",&count);
	
	while(st==1){
	printf("\n Options : ");
	printf("\n 1. ENQUEUE - REAR ");
	printf("\n 2. ENQUEUE - FRONT ");
	printf("\n 3. DEQUEUE - FRONT ");
	printf("\n 4. DEQUEUE - REAR");
	printf("\n\n Enter your Choice : ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			enqueue();
			break;
		case 2:
			enqueue_front();
			break;
		case 3:
			dequeue_front();
			break;
		case 4:
			dequeue_rear();
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
	if((front==0 && rear==count-1) || (front==rear+1)){
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

int dequeue_front(){
	int i,x;
	if(front==-1){ //empty
		printf("\n Queue is Empty");
		return 0;
	}
	x = queue[front];
	queue[front]=-1;
	if(front == rear){ //when only 1 element is present
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

int enqueue_front(){
	int x, i;
	printf("\n Enter an element to be inserted : ");
	scanf("%d",&x);
	// check whether Deque if  full or not 
    if ((front==0 && rear==count-1) || (rear==(front-1)%(count-1))) 
    {   printf("\n Queue is Full");
		return 0; 
    }       // agar queue initially empty 
    if (front == -1) 
    {   front = 0; 
        rear = 0; 
    } 
      // front is at first position of queue 
    else if (front == 0){
    	front = count - 1 ; 
    } 
    else {
    	front = front-1;
    }// decrement front end by '1' 
         
      // insert current element into Deque 
    queue[front] = x ;
    printf("\n Updated queue : ");
	display(); 

}

int dequeue_rear(){
	if (front==-1) 
    { 
        printf("\n Queue is Empty"); 
        return 0; 
    } 
      // Deque has only one element 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (rear == 0) 
        rear = count-1; 
    else
        rear = rear-1; 
    printf("\n Updated queue : ");    
    display();    

}

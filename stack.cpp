#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define N 6

int top=-1,stack[5],bin[10];
void stack_array();

void push(){
 int n;
 if(top==5-1){
      printf("\n\nThe Stack is full!!!");
 }
 else{
      printf("\nEnter element you want to insert : ");
      scanf("%d",&n);
	  top++;
	  stack[top]=n;
      printf("\nElement Inserted Successfully!!!");
  }
}

void pop(){
 if(top==-1){
     printf("\n\nThe Stack is empty!!!");
 }
 else{
     printf("\nDeleted element is %d",stack[top]);
     top--;
 }
}

void display(){
 int i;
 if(top==-1){
    printf("\n\nStack is empty!!");
 }
 else{
    printf("\n\nStack : ");

    for(i=top;i>=0;--i){
        printf("%d ",stack[i]);
    }
 }
 }

void decimal(){
	 int dec,max,Top=-1,rem,i;
	 printf("\n Enter a +ve Decimal number : ");
	 scanf("%d",&dec);
	 max=10;
	 while(dec>0){
	 	int rem = dec%2;
	 	dec = dec / 2;
	 	if(Top>=max){
	 		printf("\n Stack overflow!");
	 	}else{
	 		Top++;
	 		bin[Top] = rem;
	 	}
	 }
	 printf("\n Binary Representation is : ");
	 for(i=Top;i>=0;i--){
	 	if(Top<0){
	 		printf("\n Stack is empty!");
	 	}else{
	 		printf("%d",bin[Top]);
	 		Top--;
	 	}
	 }
}

void parentheses(){
	 char exp[10],prth[10],tp;
	 int i,vld=0,TOP=-1;
	 printf("\n Enter an Expression : ");
	 scanf("%s",&exp);
	 for(i=0;i<strlen(exp);i++){
	 	if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
	 		TOP++;
	 		prth[TOP] = exp[i];
	 	}else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
	 		if(TOP==-1){
	 			printf("\n Invalid expression");
	 		}else{
	 			tp=prth[TOP];
	 			TOP--;
	 		}
	 		if(tp=='(' && (exp[i]== '}' || exp[i]==']')){
	 			vld = 0;
	 		}else if(tp =='{' &&(exp[i]==')' || exp[i]==']')){
	 			vld=0;
	 		}else if(tp =='[' &&(exp[i]==')' || exp[i]=='}')){
	 			vld=0;
	 		}else{
	 			vld++;
	 		}
	 	}
	 }
	 if(TOP>=0){
	 	vld=0;
	 }
	 if(vld>=1){
	 	printf("\n Valid expression");
	 }else{
	 	printf("\n Invalid expression");
	 }
}

void menu(){
 int ch,m;
 do{

 printf("\n\n-------Menu-------");
 printf("\n\n1.Stack using array");
 printf("\n2.Decimal to Binary");
 printf("\n3.Check Well Formed Parentheses");
 printf("\n4.Exit");
 printf("\n\n Enter your choice : ");
 scanf("%d",&ch);

 switch(ch){
 	
    case 1:
    	stack_array();
        break;
    case 2:
        decimal();
        break;
    case 3:
	    parentheses();
        break;
    case 4:
	    exit(0);
    default: printf("\n Invalid Input!!");
}
}while(ch!=0);
}

void stack_array(){
 	int ch,m;

 do{

 printf("\n\n-------Menu-------");
 printf("\n\n1.Push");
 printf("\n2.Pop");
 printf("\n3.Display");
 printf("\n4.Exit");
 printf("\n\n Enter your choice : ");
 scanf("%d",&ch);

 switch(ch){
 case 1: push();
         display();
         break;

 case 2: pop();
         display();
         break;

 case 3: display();
         break;
 case 4:
         menu();

 default: printf("\n Invalid Input!!");
}
}while(ch!=0);
 }
 
 main(){
      menu(); 
}

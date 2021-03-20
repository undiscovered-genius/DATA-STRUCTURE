#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node{
	public:
		int data;
		Node* nxt;
};

class list: public Node{
	Node *head, *temp;   //for list 1
	Node *head2, *tmp;   //for list 2
	public:
		list(){
			head = NULL;
			temp = NULL;
			head2 = NULL;
			tmp = NULL;
		}
		void create(int x); //LIST 1
		
		void crt(int x);	//LIST 2
		
		int menu(){
			int x;
			
			cout<<"\n1. 1st List";
			cout<<"\n2. 2nd List";
			cout<<"\n   Enter ur Choice : ";
			cin>>x;
			return x;
		}
		void display();
		
		void insrt_srt();
		
		void insrt_end();
		
		void insrt_btwn();
		
		void del_srt();
		
		void del_end();
		
		void del_bwt();
		
		void rev();
		
		void concat();
};

void list::create(int x){  //list 1
	Node * newnode = new Node;
			
	newnode->data = x;
	newnode->nxt = NULL;
			
	if(head == NULL){
		head = newnode;
		temp = newnode;
	}else{
		temp->nxt = newnode;
		temp = newnode;
	}
	cout<<" Data Added";
}

void list::crt(int x){   //list 2
	Node * newnode = new Node;
			
	newnode->data = x;
	newnode->nxt = NULL;
			
	if(head2 == NULL){
		head2 = newnode;
		tmp = newnode;
	}else{
		tmp->nxt = newnode;
		tmp = newnode;
	}
	cout<<" Data Added";
}

void list::display(){
	cout<<"\n----Display----";
	int x;
	x = menu();	
	switch(x){
		case 1:
			if(head == NULL){
		        cout<<"\n List is Empty";
	        }else{
	        	temp = head;
		       	cout<<"\n List : ";
		        while(temp->nxt != NULL ){
			        cout<<temp->data<<"->";
			        temp = temp->nxt;
		        }
		        cout<<temp->data<<"->";
		        cout<<"NULL ";
			}
			break;
		case 2:
			if(head2 == NULL){
		        cout<<"\n List is Empty";
		    }else{
	        	tmp = head2;
	        	cout<<"\n List : ";
		        while(tmp->nxt != NULL ){
			        cout<<tmp->data<<"->";
			        tmp = tmp->nxt;
		        }
		        cout<<tmp->data<<"->";
		        cout<<"NULL ";
			}
			break;
		default:
			cout<<"\n Invalid Choice!";
			}
}
void list::insrt_srt(){
	int x;
	Node * newnode = new Node;
	cout<<"\n Enter Data : ";
	cin>>x;
	newnode->data = x;
	newnode->nxt = NULL;
	newnode->nxt = head;
	head = newnode;
	cout<<" Data Added";
}

void list::insrt_end(){
	int x;
	Node * newnode = new Node;
	if(head == NULL){
		cout<<"\n List is Empty. Creating a new List";
		cout<<"\n Enter data : ";
	    cin>>x;
	    newnode->data = x;
	    newnode->nxt = NULL;
	    head = newnode;
		temp = newnode;
	}else{
		cout<<"\n Enter Data : ";
	    cin>>x;
	    newnode->data = x;
	    newnode->nxt = NULL;
	    temp = head;
	    while(temp->nxt != NULL){
   	        temp = temp->nxt;
	    }
	    temp->nxt = newnode;
	}
	cout<<" Data Added";
}

void list::insrt_btwn(){
	int x , n, i=1;
	Node * newnode = new Node;
			
	cout<<"\n Enter Position (starting from 1): "; //3
	cin>>n;
	if(n == 1){
		insrt_srt();
	}else{
		cout<<"\n Enter Data : ";
	    cin>>x;
		newnode->data = x;
	    newnode->nxt = NULL;
	    temp = head;
		while(i != (n-1)){  //i=2 
		    if(temp->nxt != NULL){
		    	temp = temp->nxt;
		        i++;
			}else{
				cout<<"\n Error! Cannot enter data at this position ";
				break;
		    }
	    }
	    newnode->nxt = temp->nxt; 
	    temp->nxt = newnode;
	}
	cout<<" Data Added";
}

void list::del_srt(){
	temp = head;
	head = temp->nxt;
	delete(temp);
	cout<<" Data Deleted";
}
void list::del_end(){
	Node *temp2;
	temp = head;
	if(head == NULL){
		cout<<" Linked List is Empty!";
	}else{
		while(temp->nxt->nxt != NULL){
		    temp=temp->nxt;
	   }
	    temp2 = temp->nxt;
	    temp->nxt = NULL;
	    delete(temp2);
	    cout<<" Data Deleted";
	}
}
void list::del_bwt(){
	Node * temp3;
	int n,i;
	temp = head;
	
	cout<<"\n Enter Position (starting from 1): ";
	cin>>n;
	if(n == 1){
		del_srt();
	}else{	
	    for(i=1;i<n-1 && temp->nxt != NULL;i++){
		    temp = temp->nxt;
		}
	    if(temp->nxt == NULL){
	    	cout<<"\n Error! Cannot delete data from this position ";
		}else{
			temp3 = temp->nxt;
	        temp->nxt = temp3->nxt;
	        delete(temp3);
	        cout<<" Data Deleted";
			}     
		}
}

void list::rev(){
	Node *cur, *pre, *fwd;
	fwd = head;
	cur = NULL;
	
	while(fwd != NULL){
		pre = cur;
		cur = fwd;
		fwd = fwd->nxt; //NULL
		cur->nxt = pre;
	}
	head = cur;
	cout<<" List Reversed";
	display();
}

void list::concat(){
	temp = head; //list1  
	  // head = 3 //temp = 3
	while(temp->nxt != NULL){  // 3 6 8  9 
		temp = temp->nxt;      // temp =  9
	}
	temp->nxt = head2;     //temp=9  head2 = 1st list2
	cout<<"   Done!";
	display();
}
int main(){
	int st =1,ch;
	list l1;
	int x,n,p,i;
			
	while(st==1){
		cout<<"\n -----Menu-----";
		cout<<"\n1.  Create";
		cout<<"\n2.  Display";
		cout<<"\n3.  Insert - Start";
		cout<<"\n4.  Insert - Intermediate";
		cout<<"\n5.  Insert - End";
		cout<<"\n6.  Delete - Start";
		cout<<"\n7.  Delete - Intermediate";
		cout<<"\n8.  Delete - End";
		cout<<"\n9.  Reverse";
		cout<<"\n10. Concatenate";
		cout<<"\n Enter Choice : ";
		cin>>ch;
		
		switch(ch){
			case 1:
			    x = l1.menu();
			    cout<<"\n Enter number of Nodes to be Created : ";
			    cin>>p;
			    switch(x){
				    case 1:
				    	for(i=0;i<p;i++){
			    	        cout<<"\n Enter data : ";
			                cin>>n;
			                l1.create(n);
				        }
					    break;
				    case 2:
				    	for(i=0;i<p;i++){
			    	        cout<<"\n Enter data : ";
			                cin>>n;
			                l1.crt(n);
				        }  
					    break;
				    default:
					    cout<<"\n Invalid Choice!";
			    }
				break;
			case 2:
				l1.display();
				break;
			case 3:
				l1.insrt_srt();
				break;
			case 4:
				l1.insrt_btwn();
				break;
			case 5:
				l1.insrt_end();
				break;
			case 6:
				l1.del_srt();
				break;
			case 7:
				l1.del_bwt();
				break;
			case 8:
				l1.del_end();
				break;
			case 9:
				l1.rev();
				break;
			case 10:
				l1.concat();
				break;
			default:
				cout<<"Invalid choice entered";
		}
		cout<<"\n Pess 1 to Countinue : ";
		cin>>st;
	}
}

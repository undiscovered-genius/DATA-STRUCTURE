#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class listgraph;

class graphnode{
	public:
	int vertex;
	graphnode *next;
	
		graphnode(int n=0){
			vertex = n;
			next = NULL;
		}
		friend class graph;
};

class listgraph{
	int n;
	graphnode *list[10];
	
	int visited[11];
	int visit[10];
	public:
		listgraph(){
			n = 5;
			for(int j=0; j<n; j++){
				list[j] = NULL;
			}
		}
		listgraph(int nov){
			n = nov;
			for(int j=0; j<n; j++){
				list[j] = NULL;
			}
		}
		void create();
		void display();
		void dfs(int v);
		void menu();
		friend class graphnode;
		friend class stack;
};

class stack {
	int top;
	graphnode * item[10];
    int items[10];
    
	public :
		stack(){
			top = -1;
		}
		
		void push(int p){
			items[++top] = p;
		}
		
		int pop(){
			return items[top--];
		}

		int isFull(){
			return top == 10;
		}
		
		int isEmpty(){
			return top == -1;
		}
};

void listgraph::menu(){
	int st = 1, ch;
	while(st == 1){
		cout<<"\n--------MENU---------";
		cout<<"\n1. Create Graph";
		cout<<"\n2. Display";
		cout<<"\n3. Depth First Search";
		cout<<"\n   Enter Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				dfs(1);
				break;
			default:
				cout<<"\n Invalid Choice!";
		}
		cout<<"\n   Press 1 to Continue : ";
		cin>>st;
	}
}

void listgraph::create(){
	int i, j;
	graphnode *temp, *newnode;
	char ans;
	for(i=0; i<n;i++){
		for(j=0; j<n; j++){
			if(i != j){
				cout<<"\n Edge between vertex "<<i+1<<" & "<<j+1<<" (y/n) : ";
		        cin>>ans;
		        if(ans == 'y' || ans == 'Y'){
			        newnode = new graphnode(j+1);
			        if(list[i] == NULL){
				        list[i] = temp = newnode;
			        }else{
				        temp->next = newnode;
				        temp = newnode;
			        }
		        }
			}
		}
	}
}

void listgraph::display(){
	graphnode *temp;
	int i;
	for(i=0;i<n;i++){
		
		temp = list[i];
		cout<<endl;
		    cout<<" Vertex "<<i+1<<" -> ";
		if(temp != NULL){
			
		    while(temp != NULL){
			    cout<<" V "<<temp->vertex<<" -> ";
			    temp = temp->next;
		    }
		    cout<<"NULL";
	    }else{
	    	cout<<" No Edges!";
	    	
		}
	}
}

void listgraph::dfs(int v){
	graphnode *temp, *temp2;
	stack s;
	int i;
	visited[v-1] = 1;
	cout<<" V"<<v<<" -> ";
	s.push(v);
	temp = list[v-1];

	while(temp != NULL){
		v = temp->vertex;
		if(visited[v-1] != 1){
			visited[v-1] = 1;
//			cout<<"\n inside while "<<v<<" \n";
			s.push(v);
			cout<<" V"<<v<<" -> ";
            temp = list[v-1];
		}else{
			temp = temp->next;
		} 	
	}
	
	while(!s.isEmpty()){
		v = s.pop();
//		cout<<"\n stack pop "<<v<<" \n";
		temp = list[v-1];
		while(temp != NULL){
			v = temp->vertex;
			if(visited[v-1] != 1){				
				visited[v-1] = 1;	
//				cout<<"\n inside stack "<<v<<" \n";			
				s.push(v);
				cout<<" V"<<v<<" -> ";
                temp = list[v-1];
			}else{
				temp = temp->next;
			}  	
		}
	}
	cout<<" ORDER \n";
}

main(){
	int v;
	cout<<"\n Enter Number of Vertex : ";
	cin>>v;
	listgraph tr1(v);
	tr1.menu();
}

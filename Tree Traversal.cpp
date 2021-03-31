#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node{
	int data;
	Node *left;
	Node *right;
	public:
		Node(int n){
			data = n;
			left = NULL;
			right = NULL;
		}
		friend class tree;
//		friend class stack;
};

class stack {
	int top;
	Node * item[10];

	public :
		stack(){
			top = -1;
		}
		
		void push(Node *p){
			item[++top] = p;
//			cout<<p;
		}
		
		Node *pop(){
			return item[top--];
		}
		
		int isFull(){
			return top == 10;
		}
		
		int isEmpty(){
			return top == -1;
		}
};
class tree{
	Node *root;
	Node *temp;
	public:
		tree(){
			root = NULL;
		}
		
		void menu();
		void create();
		void nonrec_inorder();
		void nonrec_preorder();
		void nonrec_postorder(); 
		void rec_inorder(Node *p);
		void rec_preorder(Node *p);
		void rec_postorder(Node *p);
		friend class stack;
};

void tree::menu(){
	int st = 1, ch;
	while(st == 1){
		cout<<"\n--------MENU---------";
		cout<<"\n1. Create Binary Tree";
		cout<<"\n2. non-recursive Inorder";
		cout<<"\n3. non-recursive Preorder";
		cout<<"\n4. non-recursive Postorder";
		cout<<"\n5. recursive Inorder";
		cout<<"\n6. recursive Preorder";
		cout<<"\n7. recursive Postorder";
		cout<<"\n   Enter Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				nonrec_inorder();
				break;
			case 3:
				nonrec_preorder();
				break;
			case 4:
				nonrec_postorder();
				break;
			case 5:
				cout<<"\n The Recursive Inorder traversal is : ";
				rec_inorder(root);
//				cout<<"NULL";
				break;
			case 6:
				cout<<"\n The Recursive Preorder traversal is : ";
				rec_preorder(root);
//				cout<<"NULL";
				break;
			case 7:
				cout<<"\n The Recursive Postorder traversal is : ";
				rec_postorder(root);
//				cout<<"NULL";
				break;
			default:
				cout<<"\n Invalid Choice!";
		}
		cout<<"\n   Press 1 to Continue : ";
		cin>>st;
	}
}

void tree::create(){
	Node *temp, *newnode;
	int c, choice;
	char ans;
	do{
		cout<<"Enter the element to attached : ";
		cin>>c;
		newnode = new Node(c);
		if(root == NULL){
			root = newnode;
		}else{
			temp = root;
			while(1){
				cout<<"\n Left or Right (l/r) of "<<temp->data<<" : ";
				cin>>ans;
				if(ans == 'l'){
				    if(temp->left == NULL){
					    temp->left = newnode;
					    break;
				    }else{
					    temp = temp->left;
				    }
				}else{
					if(temp->right == NULL){
						temp->right = newnode;
						break;
					}else{
						temp = temp->right;
					}
				}
			}	
		}
		cout<<"\n Press 1 to Add data : ";
		cin>>choice;
	}while(choice == 1);
}

void tree::rec_preorder(Node *p){   //root->left->right
	if(p != NULL){
		cout<<p->data<<"  ";
		rec_preorder(p->left);
		rec_preorder(p->right);
	}
}

void tree::rec_inorder(Node *p){  //left->root->right
	if(p != NULL){
		rec_inorder(p->left);
		cout<<p->data<<"  ";
		rec_inorder(p->right);
	}	
}

void tree::rec_postorder(Node *p){  //left->right->root
	if(p != NULL){
		rec_postorder(p->left);
		rec_postorder(p->right);
		cout<<p->data<<"  ";
	}
}

void tree::nonrec_inorder(){  //left->root->right
	Node *temp2 = root;
	stack s;
	cout<<"\n The Non-Recursive Inorder traversal is : ";
	while(1){
		while(temp2 != NULL){
//			cout<<temp2->data;
			s.push(temp2);
			temp2 = temp2->left;
		}
		if(s.isEmpty()){
//			cout<<"Stack in underflow";
			break;
		}
		temp2 = s.pop();
		cout<<temp2->data<<"  ";
		temp2 = temp2->right;
	}
//	cout<<"NULL";
}

void tree::nonrec_preorder(){   //root->left->right
	Node *temp3 = root;
	stack s;
	cout<<"\n The Non-Recursive Preorder traversal is : ";
	s.push(temp3);
	while(1){
		
		while(temp3 != NULL){ 
			cout<<temp3->data<<"  ";
			
			if(temp3->right){
//			    temp3 = temp3->right;
			    s.push(temp3->right);
		    }
//		    if(temp3->left){
////			    temp3 = temp3->left;
//			    s.push(temp3->left);
//		    }
            temp3 = temp3->left;
		}
		temp3 = s.pop();
		if(s.isEmpty()){
			break;
		}
		
	}
//	cout<<"NULL";
}

void tree::nonrec_postorder(){   //left->right->root
	Node *temp2 = root;
	Node *temp3;
	stack s, ss;
	cout<<"\n The Non-Recursive Postorder traversal is : ";
	if(temp2 == NULL){
		cout<<"\n Tree is Empty";
	}
	s.push(temp2);
	while(!s.isEmpty()){
		temp3 = s.pop();
//		cout<<temp3->data<<"  ";
		ss.push(temp3);
		if(temp3->left != NULL){
			s.push(temp3->left);
		}
		if(temp3->right != NULL){
			s.push(temp3->right);
		}
	}
	while(!ss.isEmpty()){
		temp3 = ss.pop();
		cout<<temp3->data<<"  ";
	}
}

main(){
	tree tr1;
	tr1.menu();	
}

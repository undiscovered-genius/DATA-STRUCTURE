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
		void search_node(int ser);
		void delete_node(int del);
		void rec_inorder(Node *p);
};

void tree::rec_inorder(Node *p){  //left->root->right
	if(p != NULL){
		rec_inorder(p->left);
		cout<<p->data<<"  ";
		rec_inorder(p->right);
	}	
}

void tree::menu(){
	int st = 1, ch;
	int ser;
	
	while(st == 1){
		cout<<"\n--------MENU---------";
		cout<<"\n1. Create Binary Tree";
		cout<<"\n2. Search Node";
		cout<<"\n3. Delete Node";
		cout<<"\n   Enter Choice : ";
		cin>>ch;
		switch(ch){
			case 1:
				create();
//				rec_inorder(root);
				break;
			case 2:
				cout<<"\n   Enter a Element to Search : ";
				cin>>ser;
				search_node(ser);
				break;
			case 3:
				cout<<"\n   Enter a Element to Delete : ";
				cin>>ser;
				delete_node(ser);
//				rec_inorder(root);
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
				if(c < temp->data){
					if(temp->left == NULL){
					    temp->left = newnode;
					    break;
				    }else{
					    temp = temp->left;
				    }
				}else if(c > temp->data){
					if(temp->right == NULL){
						temp->right = newnode;
						break;
					}else{
						temp = temp->right;
					}
				}else if(c == temp->data){
					cout<<" Cannot store duplicate element in list.";
				}
			}	
		}
		cout<<"\n Press 1 to Add data : ";
		cin>>choice;
	}while(choice == 1);
}

void tree::search_node(int ser){   //search
	int count, level=1;
	temp = root;
	while(1){
		if(ser == temp->data){
			cout<<"  Search Result : "<<ser<<" found at "<<" Height "<<level;
			break;
		}else if(ser < temp->data){
			if(temp->left != NULL){
				temp = temp->left;
			    level++;
			}else{
				cout<<"  Search Result : "<<ser<<" not found.";
			    break;
			}
		}else if(ser > temp->data){
			if(temp->right != NULL){
				temp = temp->right;
			    level++;
			}else{
				cout<<"  Search Result : "<<ser<<" not found.";
			    break;
			}	
		}
	}
}

void tree::delete_node(int del){   //delete
	Node *temp2, *parent=NULL, *child, *leaf;
	temp = root;
	if(temp == NULL){
		cout<<"\n Binary Tree is Empty.";
	}else{
		while((temp->data!=del) && (temp!=NULL)){
//			if(del == temp->data){
//			    if(temp->left==NULL && temp->right==NULL){
//				    delete(temp);
//				    cout<<"\n Element deleted.";
//				    break;
//			    }else if(temp->left!=NULL && temp->right==NULL){
//				    temp2 = temp;
//				    temp = temp->left;
//				    delete(temp2);
//				    cout<<"\n Element Deleted.";
//				    break;
//			    }else if(temp->left==NULL && temp->right!=NULL){
//				    temp2 = temp;
//				    temp = temp->right;
//				    delete(temp2);
//				    cout<<"\n Element Deleted.";
//				    break;
//			    }else if(temp->left!=NULL && temp->right!=NULL){
//				
//			    }
//		    }else if(del < temp->data){
//			    if(temp->left != NULL){
//				    temp = temp->left;
//			    }else{
//				    cout<<"  Deletion Result : "<<del<<" not found.";
//			        break;
//			    }
//		    }else if(del > temp->data){
//			    if(temp->right != NULL){
//				    temp = temp->right;
//			    }else{
//				    cout<<"  Deletion Result : "<<del<<" not found.";
//			        break;
//			    }	
//		    }
            if(del < temp->data){
            	parent = temp;
            	temp = temp->left;
			}else{
				parent = temp;
				temp = temp->right;
			}	
		}
		if(temp == NULL){
			cout<<"\n Deletion Result :"<<del<<" not found.";
			return;
		}
		if(temp->left == NULL){
			temp2 = temp->right;
		}else if(temp->right == NULL){
			temp2 = temp->left;
		}else{
			child = temp;
			temp2 = temp->right;
			leaf = temp2->left;
			while(leaf != NULL){
				child = temp2;
				temp2 = leaf;
				leaf = temp2->left;
			}
			if(child != temp){
				child->left = temp2->right;
				temp2->right = temp->right;
			}
			temp2->left = temp->left;
		}
		if(parent == NULL){
			root = temp2;
		}else{
			if(temp == parent->left){
			    parent->left = temp2;
		    }else{
		    	parent->right = temp2;
			}
			delete temp;
			return; 
		} 	
	}
}

main(){
	tree tr1;
	tr1.menu();	
}

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <cstdio>

using namespace std;

class Sort{
	public:
		int size;
		int *array ;
		
		Sort(int n){
			size = n;
			array = new int(size);
			for(int i=0;i<n;i++){
				array[i] = 0;
			}
		}
		
		void insert();
		void display();
		void Recursive();
		void insertionSortItirative();
		void insertionSortRecursive(int array[], int n);
};

void Sort::insert(){
	for(int x=0;x<size;x++){
		cout<<"Enter Element "<<x+1<<" : ";
		cin>>array[x];
	}
	cout<<"\n\n Initial Array : ";
	display();
}

void Sort::display(){
	for(int k =0;k<size;k++){
		cout<<array[k]<<" ";
	}
}

void Sort::Recursive(){
	insertionSortRecursive(array, size);
}

void Sort::insertionSortItirative()
{
    cout<<"\n";
	int temp;
	for(int i=0;i<size;i++){
		for(int j=0;j<i;j++){
			if(array[i] < array[j]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
		
		cout<<"\n "<<i+1<<" Iteration : ";
	    for(int k =0;k<size;k++){
		    cout<<array[k]<<" ";
	    }
	}
	cout<<"\n\n Final Array : ";
	display();
}

void Sort::insertionSortRecursive(int array[], int n)
{
    if (n <= 1)
        return;
 
    insertionSortRecursive( array, n-1 );
 
    int last = array[n-1];
    int j = n-2;
    
    while (j >= 0 && array[j] > last)
    {
        array[j+1] = array[j];
        j--;
    }
    array[j+1] = last;
    
}


int menu(){
	int ch;
	cout<<"\n 1 Insert Element ";
	cout<<"\n 2 Display ";
	cout<<"\n 3 Itirative Insertion Sort";
	cout<<"\n 4 Recursive Insertion Sort";
	cout<<"\n 5 EXIT ";
	cout<<"\n  Enter your choice : ";
	cin>>ch;
	return ch;
}

int main(){
	int n;
	cout<<"Enter the length of array : ";
	cin>>n;
	
	Sort s = Sort(n);
	int ch,st=1,j; 
	while(st==1)
    { 
        ch=menu();
        switch(ch)
        {
            case 1:
            	s.insert();
                break;
            case 2:
            	cout<<"\n\n Array : ";
            	s.display();
                break;
            case 3:
                s.insertionSortItirative();
                break;
            case 4:
            	s.insertionSortRecursive(s.array, s.size);
            	cout<<"\n\n Final Array : ";
            	s.display();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Invalid choice entered";
        }
        cout<<"\n Press 1 to continue : ";
        cin>>st;
    }
}

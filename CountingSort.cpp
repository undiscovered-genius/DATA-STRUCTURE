#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <cstdio>

using namespace std;

class Sort{
	public:
		int size;
		int *inputArray ;
		int max=0;
		int *countArray;
		int *outputArray;
		
		Sort(int n){
			size = n;
			inputArray = new int(size);
			outputArray = new int(size);
			for(int i=0;i<n;i++){
				inputArray[i] = 0;
				outputArray[i] = 0;
			}
		}
		
		void insert();
		void display(int array[],int sz);
		void iniSort();
		//int qk_prt(int a[],int p,int r);
		//void quick(int a[],int p,int r);
};

void Sort::insert(){
	for(int x=0;x<size;x++){
		cout<<"Enter Element "<<x+1<<" : ";
		cin>>inputArray[x];
		if(max < inputArray[x]){
			max = inputArray[x];
		}
	}
	
	countArray = new int(max+1);
	for(int i=0;i<=max;i++){
		countArray[i] = 0;
	}
	cout<<"\n\n Initial Array : ";
	display(inputArray,size);
	cout<<"\n Count Array : ";
	display(countArray,max+1);
}

void Sort::display(int array[],int sz){
	for(int k =0;k<sz;k++){
		cout<<array[k]<<" ";
	}
}

void Sort::iniSort(){
	int count = 0;
	int sum = 0;
	int temp = 0;
	for(int i=0;i<=max;i++){
		count=0;
		for(int j=0;j<size;j++){
			if(i==inputArray[j]){
				count = count+1;
			}
		}
		countArray[i]=count;
	}
	cout<<"\n\n Count Array (Unique Element) : ";
	display(countArray,max+1);
	
	for(int i=0;i<=max;i++){
		sum = sum + countArray[i];
		countArray[i]=sum;
	}
	cout<<"\n\n Count Array (After sum): ";
	display(countArray,max+1);
	
	for(int x=size-1;x>=0;x--){
		temp = inputArray[x];
		count = countArray[temp] - 1;
		countArray[temp] = count;
		outputArray[count] = temp;
	}
}

int menu(){
	int ch;
	cout<<"\n 1 Insert Element ";
	cout<<"\n 2 Display ";
	cout<<"\n 3 Itirative Counting Sort";
	cout<<"\n 4 Recursive Counting Sort";
	cout<<"\n 5 EXIT ";
	cout<<"\n  Enter your choice : ";
	cin>>ch;
	return ch;
}

int main(){
	int n;
	cout<<"Enter the length of array : ";
	cin>>n;
	int beg = 0;
	int end = 0;
	
	Sort s = Sort(n);
	int ch,st=1,j; 
	while(st==1){ 
        ch=menu();
        switch(ch){
            case 1:
            	s.insert();
                break;
            case 2:
            	cout<<"\n\n Array : ";
            	s.display(s.inputArray,s.size);
                break;
            case 3:
                end = n;
            	s.iniSort();
                cout<<"\n\n Final Sorted Array : ";
            	s.display(s.outputArray,s.size);
                break;
            case 4:
            	end = n;
            	//s.quick(s.array, beg, end);
                cout<<"\n\n Final Array : ";
            	s.display(s.inputArray,s.size);
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

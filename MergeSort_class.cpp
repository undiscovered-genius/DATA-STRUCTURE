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
		void mergeSort(int arr[], int n);
		void merge(int arr[], int l, int m, int r);
		void mergeSortRecursive(int arr[],int size);
		void mergeRecursive(int arr[],int arr1[],int arr2[],int l,int r);
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

void Sort::mergeRecursive(int arr[],int arr1[],int arr2[],int l,int r){
    int i=0,j=0,k=0;
    while(i<l && j<r){
        if (arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<l){
        arr[k]=arr1[i];
        k++,i++;
    }
    while(j<r){
        arr[k]=arr2[j];
        k++;j++;
    }

}
void Sort::mergeSortRecursive(int arr[],int size){
    if (size <2){
        return ;
    }
    int mid=size/2,i;
    int arr1[mid];
    int arr2[size-mid];
    for(i=0;i<size;i++){
        if (i<mid){
            arr1[i]=arr[i];
        }
        else{
            arr2[i-mid]=arr[i];
        }
    }
    mergeSortRecursive(arr1,mid);
    mergeSortRecursive(arr2,size-mid);
    mergeRecursive(arr,arr1,arr2,mid,size-mid);

}

void Sort::mergeSort(int arr[], int n)
{	//currSize = size
	//left start -> left
   int size;  
   int left; 
 
   for (size=1; size<=n-1; size = 2*size)
   {
       for (left=0; left<n-1; left += 2*size)
       {
           int mid = min(left + size - 1, n-1);
           int right = min(left + 2*size - 1, n-1);
           merge(arr, left, mid, right);
       }
   }
}
 
void Sort::merge(int arr[], int lft, int mid, int ryt){
    int i, j, k;
    int n1 = mid - lft + 1;
    int n2 =  ryt - mid;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[lft + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
 
    i = 0;
    j = 0;
    k = lft;
    while (i < n1 && j < n2){
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


int menu(){
	int ch;
	cout<<"\n 1 Insert Element ";
	cout<<"\n 2 Display ";
	cout<<"\n 3 Itirative Merge Sort";
	cout<<"\n 4 Recursive Merge Sort";
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
	while(st==1){ 
        ch=menu();
        switch(ch){
            case 1:
            	s.insert();
                break;
            case 2:
            	cout<<"\n\n Array : ";
            	s.display();
                break;
            case 3:
                s.mergeSort(s.array, s.size);
                cout<<"\n\n Final Array : ";
            	s.display();
                break;
            case 4:
            	s.mergeSortRecursive(s.array, s.size);
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

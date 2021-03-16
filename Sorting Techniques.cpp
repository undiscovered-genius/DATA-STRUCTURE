#include<stdio.h>
#include<stdlib.h>

int count;

void insertion(int a[],int n){
	int i, j, k, temp;
	int* b;
	b = (int*)malloc(n * sizeof(int));
	for(i=0;i<n;i++){
		b[i] = a[i];
	}
	for(i=0;i<n;i++){//total n pass
		for(j=i;j>0;j--){
			if(b[j]>b[j-1]){
			}else{
				temp = b[j];
				b[j] = b[j-1];
				b[j-1] = temp;
			}
		}
		printf("\n Pass %d : ",i+1);
	    for(k=0;k<n;k++){
		    printf(" %d ",b[k]);
	    }	
	}
	printf("\n Sorted Array : ");
	for(i=0;i<n;i++){
		printf(" %d ",b[i]);
	}
}

void section(int a[],int n){
	int i, j, k, min, temp;
	int* c;
	c = (int*)malloc(n * sizeof(int));
	for(i=0;i<n;i++){
		c[i] = a[i];
	}
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(c[min]>c[j]){
				min = j;
			}
		}
		temp = c[i];
		c[i] = c[min];
		c[min] = temp;
		printf("\n Pass %d : ",i+1);
	    for(k=0;k<n;k++){
		    printf(" %d ",c[k]);
	    }
	}
	printf("\n Sorted Array : ");
	for(i=0;i<n;i++){
		printf(" %d ",c[i]);
	}
}

void bubble(int a[],int n){
	int i, j, k, temp;
	int* d;
	d = (int*)malloc(n * sizeof(int));
	for(i=0;i<n;i++){
		d[i] = a[i];
	}
	for(i=0;i<n-1;i++){  //total 3 pass
		for(j=0;j<n-(i+1);j++){
			if(d[j]>d[j+1]){  //compare
				temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
		printf("\n Pass %d : ",i+1);
	    for(k=0;k<n;k++){
		    printf(" %d ",d[k]);
	    }	
	}
	printf("\n Sorted Array : ");
	for(i=0;i<n;i++){
		printf(" %d ",d[i]);
	}
}

int qk_prt(int a[],int p,int r){
	int x, i, j, temp;
	x = a[r];
	i = p-1;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i = i+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	
	return (i+1);
}

void quick(int a[],int p,int r){
	int q,i;
	
	
	if(p < r){
		q = qk_prt(a,p,r);
		quick(a,p,q-1);
		quick(a,q+1,r);
		printf("\n pass : ");
		for(i=0;i<count;i++){
			printf(" %d ",a[i]);
		}
	}
}

void merge(int arr[],int arr1[],int arr2[],int l,int r){
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
void merge_sort(int arr[],int size){
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
    merge_sort(arr1,mid);
    merge_sort(arr2,size-mid);
    merge(arr,arr1,arr2,mid,size-mid);

}

void display(int c[], int n){
	int i;
	printf("\n Sorted Array : ");
	for(i=0;i<n;i++){
		printf(" %d ",c[i]);
	}
}

int menu(){
	int ch;
	printf("\n 1 Insertion Sort");
	printf("\n 2 Section Sort");
	printf("\n 3 Bubble Sort ");
	printf("\n 4 Merge Sort ");
	printf("\n 5 Quick Sort ");
	printf("\n 6 EXIT ");
	printf("\n  Enter your choice : ");
	scanf("%d",&ch);
	return ch;
}

int main(){
	int* a;
	int i,ch,st=1,j;  //count,
	int end = 0, beg = 0;
	
	printf("\n Enter number of elements: ");
	scanf("%d",&count); 
  
    // Dynamic memory 
    a = (int*)malloc(count * sizeof(int));
	
	for(i=0;i<count;i++){
		printf(" Enter Element %d : ",i+1);
		scanf("%d",&a[i]);
	}
    
    while(st==1)
    { 
        ch=menu();
        switch(ch)
        {
            case 1:
            	insertion(a, count);
                break;
            case 2:
            	section(a, count);
                break;
            case 3:
            	bubble(a, count);
                break;
            case 4:
            	merge_sort(a,count);
            	display(a, count);
                break;
			case 5:
				end = count;
            	quick(a, beg, end);
            	display(a, count);
                break;	    
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice entered");

        }
        printf("\n Press 1 to continue : ");
        fflush(stdin);
        scanf("%d",&st);

    }
}

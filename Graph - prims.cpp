#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cstring> 

using namespace std;


class listgraph;

class graphnode{
	public:
	int vertex;
	graphnode *next;
	
	graphnode(int n){
		vertex = n;
		next = NULL;
	}
};

class listgraph{
	int n;
	graphnode *list[10];
	int cost[10][10];
	int visited[11];

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
				for(int i=0; i<n; i++){
					cost[j][i] = 0;
				}
			}
		}
		void create();
		void display();
		void prims(int  graph[][10]);
		void menu();
		friend class graphnode;
		friend class stack;
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
				prims(cost);
				break;
			default:
				cout<<"\n Invalid Choice!";
		}
		cout<<"\n   Press 1 to Continue : ";
		cin>>st;
	}
}

void listgraph::create(){
	int i, j, c;
	graphnode *temp, *newnode;
	char ans;
	for(i=0; i<n;i++){
		for(j=0; j<n; j++){
			if(i != j){
				cout<<"\n Edge between vertex "<<i+1<<" & "<<j+1<<" (y/n) : ";
		        cin>>ans;
		        if(ans == 'y' || ans == 'Y'){
		        	if(cost[i][j] == 0){
		        		cout<<"\n Cost : ";
		        	    cin>>c;
		        	    cost[i][j] = c;
		        	    cost[j][i] = c;
					}
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
	cout<<"\n Cost Matrix \n";
	for(i=0;i<n;i++){
		for(int k=0;k<n;k++){
			cout<<" \t"<<cost[i][k];
		}
		cout<<"\n";
	}
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

void listgraph::prims(int G[10][10]){
	int no_edge;  // number of edge
    int total_cost = 0;
  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[n];

  // set selected false initially
//  bool selected[];
  for(int z=0;z<n;z++){
  	selected[z] = 0;
  }
//  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = 1;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "\tEdge"<< " : "<< "Weight";
  cout << endl;
  while (no_edge < n - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = 100;
    x = 0;
    y = 0;

    for (int i = 0; i < n; i++) {
      if (selected[i]) {
        for (int j = 0; j < n; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout <<"\t"<< x+1 << " - " << y+1 << " :  " << G[x][y];
    cout << endl;
    total_cost += G[x][y];
    selected[y] = 1;
    no_edge++;
    }
    cout<<"\n Total Cost of Spanning : "<<total_cost;	
}

main(){
	int v;
	cout<<"\n Enter Number of Vertex : ";
	cin>>v;
	listgraph tr1(v);
	tr1.menu();
}

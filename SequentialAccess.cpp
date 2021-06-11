#include<iostream>
using namespace std;

class Sequen
{
	public:
	  int prn;
	  char name[20];
}s;
void display(FILE *fp)
{
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp))
	{
		cout<<s.prn<<"  "<<s.name;
		cout<<" \n";
	}
}
int search(FILE *fp,int prn_key)
{
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp))
	{
		if(s.prn == prn_key){ return 1; }	
	}
	return 0;
}
void read(FILE *fp,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the Info for Student "<<i+1<<"|";
		cout<<"\n PRN : ";
		cin>>s.prn;
		cout<<"\nName : ";
		cin>>s.name;
		fwrite(&s,sizeof(s),1,fp);
	}
}

int main()
{
    int i,n,prn_key,opn;
	FILE *fp;
	char file[20];
	cout<<"\n-----------Sequential------------\n\nEnter a File Name- ";
	cin>>file;
	do
	{
		cout<<"\n---------------MENU------------------\n1)Enter Data\n2)Print All\n3)Search By prn\n4)exit\nEnter Your Choice : ";
		cin>>opn;
		switch(opn)
		{
			case 1:
				cout<<"How many records? - ";
	            cin>>n;
	            fp=fopen(file,"w");
	            read(fp,n);
	            fclose(fp);
				break;
			case 2:
				fp = fopen(file,"r");
				cout<<"\n\tSTUDENT RECORDS \n";
				display(fp);
				cout<<"\n----------------------\n";
				fclose(fp);
				break;
			case 3:
				fp = fopen(file,"r");
				cout<<"\nEnter the PRN to Search : ";
				cin>>prn_key;
				if(search(fp,prn_key))
				{
					cout<<"\n----RECORD FOUND----\n\n";
					cout<<s.prn<<" "<<s.name;
		            cout<<" \n";
				}
				else
				{
					cout<<"PRN not found!"<<prn_key;
			    }
			    fclose(fp);
			    break;
			case 4:
				opn=0;
				break;
			default:
				cout<<"Invalid Operation!";
				break;
		}
			
	}while(opn!=0);
	fclose(fp);
	return 0;
}

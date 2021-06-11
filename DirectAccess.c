#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int key;
}file_record;

void create_index(long index[], int key, long relative_add){
    index[key]=relative_add;
}

void write_rec(FILE *fptr, file_record rec){
    fwrite(&rec,sizeof(rec),1,fptr);
}

int main() {
    
    long relative_add=0;
    long index[20]; 
    int key,num,choice;
    file_record f_rec;
    
    FILE *rec_file=NULL,*index_file=NULL;
    int i;
   
    for(i=0;i<20;i++){
        index[i]=-1;
    }
    
    rec_file=fopen("lab9_2.txt","w");
    if(rec_file==NULL){
        printf("Error!\n");
        exit(0);
    }
    
    printf("Enter number of records: ");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("\nEnter Name: ");
        scanf("%s",f_rec.name);
        printf("Enter key: ");
        scanf("%d",&f_rec.key);
        
        while(index[f_rec.key]!=(-1)){
            printf(" Record already exists with this key value.\n Please enter another record.\n");
            printf(" Name :");
            scanf("%s",f_rec.name);
            printf(" Key :");
            scanf("%d",&f_rec.key);
        }
        create_index(index, f_rec.key, relative_add);
        write_rec(rec_file, f_rec);
        relative_add=ftell(rec_file);
       
    }
    
    index_file=fopen("lab9_2_File.txt","w");
    if(index_file==NULL){
        printf("Error!!\n");
        exit(1);
    }
    fwrite(index, sizeof(index), 1, index_file);
    fclose(rec_file);
    fclose(index_file);
    
    
    index_file=fopen("lab9_2_File.txt","r");
    if(index_file==NULL){
        printf("Error in opening file.\n");
        exit(3);
    }
    fread(index, sizeof(index), 1, index_file); 
    
    rec_file=fopen("lab9_2.txt","r");
    if(rec_file==NULL){
        printf("Error in opening file.\n");
        exit(3);
    }
    do{
        printf("----MENU----\n");
        printf("1: Print all records.\n");
        printf("2: Retrieve a particular record.\n");
        printf("   Enter your Choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("\nThe contents of File: \n");
                while((fread(&f_rec,sizeof(f_rec),1,rec_file))!=0){
                    printf("%s \t %d \n",f_rec.name,f_rec.key);
                }
                break;
            case 2:
                printf("\nEnter the key of the record to be retrieved: ");
                scanf("%d",&key);
                relative_add=index[key];
                
               
                if((fseek(rec_file,relative_add,SEEK_SET))!=0){
                    printf("\nRecord Not Found!\n");
                }else{
                	fread(&f_rec, sizeof(f_rec), 1, rec_file);
                    printf("\nThe data of the retrieved record is: %s ",f_rec.name);
				}
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("\nPress 1 to Continue : ");
        scanf("%d",&num);
    }while(num==1);
    
    fclose(index_file);
    fclose(rec_file);
    
    return 0;
}

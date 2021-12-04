#include<stdio.h>
#include<stdlib.h>
typedef struct library
{
	int bookid;
	char bookname[100];
	char authorname[100];
	char booktype[100];
	int rack;
}library;
void add(library*,int);
void display(library*,int);
void search(library*,int);
void edit(library*,int);
void destroy(library*,int);
void main()
{
	int size;
    printf("Enter Number of books you want to store :");
    scanf("%d",&size);
    library arr[size];
	int i,choice;
	do
	{
		printf("1.Add Book Details\n2.Display Book Details\n3.Search Book\n4.Modify Details\n5.Delete Deatail\n6.Exit");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add(arr,size);
				break;
			case 2:
				display(arr,size);
				break;
			case 3:
				search(arr,size);
				break;
			case 4:
				edit(arr,size);
				break;
			case 5:
				destroy(arr,size);
				break;
			case 6:
				exit(0);
			default :
				printf("Invalid Choice");
				break;
			
		}
	}while(1);
}
void add(library* ptr,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("Enter Book ID,Book Name,Author Name,Book Type and Rack Number :\n");
		scanf("%d%s%s%s%d",&ptr[i].bookid,&ptr[i].bookname,&ptr[i].authorname,&ptr[i].booktype,&ptr[i].rack);
	}
}
void display(library* ptr,int x)
{
	int i;
	printf("Entered information is :\n");
	for(i=0;i<x;i++)
	{
		printf("Book ID = %d",ptr[i].bookid);
		printf("\t Book Name = %s",&ptr[i].bookname);
		printf("\t Author Name = %s",&ptr[i].authorname);
		printf("\t Book Type = %s",&ptr[i].booktype);
		printf("\t Rack Number = %d\n",ptr[i].rack);
	}
	
}
void search(library* ptr,int x)
{
	int select;
	printf("You want to search by :\n");
	printf("1.Book Id\n2.Book Name\n3.Author Name\n4.Book Type\n5.Rack number\n");
	printf("Enter your choice :\n");
	scanf("%d",&select);
	if(select==1)
	{
		int i,found=0;
	    int id;
	    printf("Enter book id you want to search :");
	    scanf("%d",&id);
	    for(i=0;i<x;i++)
	    {
		if(ptr[i].bookid==id)
		{
			found=1;
			printf("\nThe book id of a book you searched is available in Library,Here are details of the book\n");
			printf("Book ID = %d",ptr[i].bookid);
		    printf("\t Book Name = %s",&ptr[i].bookname);
		    printf("\t Author Name = %s",&ptr[i].authorname);
		    printf("\t Book Type = %s",&ptr[i].booktype);
		    printf("\t Rack Number = %d\n",ptr[i].rack);
		}
	    }
	    if(found==0)
	    {
		printf("Sorry,The book id of book you searched is not available in Library");
	    }
	}
	else if(select==2)
	{
		int i,found=0;
	    char find[20];
	    printf("Enter book name you want to search :");
	    scanf("%s",&find);
	    for(i=0;i<x;i++)
	    {
		if(strcmp(find,ptr[i].bookname)==0)
		{
			found=1;
			printf("\nThe book you searched is available in Library,Here are details of the book\n");
			printf("Book ID = %d",ptr[i].bookid);
		    printf("\t Book Name = %s",&ptr[i].bookname);
		    printf("\t Author Name = %s",&ptr[i].authorname);
		    printf("\t Book Type = %s",&ptr[i].booktype);
		    printf("\t Rack Number = %d\n",ptr[i].rack);
		}
	    }
	    if(found==0)
	    {
		printf("Sorry,The book you searched is not available in Library");
	    }
	}
	else if(select==3)
	{
		int i,found=0;
	    char find[20];
	    printf("Enter author name you want to search :");
	    scanf("%s",&find);
	    for(i=0;i<x;i++)
	    {
		if(strcmp(find,ptr[i].authorname)==0)
		{
			found=1;
			printf("\nThe books of this author are available in Library,Here are details of the book\n");
			printf("Book ID = %d",ptr[i].bookid);
		    printf("\t Book Name = %s",&ptr[i].bookname);
		    printf("\t Author Name = %s",&ptr[i].authorname);
		    printf("\t Book Type = %s",&ptr[i].booktype);
		    printf("\t Rack Number = %d\n",ptr[i].rack);
		}
	    }
	    if(found==0)
	    {
		printf("Sorry,The books of this author are not available in Library");
	    }
	}
	else if(select==4)
	{
		int i,found=0;
	    char find[20];
	    printf("Enter book type you want to search :");
	    scanf("%s",&find);
	    for(i=0;i<x;i++)
	    {
		if(strcmp(find,ptr[i].booktype)==0)
		{
			found=1;
			printf("\nThe books under this type are available in Library,Here are details of the book\n");
			printf("Book ID = %d",ptr[i].bookid);
		    printf("\t Book Name = %s",&ptr[i].bookname);
		    printf("\t Author Name = %s",&ptr[i].authorname);
		    printf("\t Book Type = %s",&ptr[i].booktype);
		    printf("\t Rack Number = %d\n",ptr[i].rack);
		}
	    }
	    if(found==0)
	    {
		printf("Sorry,The books under this type are not available in Library");
	    }
	}
	else if(select==5)
	{
		int i,found=0;
	    int num;
	    printf("Enter the rack number :");
	    scanf("%d",&num);
	    for(i=0;i<x;i++)
	    {
		if(ptr[i].rack==num)
		{
			found=1;
			printf("\nThe books available on this rack are :\n");
			printf("Book ID = %d",ptr[i].bookid);
		    printf("\t Book Name = %s",&ptr[i].bookname);
		    printf("\t Author Name = %s",&ptr[i].authorname);
		    printf("\t Book Type = %s",&ptr[i].booktype);
		    printf("\t Rack Number = %d\n",ptr[i].rack);
		}
	    }
	    if(found==0)
	    {
		printf("Sorry,the rack number you entered is not available in Library");
	    }
	}
	else
	{
		printf("Invalid choice");
	}
}
void edit(library* ptr,int x)
{
	int id,i=0;
	printf("Enter a book id of the book you want to modify:");
	scanf("%d",&id);
	while(id!=ptr[i].bookid)
	{
		i++;
	}
	printf("Enter New Book ID,Book Name,Author Name,Book Type and Rack Number :");
	scanf("%d%s%s%s%d",&ptr[i].bookid,&ptr[i].bookname,&ptr[i].authorname,&ptr[i].booktype,&ptr[i].rack);
	printf("Successfully Modified!!\n");
}
void destroy(library* ptr,int x)
{
	int id,i,j,found=0;
	printf("Enter a book id of the book you want to delete:");
	scanf("%d",&id);
	for(i=0;i<x;i++)
	{
		if(ptr[i].bookid==id)
		{
			found=1;
			for(j=i;j<x;j++)
			{
				ptr[j]=ptr[j+1];
			}
			printf("Record deleted successfully!!!\n");
		}
	}
	if(found==0)
	{
		printf("Record not found");
	}
	
}

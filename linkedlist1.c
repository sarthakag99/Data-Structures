#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char alphabet;
	struct node *next;
}node;

node* creatlist(node *other,int n)
{
	for(int i=0;i<n;i++)
	{
		scanf(" %c",&other->alphabet);
		other->next = (node*) malloc(sizeof(node));
		other = other->next;
	}
	printf("\n");
	return other;
}

void printll(node *print)
{
	while(print!=NULL)
	{
		printf("%c ",print->alphabet);
		print = print->next;
	}
	printf("\n");
}

node* insertatbeginning(node *newnode,node *start)
{
	printf("Enter data for adding in beginning: \n");
	scanf(" %c",&newnode->alphabet);
	newnode->next = start;
	start = newnode;
return start;
}

void insertinbetween(node *extra,int pos)
{
	for(int i=1;i<pos-1;i++)
	{
		extra=extra->next;
	}
	node *newnode = (node*) malloc(sizeof(node));
	scanf(" %c",&newnode->alphabet);
	newnode->next = extra->next;
	extra->next = newnode;
}

void delete(node *head)
{
	char ch;
	node *prev = (node*) malloc(sizeof(node));
	printf("enter key to delete:");
	scanf(" %c",&ch);
	prev=head;
	while(head!=NULL)
	{
		
		if(head->alphabet == ch)
		{
			prev->next=head->next;
			break;
		}
		prev=head;
		head=head->next;
	}
}

int main()
{
	int n;
	printf("Enter number how many alphabets you want to enter: \n");
	scanf("%d",&n);
	node *start = (node*) malloc(sizeof(node));
	node *other = (node*) malloc(sizeof(node));
	//start = NULL;
	other = start;
	other = creatlist(other,n);
	
	printll(start);
	
	//adding in beginning
	node *newnode = (node*) malloc(sizeof(node));
	start = insertatbeginning(newnode,start);
	
	printll(start);
	
	//adding at nth position
	node *extra = (node*) malloc(sizeof(node));
	extra = start;
	printf("\nTpye position at which you want to add new alphabet: ");
	int position;
	scanf("%d",&position);
	insertinbetween(extra,position);
	
	printll(start);
	
	//delete the search key
	node *del = (node*) malloc(sizeof(node));
	del = start;
	delete(del);
	
	printll(start);
	
return 0;
}

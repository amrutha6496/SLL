#include<stdio.h>
#include<stdlib.h>
struct sll//self referenal struct
{
	int data;
	struct sll *next;
};
typedef struct sll node;//name struct sll changed node
node* first=NULL,*last=NULL;
void create(int ele)
{
	node*new=(node*)malloc(sizeof(node));
	if(first == NULL)
	{
		new->data=ele;
		new->next=NULL;
		first=new;
		last=new;
	}
	else
	{
		new->data=ele;
		new->next=NULL;	
		last->next=new;
		last=new;
	}
}
void display()
{
	node*temp=first;
	while(temp != NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void create_front(int ele)
{
	node*new=(node*)malloc(sizeof(node));
	new->data=ele;
	new->next=first;
	first=new;
}
void create_last(int ele)
{
	node*new=(node*)malloc(sizeof(node));
	new->data=ele;
	new->next=NULL;
	last->next=new;
	last=new;
}
void create_middle(int ele)
{
	int key;
	printf("enter a key\n");
	scanf("%d",&key);
	node*temp=first,*temp1;
	while(temp->data != key)
	{
		temp1=temp;
		temp=temp->next;
	}
	node*new=(node*)malloc(sizeof(node));
	new->data=ele;
	new->next=temp;
	temp1->next=new;
}
void delete_front()
{
	node*temp=first;
	first=temp->next;
	free(temp);
}
void delete_last()
{
	node*temp=first,*temp1;
	while(temp != last)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	last=temp1;
	free(temp);
}
void delete_middle()
{
	int key;
	printf("enter key for delete\n");
	scanf("%d",&key);
	node*temp=first,*temp1;
	while(temp->data != key)
	{
		temp1=temp;
		temp=temp->next;	
	}
	temp1->next=temp->next;
	free(temp);
}
int main()
{
	create(10);
	create(20);
	create(30);
	create(40);
	display();
	create_front(5);
	create_last(45);
	printf("after front and last creation\n");
	display();
	create_middle(25);
	printf("after middle node creation\n");
	display();
	delete_front();
	delete_last();
	printf("after delete\n");
	display();
	delete_middle();
	printf("after delete_middle\n");
	display();
}

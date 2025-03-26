#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node  *next;
};
struct node* createnode(int data) //function  to return a node
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insertatbegining(struct node**head,int data)
{
    struct node* newnode=createnode(data);
    newnode->next=*head;
    *head=newnode;
}
void insertatend(struct node** head,int data)
{
     struct node* newnode=createnode(data);
    if(*head==NULL)
    {
         *head==newnode;
         return;
         
    }
   
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
int main()
{
    return 0;
}
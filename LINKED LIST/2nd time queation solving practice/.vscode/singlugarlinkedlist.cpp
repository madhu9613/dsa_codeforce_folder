#include<iostream.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
}

void insertathead(node *&head,int d)
{
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

void insertatend(node* &head,int d)
{
    node* newnode=new node(d);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insertatposition(node* &head, int p,int d)
{
    if(p==1)
    {
        //its a case when i need to insert in head 
        insertathead(head,d);
        return;
    }
}





int main()
{

    return 0;
}
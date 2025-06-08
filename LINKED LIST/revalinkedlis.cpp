#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertatend(node* &tail,node* &head, int d)
{
    if (tail == NULL)
    {
        node *newnode = new node(d);
      head= tail = newnode;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        tail = temp;
    }
}


void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


node* revlinkedlist(node* head) //its return a node:: 
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* prev=NULL;
    node* current= head;
    node* forward=NULL;
    while(current!=nullptr)
    {
        forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;
    }
    return prev;

}
int main()
{
    int n;
    cout << "enter element in linked list:>\n" << endl;
    cin >> n;
node* head=NULL;
node* tail=NULL;
int e;
for(int i=0;i<n;i++)
{
    cin>>e;
    insertatend(tail,head,e);
}
cout<<"original list is :>\n";
print(head);
head=revlinkedlist(head);
cout<<"printing in reverse order:>\n";
print(head);

    return 0;
}
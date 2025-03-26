#include <iostream>
#include <sstream>
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
void insertatend(node *&tail, node *&head, int d)
{
    if (tail == NULL)
    {
        node *newnode = new node(d);
        head = tail = newnode;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        tail = temp;
    }
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int getlength(node *head)
{
    node *temp = head;
    int c = 0;
    while (temp != 0)
    {
        temp = temp->next;
        c++;
    }
    return c;
}
node* getmidelement(node* head)
{

if(head==nullptr || head->next==nullptr)
{
    return head;
}
if(head->next->next=nullptr)
{
    return head->next;
}
node* slow=head;
node* fast=head->next;
while(fast!=nullptr)
{
    fast=fast->next;
    if(fast!=nullptr)
    {
        fast=fast->next;
    }
    slow=slow->next;
}
return slow;
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    while (ss >> num)
    {
        insertatend(tail, head, num);
    }
    print(head);
   
    node* ans=getmidelement(head);
    cout<<ans->data;
    return 0;
}
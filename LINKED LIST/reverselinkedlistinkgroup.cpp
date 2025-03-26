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


node* krevgroup(node* &head,int k)
{
 if(head==NULL || head->next==NULL)
 {
    return head;
 }
 node* forward=NULL;
 node* current=head;
 node* prev=NULL;
 int count =0;
 while(current!=NULL && count<k)
 {
    forward=current->next;
    current->next=prev;
    prev=current;
    current=forward;
    count++;
 }
//step 2 :recursion ::
if(forward!=NULL)
{
    head->next=krevgroup(forward,k);
}
//return the head::
return prev;
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
   node* krev=krevgroup(head,2);
   print(krev);
  
    return 0;
}
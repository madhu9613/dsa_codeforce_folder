#include <iostream>
#include<map>
using namespace std;

class node
{
public:
  int data;
  node *next;

  // Constructor
  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Memory is free for the node with data " << value << endl;
  }
};

void insertathead(node *&head, int d)
{
  node *temp = new node(d);
  temp->next = head;
  head = temp;
}

void insertattail(node *&tail, int d)
{
  node *temp = new node(d);
  tail->next = temp;
  tail = temp;
}

void insertatposition(node *&tail, node *&head, int p, int d)
{
  if (p == 1) 
  {
    insertathead(head, d);
    return;
  }

  node *temp = head;
  int count = 1;

  // Traverse to the (p-1)th position
  while (count < p - 1 && temp->next != NULL)
  {
    temp = temp->next;
    count++;
  }

  // Inserting at tail
  if (temp->next == NULL)
  {
    insertattail(tail, d);
    return;
  }

  node *nodetoinsert = new node(d);
  nodetoinsert->next = temp->next;
  temp->next = nodetoinsert;
}

void deletenode(node *&head, int p)
{
  if (p == 1)
  {
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    node *curr = head;
    node *prev = NULL;
    int c = 1;

    while (c < p)
    {
      prev = curr;
      curr = curr->next;
      c++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}
//detecting loop in linked list>>
bool detectloop(node* head)
{
    if(head==NULL)
    {
        return false;
    }
    map<node*,bool> visited;
    node* temp=head;
    while(temp!=NULL)
    {//cycle present
        if(visited[temp]==true)
        {
          cout<<"present at:>"<<temp->data<<endl;
           return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}


void print(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  node *node1 = new node(10);

  node *head = node1;
  node *tail = node1;

  insertathead(head, 1);
  insertathead(head, 2);
  insertattail(tail, 4);
  insertathead(head, 3);
  insertatposition(tail, head, 5, 100);
  insertatposition(tail, head, 4, 10);
  insertatposition(tail, head, 1, 0);
  insertatposition(tail, head, 9, 69); // Tail should be updated
  insertattail(tail, 79);
   tail->next=head->next;
  if(detectloop(head))
  {
    cout<<" LOOP present\n";
  }
  else{
    cout<<"LOOP NOT PRESENT\n";
  }
  // print(head);

  deletenode(head, 1);
  deletenode(head, 4);
  if(detectloop(head))
  {
    cout<<" LOOP present\n";
  }
  else{
    cout<<"LOOP NOT PRESENT\n";
  }
  // print(head);

  return 0;
}

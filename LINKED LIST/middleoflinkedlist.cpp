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
void getelement(node *head, int mid)
{
    node *temp = head;
    int pos = 1;
    while (pos < mid)
    {
        temp = temp->next;
        pos++;
    }
    cout<<temp->data;
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
    int mid=getlength(head)/2 + 1; // i want to acces this {{}}
     getelement(head,mid);
    return 0;
}
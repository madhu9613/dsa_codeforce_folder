#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {

        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for the node with " << val << endl;
    }
};
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
int getlength(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;

}
void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertatposition(node *&head, node *&tail, int p, int d)
{
    // insetatstart
    if (p == 1)
    {
        insertathead(head, d);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < p - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }

    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;

    nodetoinsert->prev = temp;
    temp->next = nodetoinsert;
}
void deletenode(node *&head, node *&tail, int p)
{
    if (p == 1)
    {
        node *temp = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;
        return;
    }

    node *curr = head;
    node *prev = NULL;
    int c = 1;

    while (c < p && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        c++;
    }

    if (curr != NULL)
    {
        if (curr->next != NULL)
        {
            curr->next->prev = prev;
        }
        else
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    int length = getlength(head);
    cout << length << endl;
    print(head);
    insertathead(head, 9);
    length = getlength(head);
    cout << length << endl;
    print(head);
    insertattail(tail, 8);
    length = getlength(head);
    cout << length << endl;
    print(head);
    insertatposition(head, tail, 3, 0);

    insertatposition(head, tail, 2, 90);
    print(head);
    deletenode(head, tail, 2);
    deletenode(head, tail, 1);
    print(head);
    return 0;
}

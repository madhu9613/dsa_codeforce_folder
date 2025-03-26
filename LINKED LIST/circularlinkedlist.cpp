#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
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
        cout << "Memory is freed for node with value " << val << endl;
    }
};

void insertnode(node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        node *node1 = new node(d);
        tail = node1;
        tail->next = tail;
    }
    else
    {

        node *curr = tail;
        do
        {
            if (curr->data == element)
            {

                node *temp = new node(d);
                temp->next = curr->next;
                curr->next = temp;

                if (curr == tail)
                {
                    tail = temp;
                }
                return;
            }
            curr = curr->next;
        } while (curr != tail); // Loop until we come back to the tail

        cout << "Element " << element << " not found in the list." << endl;
    }
}

void print(node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    node *temp = tail;
    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);

    cout << "repeat::" << endl;
}

bool iscircular(node *head)
{
    if (head == NULL)

    {
        return false;
    }
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// using map
bool detectloop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    { // cycle present
        if (visited[temp] == true)
        {
            return temp->data;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    node *tail = NULL;

    insertnode(tail, 1, 4);
    insertnode(tail, 4, 5);
    insertnode(tail, 5, 6);
    insertnode(tail, 11, 6);
    print(tail);
    if (iscircular(tail))
    {
        cout << "LINKED LIST IS CIRCULAR IN NATURE\n"
             << endl;
    }
    else
    {
        cout << "LINKED LIST IS NOT CIRCULAR\n"
             << endl;
    }
    if (detectloop(tail))
    {
        cout << "LOOP IS PRESENT\n";
    }
    else
    {
        cout << "lOOP IS NOT PRESENT\n";
    }

    return 0;
}

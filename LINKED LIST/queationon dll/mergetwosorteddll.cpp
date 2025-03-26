
/*. Merge Two Sorted Doubly Linked Lists
Write a function to merge two sorted doubly linked lists into a single sorted doubly linked list.*/
#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
// function to take input for linked list in sorted order
node *createdll()
{
    node *head = NULL;
    node *tail = NULL;
    string input;

    while (true)
    {
        cin >> input;
        if (input == ".")
            break;

        try
        {
            int value = stoi(input); // Convert string to integer
            node *newnode = new node(value);
            if (!head)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                // if current node is less than head means need to update head::
                if (value <= head->data)
                {
                    // update head::
                    newnode->next = head;
                    head->prev = newnode;
                    head = newnode;
                }
                else
                {
                    node *current = head;
                    // visit to the correct place in the existing linked list::
                    while (current->next && current->next->data < value)
                    {
                        current = current->next;
                    }
                    newnode->next = current->next;
                    if (current->next)
                    {
                        current->next->prev = newnode;
                    }

                    current->next = newnode;
                    newnode->prev = current;
                }
            }
        }
        catch (invalid_argument &e)
        {
            cout << "Invalid input. Please enter numbers or '.' to stop." << endl;
        }
    }
    return head;
}

node *mergetwosorted(node *head1, node *head2)
{
    node *head = NULL;
    node *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->next;
            }
            else
            {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->next;
            }
            else
            {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->next = head1;
        tail = head1;
        head1 = head1->next;
    }
    while(head2!=NULL)
    {
     tail->next = head2;
     tail = head2;
     head2 = head2->next;   
    }
    return head;
}
void print(node* head)
{
    if(head==NULL)
    {

        cout<<"empty linked list"<<endl;
        return ;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        if(temp!=NULL)
        {
            cout<<"->";
        }
    }cout<<endl;
}

int main()
{
    cout<<"enter data for linkedlist 1"<<endl;
    node* head1=createdll();
    
    cout<<"enter data for linkedlist 2"<<endl;
    node* head2=createdll();
node* head=mergetwosorted(head1,head2);
cout<<"printing this mergeed list"<<endl;
print(head);

    return 0;
}

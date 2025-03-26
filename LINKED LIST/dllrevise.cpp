#include <iostream>
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
// function to make a dll from a steam of numbers
node *createdll()
{
    node* head=NULL;
    node* tail=NULL;
      string input;

    while (true) {
        cin >> input;
        if (input == ".") break;

        try {
            int value = stoi(input); // Convert string to integer
            node* newNode = new node(value);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } catch (invalid_argument& e) {
            cout << "Invalid input. Please enter numbers or '.' to stop." << endl;
        }
    }
    return head;
}

 void printll(node* head)
 {
    if(head==NULL)
    {cout<<"empty";
        return;
    }
    cout<<"printing in  given order:"<<endl;
    node* temp=head;
    while(temp!=NULL)

    {
        cout<<temp->data<<" ";
        if(temp->next!=NULL)
        {
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<<endl;
    cout<<"printing in reverse order:"<<endl;
    temp=head;
    while(temp->next!=NULL)

    {
        temp=temp->next;
    }
    //now print
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->prev!=NULL)
        {
            cout<<"->";
        }
        temp=temp->prev;
    }cout<<endl;

 }   
int main()
{
    node* head=createdll();
    printll(head);
}
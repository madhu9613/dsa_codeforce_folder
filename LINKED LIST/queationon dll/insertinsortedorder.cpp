
/*2. Insert in Sorted Order
Given a sorted doubly linked list, write a function 
to insert a new node in its correct position while maintaining the sorted order.
*/
#include<iostream>
#include<string>
using namespace std;
class node{
public:
int data;
node* prev;
node* next;
node(int data)
{
    this->data=data;
    this->prev=NULL;
    this->next=NULL;
}

};
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
            node* newnode = new node(value);
            if (!head) {
                head = newnode;
                tail = newnode;
            } else {
                //if current node is less than head means need to update head::
                if(value <=head->data)
                {
                    //update head::
                    newnode->next=head;
                    head->prev=newnode;
                    head=newnode;
                }
                else{
                    node* current=head;
                    //visit to the correct place in the existing linked list::
                    while(current->next && current->next->data< value)
                    {
                        current=current->next;
                        
                    }
                     newnode->next=current->next;
                    if(current->next)
                    {
                   current->next->prev=newnode;
                    }

                    current ->next=newnode;
                    newnode->prev=current;

                }
               
            }
        } catch (invalid_argument& e) {
            cout << "Invalid input. Please enter numbers or '.' to stop." << endl;
        }
    }
    return head;
}
//print dll
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

node* head=createdll();
print(head);
    return 0;
}
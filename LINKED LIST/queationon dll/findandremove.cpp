/*1. Find and Remove All Nodes with a Specific Value
Write a function to find and remove all nodes in a doubly linked list with a given value. 
The function should handle all edge cases, including removing the head, tail, and all nodes containing the value.
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
//create a dll:
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
//function to remove all the nodes with a spacific numbers:
void remove(node* &head,int key)
{
    if(head==NULL)
    {
        return ;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            node* nodetodelete=temp;
           if(temp==head)
           {
            
            head=temp->next;
            if(head)
             {  
                head->prev=NULL;}
           }
           else{
            if(temp->prev) //if previous is present:
            {
                temp->prev->next=temp->next;
              
            }
            if(temp->next)
            {
                temp->next->prev=temp->prev;
            }
    
            
        }
        temp=temp->next;
        delete nodetodelete;
       //  return ; if i place return here it will delete only a single occurence of the  element;;in
       //sort only one element will be delete
       

        }
        else{
            temp=temp->next;
        }

    }
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
    cout<<"current linked list is:"<<endl;
     print(head);
    int key;
    cout<<"enter key to remove:"<<endl;
    cin>>key;
    remove(head,key);
    print(head);
    return 0;
}
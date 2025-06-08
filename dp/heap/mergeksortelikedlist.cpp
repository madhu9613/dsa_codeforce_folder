#include <bits/stdc++.h>
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
    node(int data, node *next)
    {
        this->data = data;
        this->next = next;
    }
};
// ......merge sorted linked list compare based on data
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};
// ... i will get head of those linked list
node* createList(const vector<int>& nums) {
    if (nums.empty()) return NULL;
    node* head = new node(nums[0]);
    node* current = head;
    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new node(nums[i]);
        current = current->next;
    }
    return head;
}
node*  mergeksortedll(vector<node *> list, int k)
{
    priority_queue<node *, vector<node *>, compare> pq;
    // ....i will first compare the first element of those
    for (int i = 0; i < k; i++)
    {
        node *temp = list[i];
        pq.push(temp);
    }
    node *head = NULL;
    node *tail = NULL;

    while ((!pq.empty()))
    {
        node* temp=pq.top();
        pq.pop();
        /* code */
        if (head == NULL)
        {
            head=tail=temp;
            if(head->next!=NULL)
            {

                pq.push(tail->next);

            }
        }
        else{
           tail->next=temp;
           tail=temp;
           if(tail->next!=NULL)
           {
             pq.push(tail->next);
           }

        }
    }
    return head;
}

void printList(node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int k;
    cout << "Enter the number of linked lists: ";
    cin >> k;

    vector<node*> lists(k);

    // Input k sorted linked lists
    for (int i = 0; i < k; i++) {
        int n;
        cout << "Enter the size of linked list " << i + 1 << ": ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements of linked list " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }
        lists[i] = createList(nums);
    }

    // Merge the k sorted linked lists
    node* mergedList = mergeksortedll(lists, k);

    // Output the merged sorted linked list
    cout << "Merged sorted linked list: ";
    printList(mergedList);

    return 0;
}
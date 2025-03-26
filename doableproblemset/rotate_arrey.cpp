#include <iostream>
#include <vector>

using namespace std;

void store(vector<int>& vec, int n) {  
    for (int i = 0; i < n; ++i) {
        int e;
        
        cin >> e;
        vec.push_back(e);
    }
}
void rotate(vector<int> &vec ,int k)

{
    vector<int> temp(vec.size());
    for(int i=0;i<vec.size();i++)
    {
        temp[(i+k)%vec.size()]=vec[i];
    }
    vec=temp;
}
void rotateright(vector<int> &vec ,int k)

{
    vector<int> temp(vec.size());
    for(int i=0;i<vec.size();i++)
    {
        temp[(i-k)%vec.size()]=vec[i];
    }
    vec=temp;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> vec; 
    store(vec, n);
     cout << "Vector elements before rotated : ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

 cout << "Vector elements before rotated : ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
    int K;
 
    cout<<"ENTER POSITON :"<<endl;
    cin>>K;
    rotate(vec,K);
 cout << "Vector elements after rotate K pon left : "<<endl;
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;


    return 0;
}

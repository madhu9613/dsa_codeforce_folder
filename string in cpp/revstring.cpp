#include<iostream>
using namespace std;

int len(char name[])
{int count =0;
for(int i=0;name[i]!='\0';i++)
  {
    count++;

  }
  return count;
}
void reverse(char name[], int n)
{
    int s=0;
    int e=n-1;
    while(s<e)
    {
        swap(name[s],name[e]);
        s++;
        e--;
    }
}
int main()
{
    
    char name[20];
 cout<<"enter your name "<<endl;
 cin>>name;

cout<<"your name is "<<name<<endl;

int length=len(name);
cout<<"length of string is "<<length<<endl;

reverse(name,length);
cout<<"after reverse my name is "<<name<<endl;
    return 0;

}

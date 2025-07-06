//reverse array
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void reverse(vector<int>&arr)
{
    stack<int>s;
    for(int i=0;i<arr.size();i++)
    s.push(arr[i]);
    int i=0;
    while(!s.empty())
    {
        arr[i]=s.top();
        s.pop();
        i++;
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
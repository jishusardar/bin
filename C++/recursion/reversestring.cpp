//reverse a string
#include<iostream>
#include<algorithm>
using namespace std;
void reversestring(string &s,int start,int end)
{
    if(start>=end)
    return;
    swap(s[start],s[end]);
    reversestring(s,start+1,end-1);
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    reversestring(s,0,s.size()-1);
    cout<<s;
}
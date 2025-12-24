//lower case to upper case
#include<iostream>
using namespace std;
string lowertoupper(string &s,int start,int end)
{
    if(start==end)
    return s;
    if(s[start]>='a'&&s[start]<='z'){
        int num=s[start]-'a';
        char c1='A'+num;
        s[start]=c1;
    }
    return lowertoupper(s,start+1,end);
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<lowertoupper(s,0,s.size());
}
//background string compare
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool backgroundcomp(string s1,string s2)
{
    stack<char>st1;
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='#'){
            if(!st1.empty())
            st1.pop();
        }
        else
        st1.push(s1[i]);
    }
    stack<char>st2;
    for(int i=0;i<s2.size();i++){
        if(s2[i]=='#'){
            if(!st2.empty())
            st2.pop();
        }
        else
        st2.push(s2[i]);
    }
    if(st1.size()!=st2.size())
    return 0;
    while(!st1.empty()&&!st2.empty()){
        if(st1.top()!=st2.top())
        return 0;
        st1.pop(),st2.pop();
    }
    return 1;
}
int main()
{
    string s1;
    cout<<"Entre The String: ";
    cin>>s1;
    string s2;
    cout<<"Entre The String: ";
    cin>>s2;
    if(backgroundcomp(s1,s2))
    cout<<"The Strings are Same";
    else
    cout<<"The Strings Are Not Same";
}
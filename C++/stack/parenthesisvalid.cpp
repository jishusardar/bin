//valid parenthesis
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
bool validparenthesis(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        st.push(s[i]);
        else{
            if(!st.empty()){
                if(s[i]==')'&&st.top()=='(')
            st.pop();
            else if(s[i]=='}'&&st.top()=='{')
            st.pop();
            else if(s[i]==']'&&st.top()==']')
            st.pop();
            else
            return 0;
            }
            return 0;
        }
    }
    if(st.empty())
    return 1;
    return 0;
}
int main()
{
    string s;
    cout<<"Entre The String :";
    cin>>s;
    if(validparenthesis(s))
    cout<<"The Parenthsis is valid";
    else
    cout<<"The Parenthesis is not valid";
}
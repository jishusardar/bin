//minimum add to valid parenthesis
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int minimumadd(string s)
{
    int count=0;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
        st.push(s[i]);
        else{
            if(st.empty())
            count++;
            else
            st.pop();
        }
    }
    return count+st.size();

}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<"Minimum need of string: "<<minimumadd(s);
}
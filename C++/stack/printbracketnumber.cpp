//print bracket number
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> printbracket(string s)
{
    vector<int>ans;
    stack<int>st;
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            count++;
            st.push(count);
            ans.push_back(st.top());
        }
        else if(s[i]==')'){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    vector<int>arr=printbracket(s);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
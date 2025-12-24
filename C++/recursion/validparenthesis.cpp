//valid parenthesis
#include<iostream>
#include<vector>
using namespace std;
void valid_parenthesis(int n,vector<string>&ans,string &s,int left,int right)
{
    if(left+right==2*n){
        ans.push_back(s);
        return;
    }
    if(left<n){
        s.push_back('(');
        valid_parenthesis(n,ans,s,left+1,right);
        s.pop_back();
    }
    if(right<left){
        s.push_back(')');
        valid_parenthesis(n,ans,s,left,right+1);
        s.pop_back();
    }
}
vector<string> parenthesis(int n)
{
    vector<string>ans;
    string s;
    valid_parenthesis(n,ans,s,0,0);
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The No of bracket: ";
    cin>>n;
    vector<string>ans=parenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
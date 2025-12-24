//string subsequence
#include<iostream>
#include<vector>
using namespace std;
void sequence(vector<string>&ans,string str,string &temp,int i)
{
    if(i==str.size()){
        ans.push_back(temp);
        return;
    }
    sequence(ans,str,temp,i+1);
    temp.push_back(str[i]);
    sequence(ans,str,temp,i+1);
    temp.pop_back();
}
vector<string> subsequence(string str)
{
    vector<string>ans;
    string temp;
    sequence(ans,str,temp,0);
    return ans;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    vector<string>ans=subsequence(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
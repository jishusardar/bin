// N Bit Binary Number
//N Bit Binary Number Having more than equal to 1 than 0 for any prefix
#include<iostream>
#include<vector>
using namespace std;
void NBitNumber(int n,int one,int zero,string &temp,vector<string>&ans)
{
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    if(one<n){
        temp.push_back('1');
        NBitNumber(n,one+1,zero,temp,ans);
        temp.pop_back();
    }
    if(zero<one){
        temp.push_back('0');
        NBitNumber(n,one,zero+1,temp,ans);
        temp.pop_back();
    }
}
vector<string> NumbersNBit(int n)
{
    vector<string>ans;
    string temp;
    NBitNumber(n,0,0,temp,ans);
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Nbit Number: ";
    cin>>n;
    vector<string>ans=NumbersNBit(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
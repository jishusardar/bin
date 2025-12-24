#include<iostream>
#include<vector>
using namespace std;
int longestkunique(string s,int k)
{
    int start=0,end=0;
    vector<int>count(26,0);
    int diff=0;
    int len=0;
    while(start<s.size()&&end<s.size()){
        if(diff>k){
            count[s[start]-'a']--;
            if(count[s[start]-'a']==0)
            diff--;
            start++;
        }
        else{
            if(count[s[end]-'a']==0)
            diff++;
            count[s[end]-'a']++;
            end++;
        }
        if(diff==k)
        len=max(len,end-start);
    }
    return len;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    int k;
    cout<<"Entre The No of unique char's: ";
    cin>>k;
    cout<<longestkunique(s,k);
}
//longest substring without repetating characater
#include<iostream>
#include<vector>
using namespace std;
int longestsub(string s)
{
    int len=0;
    vector<int>count(26,0);
    int start=0,end=0;
    while(end<s.size()){
        while(count[s[end]-'a']){
            count[s[start]-'a']--;
            start++;
        }
        count[s[end]-'a']=1;
        len=max(len,end-start+1);
        end++;
    }
    return len;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<longestsub(s);
}
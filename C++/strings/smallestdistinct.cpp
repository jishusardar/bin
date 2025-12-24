#include<iostream>
#include<vector>
using namespace std;
int smallestdistinct(string s)
{
    int start=0,end=1;
    vector<int>count(26,0);
    for(int i=0;i<s.size();i++){
        count[s[i]-'A']++;
    }
    int diff=0;
    for(int i=0;i<26;i++){
        if(count[i]!=0)
        diff++;
    }
    for(int i=0;i<26;i++)
    count[i]=0;
    count[s[start]-'A']++;
    diff--;
    int len=s.size();
    while(end<s.size()){
        while(diff){
            if(count[s[end]-'A']==0)
            diff--;
            count[s[end]-'A']++;
            end++;
        }
        len=min(len,end-start);
        while(diff!=1){
            len=min(len,end-start);
            count[s[start]-'A']--;
            if(count[s[start]-'A']==0)
            diff++;
            start++;
        }
    }
    return len;

}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<smallestdistinct(s);
}
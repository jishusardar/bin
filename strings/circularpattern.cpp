#include<iostream>
#include<vector>
using namespace std;
void longestprefix(vector<int>&lps,string s)
{
    int pre=0,suff=1;
    while(suff<s.size()){
        if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++,suff++;
        }
        else{
            if(pre==0){
                lps[suff]=0;
                suff++;
            }
            else
            pre=lps[pre-1];
        }
    }
}
bool circularpattern(string s1,string s2)
{
    string str=s1;
    str+=s1;
    int pre=0,suff=0;
    vector<int>lps(str.size(),0);
    longestprefix(lps,str);
    while(pre<str.size()&&suff<s2.size()){
        if(str[pre]==s2[suff]){
            pre++,suff++;
        }
        else{
            if(pre==0){
                suff++;
            }
            else
            pre=lps[pre-1];
        }
    }
    if(suff==s2.size())
    return 1;
    return 0;
}
int main()
{
    string s1,s2;
    cout<<"Entre the string 1: ";
    cin>>s1;
    cout<<"Entre The String 2: ";
    cin>>s2;
    cout<<"Circular Pattern : "<<circularpattern(s1,s2);
}
//repeated string matching algorithm
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
bool repeatedstringmatch(string s1,string s2)
{
    while(s1.size()<=s2.size()){
        s1+=s1;
    }
    vector<int>lps(s1.size(),0);
    longestprefix(lps,s1);
    int pre=0,suff=0;
    while(pre<s1.size()&&suff<s2.size()){
        if(s1[pre]==s2[suff]){
            pre++,suff++;
        }
        else{
            if(pre==0)
            suff++;
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
    string s1;
    cout<<"Entre The String 1: ";
    cin>>s1;
    string s2;
    cout<<"Entre The String 2: ";
    cin>>s2;
    if(repeatedstringmatch(s1,s2))
    cout<<"The String's are Match";
    else
    cout<<"The String's are Not Match";
}
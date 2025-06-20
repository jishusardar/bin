//string matrching
#include<iostream>
#include<vector>
using namespace std;
void lps(vector<int>&arr,string s)
{
    int pre=0,suff=1;
    while(suff<s.size()){
        if(s[pre]==s[suff]){
            arr[suff]=pre+1;
            pre++,suff++;
        }
        else{
            if(pre==0){
                arr[suff]=0;
                suff++;
            }
            else{
                pre=arr[pre-1];
            }
        }
    }
}
bool stringmatching(string s1,string s2)
{
    int pre=0,suff=0;
    vector<int>lpss(s1.size(),0);
    lps(lpss,s1);
    while(pre<s1.size()&&suff<s2.size()){
        if(s1[pre]==s2[suff])
        pre++,suff++;
        else{
            if(pre==0)
            suff++;
            else
            pre=lpss[pre-1];
        }
    }
    if(suff==s2.size())
    return 1;
    return 0;
}
int main()
{
    string s1,s2;
    cout<<"Entre The String 1: ";
    cin>>s1;
    cout<<"Entre The String 2: ";
    cin>>s2;
    cout<<stringmatching(s1,s2);
}
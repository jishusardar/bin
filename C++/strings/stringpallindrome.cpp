//make an string pallindrome
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int stringpallindrome(string s)
{
    string str=s;
    str+="$";
    reverse(s.begin(),s.end());
    str+=s;
    vector<int>lps(str.size(),0);
    int pre=0,suff=1;
    while(suff<str.size()){
        if(str[pre]==str[suff]){
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
    return s.size()-lps[lps.size()-1];
}
int main()
{
    string s;
    cout<<"Entre The string: ";
    cin>>s;
    cout<<"The Minimum No o Characters Required for pallindrome is: "<<stringpallindrome(s);
}
#include<iostream>
#include<algorithm>
using namespace std;
string addstring(string s1,string s2)
{
    string ans="";
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int i=0,j=0;
    int sum;
    int carry=0;
    while(i<s1.size()&&j<s2.size()){
        sum=carry+(s1[i]-'0')+(s2[j]-'0');
        ans+=(sum%10)+'0';
        carry=sum/10;
        i++,j++;
    }
    while(i<s1.size()){
        sum=carry+(s1[i]-'0');
        ans+=(sum%10)+'0';
        carry=sum/10;
        i++;
    }
    while(j<s2.size()){
        sum=carry+(s2[j]-'0');
        ans+=(sum%10)+'0';
        carry=sum/10;
        j++;
    }
    while(carry){
        ans+=(carry%10)+'0';
        carry/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string str1;
    string str2;
    cout<<"Entre string 1: ";
    cin>>str1;
    cout<<"Entre string 2: ";
    cin>>str2;
    cout<<addstring(str1,str2);
}
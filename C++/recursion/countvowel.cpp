//count the vowels
#include<iostream>
using namespace std;
int countvowels(string s,int i)
{
    if(i==s.size())
    return 0;
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
    return 1+countvowels(s,i+1);
    return 0+countvowels(s,i+1);
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<countvowels(s,0);
}
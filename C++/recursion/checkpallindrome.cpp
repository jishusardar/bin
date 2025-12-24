//check pallindrome
#include<iostream>
using namespace std;
bool checkpallindrome(string s,int start,int end)
{
    if(start>=end)
    return 1;

    if(s[start]!=s[end])
    return 0;
    return checkpallindrome(s,start+1,end-1);
} 
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    if(checkpallindrome(s,0,s.size()-1))
    cout<<"The string is pallindrome";
    else
    cout<<"The String is not pallindrome";
}
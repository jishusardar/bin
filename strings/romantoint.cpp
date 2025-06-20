#include<iostream>
using namespace std;
int strtoint(char c)
{
    if(c=='I')
    return 1;
    else if(c=='V')
    return 5;
    else if(c=='X')
    return 10;
    else if(c=='L')
    return 50;
    else if(c=='C')
    return 100;
    else if(c=='D')
    return 500;
    else if(c=='M')
    return 1000;
    else
    return -1;
}
int romantoint(string s)
{
    int ans=0;
    for(int i=1;i<s.size();i++){
        if(strtoint(s[i-1])<strtoint(s[i]))
        ans+=-(strtoint(s[i-1]));
        else
        ans+=strtoint(s[i-1]);
    }
    ans+=strtoint(s[s.size()-1]);
    return ans;
}
int main()
{
    string num;
    cout<<"Entre The Roman No: ";
    cin>>num;
    cout<<romantoint(num);
}
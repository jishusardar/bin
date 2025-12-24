//smallest window contains 0,1,2
#include<iostream>
#include<vector>
using namespace std;
int smallestwindow(string s)
{
    int len=s.size();
    vector<int>count(3,0);
    int start=0,end=1;
    count[s[start]-'0']++;
    while(end<s.size()){
        count[s[end]-'0']++;
        while(end>start&&count[s[end]-'0']>1){
            count[s[start]-'0']--;
            start++;
        }
        end++;
        if(count[0]>0&&count[1]>0&&count[2]>0)
        len=min(len,end-start);
    }
    return len;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<smallestwindow(s);
}
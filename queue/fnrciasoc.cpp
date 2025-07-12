//first no repetating char in a stream of characters
#include<iostream>
#include<queue>
using namespace std;
string fnrciasoc(string s)
{
    string ans;
    queue<char>q;
    vector<int>count(26,0);
    for(int i=0;i<s.size();i++){
        if(count[s[i]-'a']>=1){
            count[s[i]-'a']++;
            while(count[q.front()-'a']>1)
            q.pop();
            if(q.empty())
            ans.push_back('#');
            else
            ans.push_back(q.front());
        }
        else{
            count[s[i]-'a']++;
            q.push(s[i]);
            while(!q.empty()&&count[q.front()-'a']>1)
            q.pop();
            ans.push_back(q.front());
        }
    }
    return ans;
}
int main()
{
    string s;
    cout<<"Entre The String: ";
    cin>>s;
    cout<<fnrciasoc(s);
}
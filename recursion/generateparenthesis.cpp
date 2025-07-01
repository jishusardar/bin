//generate parenthesis
#include<iostream>
#include<vector>
using namespace std;
void generate(int n,int left,int right,string temp,vector<string>&ans)
{
    if(left==right)
    {
        ans.push_back(temp);
        return;
    }
    if(left<n){
        temp.push_back('(');
        generate(n,left+1,right,temp,ans);
    }
    if(right<left){
        temp.push_back(')');
        generate(n,left,right+1,temp,ans);
    }
}
vector<string>validparenthesis(int n)
{

}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
}
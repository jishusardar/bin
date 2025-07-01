//recursion 1 to n
#include<iostream>
using namespace std;
void function(int i,int n)
{
    if(i=n+1)
    return;
    cout<<i<<" ";
    function(i+1,n);

}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    function(1,n);
}
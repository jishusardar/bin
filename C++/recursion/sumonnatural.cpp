//sum of n natural number
#include<iostream>
using namespace std;
int sumofnatural(int n)
{
    if(n==1)
    return n;
    return n+sumofnatural(n-1);
}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<sumofnatural(n);
}
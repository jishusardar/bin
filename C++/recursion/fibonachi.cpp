//fibonachi series
#include<iostream>
using namespace std;
int fibonachhi(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return fibonachhi(n-1)+fibonachhi(n-2);
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    cout<<fibonachhi(n);
}
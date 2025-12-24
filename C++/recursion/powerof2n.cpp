//power of 2^n
#include<iostream>
using namespace std;
int powerof2n(int n)
{
    if(n==1)
    return 2;
    return 2*powerof2n(n-1);
}
int main()
{
    int n;
    cout<<"Entre The power Of Two: ";
    cin>>n;
    cout<<powerof2n(n);
}
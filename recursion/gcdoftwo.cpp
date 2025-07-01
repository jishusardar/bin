//gcd of two numbers
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main()
{
    int n1,n2;
    cout<<"Entre The Numbers: ";
    cin>>n1>>n2;
    cout<<gcd(n1,n2);
}
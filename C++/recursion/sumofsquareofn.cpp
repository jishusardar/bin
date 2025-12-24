//sum of square of n numbers
#include<iostream>
using namespace std;
int sumofsquaren(int n)
{
    if(n==1)
    return 1;
    return (n*n)+sumofsquaren(n-1);
}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<sumofsquaren(n);
}
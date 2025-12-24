#include<iostream>
#include<math.h>
using namespace std;
int digits(int n)
{
    int ans=0;
    while(n){
        n/=10;
        ans++;
    }
    return ans;
}
bool armstrong(int n,int m)
{
    int temp=n;
    int ans=0;
    while(n){
      int rem=n%10;
      n/=10;
      ans+=pow(rem,m);
    }
    if(temp==ans)
    return 1;
    return 0;
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    int m=digits(n);
    if(armstrong(n,m))
    cout<<"The No is armstrong";
    else
    cout<<"its not ";
}

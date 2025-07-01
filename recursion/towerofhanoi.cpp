//tower of hanio
#include<iostream>
#include<vector>
using namespace std;
void towerofhanio(int n,int s,int h,int d)
{
    if(n==1){
        cout<<"Move Disk "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    towerofhanio(n-1,s,d,h);
    cout<<"Move Disk "<<n<<" from "<<s<<" to "<<d<<endl;
    towerofhanio(n-1,h,s,d);
}
int main()
{
    int n;
    cout<<"Entre The No. of disk: ";
    cin>>n;
    towerofhanio(n,1,2,3);
}
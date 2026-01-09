//
// Created by jishu on 09-01-2026.
//Minimum rotations to unlock a circular lock
//lock ko sirf ek taraf ghuma sakte hain
#include<iostream>
using namespace std;
long long MinRotation(long long R,long long D) {
    long long ans=0;
    while (R!=0) {
        long long rem1=R%10;
        long long rem2=D%10;
        R/=10;
        D/=10;
        ans+=min(abs(rem1-rem2),10-abs(rem2-rem1));
    }
    return ans;
}
int main() {
    long R,D;
    cin>>R>>D;
    cout<<MinRotation(R,D)<<" ";
}

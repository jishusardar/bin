//
// Created by Jishu Sardar on 20/08/25.
//construct target array with nultiple sum
#include <iostream>
#include<vector>
#include <queue>
using namespace std;
bool isConvertingarrayPossible(vector<int>&mat) {
    priority_queue<int>q(mat.begin(),mat.end());
    int sum=0;
    for (int i=0;i<mat.size();i++) {
        sum+=mat[i];
    }
    while (q.top()!=1) {
        int MaxEl=q.top();
        q.pop();
        int Resum=sum-MaxEl;
        if (Resum>=MaxEl||Resum<1)
            return 0;
        int el=MaxEl%Resum;
        if (el==0) {
            if (Resum==1)
                return 1;
            else
                return 0;
        }
        q.push(el);
        sum=Resum+el;
    }
    return 1;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Elemenets: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    if (isConvertingarrayPossible(arr)) {
        cout<<"The Construction is Possible";
    }
    else
        cout<<"The Construction is Not Possible";
}
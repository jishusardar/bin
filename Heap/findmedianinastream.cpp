//
// Created by jishu on 18-08-2025.
//find median in a stream
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int>q1;
priority_queue<int,vector<int>,greater<int>>q2;
void insert(int x) {
    if (q1.empty())
        q1.push(x);
    else {
        if (x>q1.top())
            q2.push(x);
        else
            q1.push(x);
    }
}
void balance() {
    if (q1.size()>q2.size()+1) {
        q2.push(q1.top());
        q1.pop();
    }
    if (q2.size()>q1.size()) {
        q1.push(q2.top());
        q2.pop();
    }
}
double median() {
    if (q1.size()==q2.size()){
        double ans=q1.top()+q2.top();
        return ans/2;
    }
    return q1.top();
}
vector<double> findmedianinanstream(vector<int>&arr) {
    vector<double>ans;
    for (int i=0;i<arr.size();i++) {
        insert(arr[i]);
        balance();
        ans.push_back(median());
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Entre The Element: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    vector<double>ans=findmedianinanstream(arr);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}

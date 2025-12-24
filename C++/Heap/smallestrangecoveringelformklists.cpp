//
// Created by Jishu Sardar on 20/08/25.
//smallest range covering all elements from k lists
#include <iostream>
#include <queue>
#include<vector>
using namespace std;
vector<int> smallestrangecovering(vector<vector<int > >&mat) {
    vector<int>ans(2);
    int minimum,maximum=INT_MIN;
    priority_queue<pair<int,pair<int,int > >,vector<pair<int,pair<int,int > > >,greater<pair<int,pair<int,int> > > >q;
    for (int i=0;i<mat.size();i++) {
        q.push(make_pair(mat[i][0],make_pair(i,0)));
        maximum=max(maximum,mat[i][0]);
    }
    ans[0]=q.top().first;
    ans[1]=maximum;
    pair<int,pair<int,int > >Ele;
    while (q.size()==mat.size()) {
        Ele=q.top();
        q.pop();
        int i=Ele.second.first;
        int j=Ele.second.second;
        if (j+1<mat[i].size()) {
            q.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
            maximum=max(maximum,mat[i][j+1]);
            minimum=q.top().first;
            if (maximum-minimum<ans[1]-ans[0]) {
                ans[0]=minimum;
                ans[1]=maximum;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cout<<"Entre The Row size: ";
    cin>>n;
    vector<vector<int > >arr;
    for (int i=0;i<n;i++) {
        int m;
        cout<<"Entre The Size Colm: ";
        cin>>m;
        vector<int>temp(m);
        cout<<"Entre The Elements: ";
        for (int j=0;j<m;j++){
            cin>>temp[j];
        }
        arr.push_back(temp);
    }
    vector<int>ans=smallestrangecovering(arr);
    cout<<"The Minimum: "<<ans[0]<<" ";
    cout<<"The Maximum: "<<ans[1]<<" ";
}
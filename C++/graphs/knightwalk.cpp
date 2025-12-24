//
// Created by jishu on 06-10-2025.
//knight walk
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int rows[8]={-1,1,-1,1,2,2,-2,-2};
int colms[8]={2,2,-2,-2,-1,1,-1,1};
bool valid(int i,int j,int n) {
    return i>=0&&j>=0&&i<n&&j<n;
}
int minstepstoreach(int n,vector<int>Kpos,vector<int>Tpos) {
    Kpos[0]--;
    Kpos[1]--;
    Tpos[0]--;
    Tpos[1]--;
    if (Kpos[0]==Tpos[0]&&Kpos[1]==Tpos[1])
        return 0;
    queue<pair<int,int>>q;
    int step=0;
    vector<vector<int>>grid(n,vector<int>(n,0));
    q.push({Kpos[0],Kpos[1]});
    grid[Kpos[0]][Kpos[1]]=1;
    while (!q.empty()) {
        int size=q.size();
        while (size--) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for (int k=0;k<8;k++) {
                if (valid(i+rows[k],j+colms[k],n)&&!grid[i+rows[k]][j+colms[k]]) {
                    if (i+rows[k]==Tpos[0]&&j+colms[k]==Tpos[1])
                        return step+1;
                    grid[i+rows[k]][j+colms[k]]=1;
                    q.push({i+rows[k],j+colms[k]});
                }
            }
        }
        step++;
    }
    return -1;
}
int main() {
    vector<vector<int>>KnightPositions={{4, 5},{7, 7}};
    vector<vector<int>>TargetPositions={{1, 1},{1, 5}};
    vector<int>Ns={6,8};
    cout<<"Min Steps To Reach: ";
    for (int i=0;i<2;i++) {
        cout<<minstepstoreach(Ns[i],KnightPositions[i],TargetPositions[i])<<" ";
    }
}
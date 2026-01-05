//
// Created by jishu on 05-01-2026.
#include<iostream>
#include <vector>
using namespace std;
bool check(int i,int j,vector<string>&Board,int n) {
    int row=i,colm=j;
    //left diagonal
    while (row>-1&&colm>-1) {
        if (Board[row][colm]=='Q')
            return 0;
        row--,colm--;
    }
    //right diagonal
    row=i,colm=j;
    while (row>-1&&colm<n) {
        if (Board[row][colm]=='Q')
            return 0;
        row--,colm++;
    }
    return 1;
}
void find(int row,vector<vector<string>>&ans,vector<string>&Board,int n,vector<bool>&colm) {
    if (row==n) {
        ans.push_back(Board);
        return;
    }
    for (int j=0;j<n;j++) {
        if (!colm[j]&&check(row,j,Board,n)) {
            colm[j]=1;
            Board[row][j]='Q';
            find(row+1,ans,Board,n,colm);
            colm[j]=0;
            Board[row][j]='.';
        }
    }
}
void  solveNQueen(int n) {
    vector<vector<string>>ans;
    vector<string>Board(n);
    vector<bool>colm(n,0);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            Board[i].push_back('.');
        }
    }
    find(0,ans,Board,n,colm);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout<<"Enter The Number Of Queen: ";
    cin>>n;
    solveNQueen(n);
}
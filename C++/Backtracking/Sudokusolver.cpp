//
// Created by jishu on 05-01-2026.
//sudoku solver
#include<iostream>
#include <vector>
using namespace std;
bool check(int i,int j,vector<vector<char>>& board,int num) {
    char ch='0'+num;
    for (int row=0;row<9;row++) {
        if (board[row][j]==ch)
            return 0;
        if (board[i][row]==ch)
            return 0;
    }
    int row=(i/3)*3;
    int col=(j/3)*3;
    for (int k=0;k<3;k++) {
        for (int l=0;l<3;l++) {
            if (board[row+k][col+l]==ch)
                return 0;
        }
    }
    return 1;
}
bool find(int i,int j,vector<vector<char>>& board) {
    if (i==9)
        return 1;
    if (j==9)
        return find(i+1,0,board);
    if (board[i][j]!='.')
        return find(i,j+1,board);
    for (int k=1;k<=9;k++) {
        if (check(i,j,board,k)) {
            board[i][j]='0'+k;
            if (find(i,j+1,board))
                return 1;
            board[i][j]='.';
        }
    }
    return 0;
}
void sudokusolver(vector<vector<char>>& board) {
    find(0,0,board);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
int main() {
    vector<vector<vector<char>>>boards={{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}}};
    sudokusolver(boards[0]);
}

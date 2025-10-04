//
// Created by jishu on 04-10-2025.
//Floyd Warshall Algorithm
//Multiple source Shortest Distance Algorithm
#include<iostream>
#include <vector>
using namespace std;
void Floyd_Warshall(vector<vector<int>>&Edges) {
    for (int k=0;k<Edges.size();k++) {
        for (int i=0;i<Edges.size();i++) {
            for (int j=0;j<Edges.size();j++) {
                if (Edges[i][k]==INT_MAX)
                    continue;
                if (Edges[k][j]==INT_MAX)
                    continue;
                Edges[i][j]=min(Edges[i][j],Edges[i][k]+Edges[k][j]);
            }
        }
    }
    for (int i=0;i<Edges.size();i++) {
        for (int j=0;j<Edges.size();j++) {
            if (Edges[i][j]==INT_MAX)
                Edges[i][j]=-1;
        }
    }
}
int main() {
vector<vector<vector<int>>>Edges={{{0, -1, 2}, {1, 0, INT_MAX}, {3, 1, 0}},{{0, 4, INT_MAX, 5, INT_MAX}, {INT_MAX, 0, 1, INT_MAX, 6}, {2, INT_MAX, 0, 3, INT_MAX}, {INT_MAX, INT_MAX, 1, 0, 2}, {1, INT_MAX, INT_MAX, 4, 0}}};
    for (int i=0;i<Edges.size();i++)
        Floyd_Warshall(Edges[i]);
    int ans=0;
    for (int i=0;i<Edges.size();i++) {
        cout<<"Answer "<<++ans<<endl;
        for (int j=0;j<Edges[i].size();j++) {
            for (int k=0;k<Edges[i].size();k++) {
                cout<<Edges[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

//celebrity problem
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int celebrityProblem(vector<vector<int>>&arr)
{
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        st.push(i);
    }
    while(st.size()>1){
        int start=st.top();
        st.pop();
        int end=st.top();
        st.pop();
        if(arr[start][end]!=arr[end][start]){
            if(arr[start][end]==0&&arr[end][start]==1)
            st.push(start);
            else
            st.push(end);
        }
    }
    if(st.empty())
    return -1;
    int num=st.top();
    st.pop();
    int sum1=0;
    int sum2=0;
    for(int i=0;i<arr.size();i++){
        sum1+=arr[i][num];
        sum2+=arr[num][i];
    }
    if(sum2==0&&sum1==arr.size()-1)
    return num;
    return -1;
}
int main()
{
    vector<vector<int>>arr={{0,1,0,1,1},{0,0,0,1,1},{0,1,0,1,0},{0,0,0,0,0},{1,0,1,1,0}};
    cout<<"The celebrity is: "<<celebrityProblem(arr);
}
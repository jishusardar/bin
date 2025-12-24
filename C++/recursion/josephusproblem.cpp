// //josephus problem
// #include<iostream>
// #include<vector>
// using namespace std;
// int josephusproblem(vector<int>&arr,int index,int person_left,int k)
// {
//     if(person_left==1){
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]==0)
//             return i+1;
//         }
//     }
//     int kill=k-1;
//     while(kill--){
//         index=(index+1)%arr.size();
//         while(arr[index]==1)
//         index=(index+1)%arr.size();
//     }
//     arr[index]=1;
//     while(arr[index]==1)
//     index=(index+1)%arr.size();
//     return josephusproblem(arr,index,person_left-1,k);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n,0);
//     int k;
//     cout<<"Entre The Kill: ";
//     cin>>k;
//     cout<<josephusproblem(arr,0,n,k);
// }
//josephus problem
#include<iostream>
#include<vector>
using namespace std;
int winner(int n,int k)
{
    if(n==1)
    return 0;
    return (winner(n-1,k)+k)%n;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n,0);
    int k;
    cout<<"Entre The Kill sequence: ";
    cin>>k;
    cout<<winner(n,k)+1;
}
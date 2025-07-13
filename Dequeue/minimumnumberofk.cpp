//minimum number of k consecutive flip bits
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumnumberofkconsequtiveflips(vector<int>&arr,int k)
{
    //optimized arrproach
    queue<int>q;
    int flips=0;
    for(int i=0;i<arr.size();i++){
        if(!q.empty()&&q.front()<i)
        q.pop();
        if(q.size()%2==arr[i]){
            if(i+k-1>=arr.size())
            return -1;
            q.push(i+k-1);
            flips++;
        }
    }
    return flips;
}
int leagyapproach(vector<int>&arr,int k)
{
    int flips=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            if(i+k-1>=arr.size())
            return -1;
            for(int j=i;j<=i+k-1;j++)
            arr[j]=!arr[j];
            flips++;
        }
    }
    return flips;
}
int main()
{
   int n,k;
   cout<<"Entre The Size: ";
   cin>>n;
   cout<<"Entre The Window Size: ";
   cin>>k;
   vector<int>arr(n);
   cout<<"Entre The Elements: ";
   for(int i=0;i<n;i++)
   cin>>arr[i];
   cout<<"Minimum No of flips required for it is: "<<minimumnumberofkconsequtiveflips(arr,k)<<endl;
   cout<<"Minimum No of flips required for it is: "<<leagyapproach(arr,k);
}
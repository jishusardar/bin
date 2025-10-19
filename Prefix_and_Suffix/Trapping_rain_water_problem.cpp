// //
// // Created by jishu on 19-10-2025.
// //Trapping Rain water Problem
// #include<iostream>
// #include <vector>
// using namespace std;
// int Tapping_Rain_Water(vector<int>&height) {
//     int water=0;
//     vector<int>prefix(height.size(),0);
//     vector<int>Suffix(height.size(),0);
//     prefix[0]=0;
//     Suffix[height.size()-1]=0;
//     for (int i=1;i<height.size();i++) {
//         prefix[i]=max(prefix[i-1],height[i-1]);
//     }
//     for (int i=height.size()-2;i>=0;i--) {
//         Suffix[i]=max(Suffix[i+1],height[i+1]);
//     }
//     for (int i=0;i<height.size();i++) {
//        int minheight=min(prefix[i],Suffix[i]);
//         if (minheight-height[i]>0)
//             water+=minheight-height[i];
//     }
//     return water;
// }
// int main() {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>height(n);
//     cout<<"Entre The Element: ";
//     for (int i=0;i<n;i++)
//         cin>>height[i];
//     cout<<Tapping_Rain_Water(height);
// }
//tapping rain water problem
#include<iostream>
#include <vector>
using namespace std;
int Tapping_Rain_water(vector<int>&height) {
    int water=0;
    int heightmax=INT_MIN,index=-1;
    for (int i=0;i<height.size();i++) {
        if (height[i]>heightmax) {
            heightmax=height[i];
            index=i;
        }
    }
    int maxheight=INT_MIN;
    for (int i=0;i<index;i++) {
        maxheight=max(maxheight,height[i]);
        if (maxheight-height[i]>0)
        water+=maxheight-height[i];
    }
    maxheight=INT_MIN;
    for (int i=height.size()-1;i>index;i--) {
        maxheight=max(maxheight,height[i]);
        if (maxheight-height[i]>0)
        water+=maxheight-height[i];
    }
    return water;
}
int main() {
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    cout<<"Entre The Element: ";
    vector<int>height(n);
    for (int i=0;i<n;i++)
        cin>>height[i];
    cout<<Tapping_Rain_water(height);
}

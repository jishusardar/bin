//tapping rain water problem
// #include<bits/stdc++.h>
// using namespace std;
// int tappingwater(vector<int>arr)
// {
//     int maxheight=0,index=0,maxleft=0,water=0,maxright=0;
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]>maxheight){
//             maxheight=arr[i];
//             index=i;
//         }
//     }
//     for(int i=0;i<index;i++){
//         if(maxleft-arr[i]>0){
//             water+=maxleft-arr[i];
//         }
//         else{
//             maxleft=arr[i];
//         }
//     }
//     for(int i=arr.size()-1;i>index;i--){
//         if(maxright-arr[i]>0){
//             water+=maxright-arr[i];
//         }
//         else
//         maxright=arr[i];
//     }
//     return water;
// }
// int tapwater(vector<int>arr)
// {
//     vector<int>prefix(arr.size(),0);
//     vector<int>suffix(arr.size(),0);
//     for(int i=1;i<arr.size();i++){
//         prefix[i]=max(prefix[i-1],arr[i-1]);
//     }
//     for(int i=arr.size()-2;i>=0;i--){
//         suffix[i]=max(suffix[i+1],prefix[i+1]);
//     }
//     int water=0;
//     for(int i=0;i<arr.size();i++){
//         int temp=min(prefix[i],suffix[i])-arr[i];
//         if(temp>0){
//             water+=min(prefix[i],suffix[i])-arr[i];
//         }
//     }
//     return water;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     cout<<tapwater(arr);
// }
//3sums
// #include<bits/stdc++.h>
// using namespace std;
// int threesums(int arr[],int n,int target)
// {
//     sort(arr,arr+n);
//     for(int i=0;i<n-2;i++){
//         int start=i+1,end=n-1;
//         int temp=target-arr[i];
//         while(start<=end){
//             if(arr[start]+arr[end]==temp)
//             return 1;
//             else if(arr[start]+arr[end]>temp)
//             end--;
//             else
//             start++;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Numb: ";
//     cin>>x;
//     cout<<threesums(arr,n,x);
// }
//4 sum
// #include<bits/stdc++.h>
// using namespace std;
// bool foursum(int arr[],int n,int target)
// {
//     sort(arr,arr+n);
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
//             int temp=target-arr[i]+arr[j];
//             int start=0,end=n-1;
//             while(start<=end){
//                 if(arr[start]==temp-arr[end])
//                 return 1;
//                 else if(arr[start]>temp-arr[end])
//                 end--;
//                 else
//                 start++;
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Target: ";
//     cin>>x;
//     cout<<foursum(arr,n,x);
// }
//container with most water
// #include<bits/stdc++.h>
// using namespace std;
// int container(int arr[],int n)
// {
//     int i=0,j=n-1,ans=0;
//     while(i<j){
//         int water=min(arr[i],arr[j])*(j-i);
//         ans=max(ans,water);
//         if(arr[i]>arr[j])
//         j--;
//         else
//         i++;
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     cout<<container(arr,n);
// }
//print matrix in all ways
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row And Colms: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<"Entre The Element: ";
//             cin>>arr[i][j];
//         }
//     }
//     cout<<"Print matrix Row Wise"<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;
//     cout<<"Print Matrix Colm Wise"<<endl;
//     for(int j=0;j<m;j++){
//         for(int i=0;i<n;i++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//add matrix
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     vector<vector<int>>arr1(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=sum++;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr1[i][j]=sum--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=arr[i][j]+arr1[i][j];
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//print row index with maximum sum
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     int sum=0;
//     int ans=0,index=0;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         int sums=0;
//         for(int j=0;j<m;j++){
//             sums+=arr[i][j];
//         }
//         if(sums>ans){
//             ans=sums;
//             index=i;
//         }
//     }
//     cout<<index;
// }
//print sum of the diagonal elements
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Row And Colms: ";
//     cin>>n;
//     int sum=0;
//     vector<vector<int>>arr(n,vector<int>(n));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     int sum1=0;
//     for(int i=0;i<n;i++){
//         sum1+=arr[i][i];
//     }
//     int sum2=0;
//     int i=0,j=arr[0].size()-1;
//     while(i<arr.size()&&j>=0){
//         sum2+=arr[i][j];
//         i++;
//         j--;
//     }
//     cout<<sum1<<" "<<sum2;
// }
//reverse each row of matrix
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n;
//     vector<vector<int>>arr(n,vector<int>(n));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         int start=0,end=arr[0].size()-1;
//         while(start<=end){
//             swap(arr[i][start],arr[i][end]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//wave form
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Row And Colm: ";
//     cin>>n;
//     vector<vector<int>>arr(n,vector<int>(n));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(i%2){
//             for(int j=n-1;j>=0;j--){
//                 cout<<arr[j][i]<<" ";
//             }
//             cout<<endl;
//         }
//         else{
//             for(int j=0;j<n;j++){
//                 cout<<arr[j][i]<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }
//spiral form
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colms: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     int left=0,right=arr[0].size()-1;
//     int top=0,bottom=arr.size()-1;
//     while(top<=bottom&&left<=right){
//         for(int i=left;i<=right;i++){
//             cout<<arr[top][i]<<" ";
//         }
//         top++;
//         for(int i=top;i<=bottom;i++){
//             cout<<arr[i][right]<<" ";
//         }
//         right--;
//         if(top<=bottom){
//             for(int i=right;i>=left;i--){
//                 cout<<arr[bottom][i]<<" ";
//             }
//             bottom--;
//         }
//         if(left<=right){
//             for(int i=bottom;i>=top;i--){
//                 cout<<arr[i][left]<<" ";
//             }
//             left++;
//         }
//     }
// }
//transpose matrix
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<m;j++){
//             swap(arr[i][j],arr[j][i]);
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//printing of diagonal
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Rows and colm: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int j=0;j<m;j++){
//         int i=0,r=j;
//         while(i<n&&r>=0){
//             cout<<arr[i][r]<<" ";
//             i++,r--;
//         }
//     }
//     for(int i=1;i<n;i++){
//         int j=arr[0].size()-1,k=i;
//         while(k<n&&j>=0){
//             cout<<arr[k][j]<<" ";
//             k++,j--;
//         }
//     }
// }
//rotate matrix by 90 degree
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Rows and Colms: ";
//     cin>>n>>m;
//     int sum=0;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<m;j++){
//             swap(arr[i][j],arr[j][i]);
//         }
//     }
//     for(int i=0;i<n;i++){
//         int start=0,end=m-1;
//         while(start<=end){
//             swap(arr[i][start],arr[i][end]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//rotate by 180 degree
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row And Colm: ";
//     cin>>n>>m;
//     int sum=0;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         int start=0,end=m-1;
//         while(start<=end){
//             swap(arr[i][start],arr[i][end]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<m;i++){
//         int start=0,end=n-1;
//         while(start<=end){
//             swap(arr[start][i],arr[end][i]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//rotate matrix 90 degree anticlockwise
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<m;j++)
//         swap(arr[i][j],arr[j][i]);
//     }
//     for(int j=0;j<m;j++){
//         int start=0,end=arr[0].size()-1;
//         while(start<=end){
//             swap(arr[start][j],arr[end][j]);
//             start++,end--;
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//rotate matrix k times
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     int sum=0;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     int x;
//     cout<<"Entre The Times to Rotate: ";
//     cin>>x;
//     x=x%4;
//     while(x--){
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<m;j++){
//                 swap(arr[i][j],arr[j][i]);
//             }
//         }
//         for(int i=0;i<n;i++){
//             int start=0,end=arr[0].size()-1;
//             while(start<=end){
//                 swap(arr[i][start],arr[i][end]);
//                 start++,end--;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//binary search in matrix
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Row and Colm: ";
//     cin>>n>>m;
//     int sum=0;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     int target;
//     cout<<"Entre The Target: ";
//     cin>>target;
//     for(int i=0;i<n;i++){
//         if(arr[i][0]<=target&&arr[i][m-1]>=target){
//             int start=0,end=m-1;
//             while(start<=end){
//                 int mid=start+(end-start)/2;
//                 if(arr[i][mid]==target){
//                 cout<<"found";
//                 return 0;
//                 }
//                 else if(arr[i][mid]>target)
//                 end=mid-1;
//                 else
//                 start=mid+1;
//             }
//         }
//     }
// }
//search in row and colm sorted matrix
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The Rows and Colm: ";
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     int sum=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             arr[i][j]=++sum;
//         }
//     }
//     int target;
//     cout<<"Entre The Target: ";
//     cin>>target;
//     int i=0,j=m-1;
//     while(i<n&&j>=0){
//         if(arr[i][j]==target){
//             cout<<"Fround";
//             return 0;
//         }
//         else if(arr[i][j]>target)
//         j--;
//         else
//         i++;
//     }
// }
//store tow number at one position
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     for(int i=0;i<n;i++){
//         arr[i]--;
//     }
//     for(int i=0;i<n;i++){
//         arr[arr[i]%n]+=n;
//     }
//     for(int i=0;i<n;i++){
//         if(arr[i]/n==0){
//             cout<<"The Missing no: "<<i+1<<endl;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(arr[i]/n>1){
//             cout<<"The Repetative no: "<<i+1<<endl;
//         }
//     }
// }
//moorey voting algorithm
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int candidate=0;
//     int count;
//     for(int i=0;i<n;i++){
//         if(candidate==0){
//             candidate=arr[i];
//             count=1;
//         }
//         else{
//             if(candidate==arr[i])
//             count++;
//             else
//             count--;
//         }
//     }
//     count=0;
//     for(int i=0;i<n;i++){
//         if(candidate==arr[i])
//         count++;
//     }
//     if(count>n/2)
//     cout<<"The Winner Is : "<<candidate;
// }
//strings in cpp
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     s[3]='\0';//escaping character
//     cout<<s;
// }
//defanging and ip
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='.'){
//             cout<<"[.]";
//         }
//         else
//         cout<<s[i];
//     }
// }
//check if string rotated by 2 places or not 
// #include<bits/stdc++.h>
// using namespace std;
// string rotateclock(string s)
// {
//     string temp="";
//     temp+=s[0];
//     temp+=s[1];
//     for(int i=2;i<s.size();i++){
//         s[i-2]=s[i];
//     }
//     s[s.size()-2]=temp[0];
//     s[s.size()-1]=temp[1];
//     return s;
// }
// string rotateanticlock(string s)
// {
//     string temp="";
//     temp+=s[s.size()-2];
//     temp+=s[s.size()-1];
//     for(int i=s.size()-3;i>=0;i--){
//         s[i+2]=s[i];
//     }
//     s[0]=temp[0];
//     s[1]=temp[1];
//     return s;
// }
// int main()
// {
//     string s1;
//     cout<<"Entre The Original String: ";
//     cin>>s1;
//     string s2;
//     cout<<"Entre The Rotated String: ";
//     cin>>s2;
//     if(rotateclock(s2)==s1||rotateanticlock(s2)==s1){
//         cout<<"Same String "<<" ";
//         return 0;
//     }
// }
//check pangram if it includes all the characters
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int>arr(26,0);
//     string s="The quick brown fox jumps over the lazy dog";
//     for(int i=0;i<s.size();i++){
//         if(s[i]>='A'&&s[i]<='Z')
//         arr[s[i]-'A']++;
//         else if(s[i]>='a'&&s[i]<='z')
//         arr[s[i]-'a']++;
//     }
//     for(int i=0;i<arr.size();i++){
//         if(arr[i]==0){
//             cout<<"its not a pangram ";
//             return 0;
//         }
//     }
//     cout<<"its a pangram ";
//     return 0;
// }
//sort a string
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre the String: ";
//     cin>>s;
//     vector<int>arr1(26,0);
//     vector<int>arr2(26,0);
//     for(int i=0;i<s.size();i++){
//         if(s[i]>='A'&&s[i]<='Z')
//         arr1[s[i]-'A']++;
//         else if(s[i]>='a'&&s[i]<='z')
//         arr2[s[i]-'a']++;
//     }
//     string ans="";
//     for(int i=0;i<arr1.size();i++){
//         if(arr1[i]){
//             char c='A'+i;
//             ans+=c;
//         }
//     }
//     for(int i=0;i<arr2.size();i++){
//         if(arr2[i]){
//             char c='a'+i;
//             ans+=c;
//         }
//     }
//     cout<<ans<<" ";
// }
//longest palindrome
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="abccccdd";
//     vector<int>count(26,0);
//     for(int i=0;i<s.size();i++){
//         if(s[i]>='a'&&s[i]<='z')
//         count[s[i]-'a']++;
//     }
//     int length=0;
//     int odd=0;
//     for(int i=0;i<count.size();i++){
//         if(count[i]%2==0){
//             length+=count[i];
//         }
//         else{
//             length+=count[i]-1;
//             odd=1;
//         }
//     }
//     cout<<length+odd;
// }
//sort the sentence
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// { 
//     string s="is2 sentence4 this1 a3";
//     int n=1;
//     for(int i=0;i<s.size();i++){
//         if(s[i]==' ')
//         n++;
//     }
//     vector<string>arr(n);
//     string temp;
//     for(int i=0;i<s.size();i++){
//         if(s[i]==' '){
//             int c=s[i-1]-'0';
//             temp.pop_back();
//             arr[c]=temp;
//         }
//         else
//         temp+=s[i];
//     }
//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
// }
//sort vowel in a string
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     vector<int>count(26,0);
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
//         count[s[i]-'a']++;
//     }
//     string temp="";
//     for(int i=0;i<count.size();i++){
//         while(count[i]--){
//             char c='a'+i;
//             temp+=c;
//         }
//     }
//     int j=0;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'){
//             s[i]=temp[j];
//             j++;
//         }
//     }
//     cout<<s;
// }
//
// add strings
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string num1;
//     string num2;
//     string ans;
//     cout<<"Entre The Num 1: ";
//     cin>>num1;
//     cout<<"Entre The Num 2: ";
//     cin>>num2;
//     reverse(num1.begin(),num1.end());
//     reverse(num2.begin(),num2.end());
//     int i=0,j=0;
//     int carry=0;
//     while(i<num1.size()&&j<num2.size()){
//         int sum=(num1[i]-'0')+(num2[j]-'0')+carry;
//         carry=sum/10;
//         ans.push_back(((sum%10)+'0'));
//         i++,j++;
//     }
//     while(i<num1.size()){
//         int sum=(num1[i]-'0')+carry;
//         carry=sum/10;
//         ans.push_back(((sum%10)+'0'));
//         i++;
//     }
//     while(j<num2.size()){
//         int sum=(num2[j]-'0')+carry;
//         carry=sum/10;
//         ans.push_back(((sum%10)+'0'));
//         j++;
//     }
//     while(carry){
//         int sum=carry;
//         carry=sum/10;
//         ans.push_back((sum%10)+'0');
//     }
//     reverse(ans.begin(),ans.end());
//     cout<<ans;
// }
//roman to integer
// #include<bits/stdc++.h>
// using namespace std;
// int integer(char c)
// {
//     if(c=='I')
//     return 1;
//     else if(c=='V')
//     return 5;
//     else if(c=='X')
//     return 10;
//     else if(c=='L')
//     return 50;
//     else if(c=='C')
//     return 100;
//     else if(c=='D')
//     return 500;
//     else if(c=='M')
//     return 1000;
//     return 0;
// }
// int main()
// {
//     string s;
//     cout<<"Entre The Roaman No: ";
//     cin>>s;
//     int num=0;
//     for(int i=0;i<s.size();i++){
//         if(integer(s[i])<integer(s[i+1])){
//             num-=integer(s[i]);
//         }
//         else{
//             num+=integer(s[i]);
//         }
//     }
//     cout<<num;
// }
//integer to roman
// #include<bits/stdc++.h>
// using namespace std;
// string roman(int &n)
// {
//     if(n>=1&&n<5){
//         if(n==4){
//         n-=4;
//         return "IV";
//         }
//         else{
//         n-=1;
//         return "I";
//         }
//     }
//     else if(n>=5&&n<10)
//     {
//         if(n==9){
//             n-=9;
//             return "IX";
//         }
//         else{
//             n-=5;
//             return "V";
//         }
//     }
//     else if(n>=10&&n<50)
//     {
//         if(n>=40){
//             n-=40;
//             return "XL";
//         }
//         else{
//             n-=10;
//             return "X";
//         }
//     }
//     else if(n>=50&&n<100)
//     {
//         if(n>=90){
//             n-=90;
//             return "XC";
//         }
//         else{
//             n-=50;
//             return "L";
//         }
//     }
//     else if(n>=100&&n<500){
//         if(n>=400){
//             n-=400;
//             return "CD";
//         }
//         else{
//             n-=100;
//             return "C";
//         }
//     }
//     else if(n>=500&&n<1000){
//         if(n>=900){
//             n-=900;
//             return "CM";
//         }
//         return "D";
//     }
//     else
//     {
//         n-=1000;
//         return "M";
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Number: ";
//     cin>>n;
//     string ans="";
//     while(n){
//         ans+=roman(n);
//     }
//     cout<<ans;
// }
//factorial of a number
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The Number: ";
//     cin>>s;
// }
//sliding window protocal
//largest substring without repetating char
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     vector<int>count(256,0);
//     int i=0,j=0;
//     int len=0;
//     while(j<s.size()){
//         while(count[s[j]]){
//             count[s[i]]--;
//             i++;
//         }
//         count[s[j]]++;
//         len=max(len,abs(i-j));
//         j++;
//     }
//     cout<<len;
// }
//smallest distinct window
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     vector<int>count(256,0);
//     for(int i=0;i<s.size();i++){
//         count[s[i]]++;
//     }
//     int diff=0;
//     for(int i=0;i<256;i++){
//         if(count[i]!=0){
//             diff++;
//             count[i]=0;
//         }
//     }
//     int i=0,j=0;
//     int len=s.size();
//     while(j<s.size()){
//         while(diff){
//             if(count[s[j]]==0){
//                 diff--;
//             }
//             count[s[j]]++;
//             j++;
//         }
//         len=min(len,abs(i-j));
//         while(diff!=1){
//             len=min(len,abs(i-j));
//             count[s[i]]--;
//             if(count[s[i]]==0)
//             diff++;
//             i++;
//         }
//     }
//     cout<<len;
// }
//smallest window containing 0 1 and 2
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="000111012";
//     int arr[3];
//     int i=0,j=0;
//     int len=s.size()+1;
//     while(j<s.size())
//     {
//         arr[s[j]-'0']++;
//         j++;
//         while(i<j&&arr[s[i]-'0']>1){
//             arr[s[i]-'0']--;
//             i++;
//         }
//         if(arr[0]>=1&&arr[1]>=1&&arr[2]>=1){
//             len=min(len,abs(i-j));
//         }
//     }
//     if(len==s.size()+1){
//         cout<<"Not Found";
//     }
//     else{
//         cout<<"Found";
//     }
//     return 0;
// }
//longest k unique substring
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="abbbbbbbbbbbcdg";
//     int k=3;
//     int i=0,j=0,l=0;
//     int len=0;
//     vector<int>count(256,0);
//     while(j<s.size()){
//         if(l<k){
//             if(count[s[j]]==0){
//                 l++;
//             }
//             count[s[j]]++;
//             j++;
//         }
//         else{
//             count[s[i]]--;
//             if(count[s[i]]==0){
//                 l--;
//             }
//             i++;
//         }
//         if(l==k)
//         len=max(len,abs(i-j)+1);
//     }
//     if(len==0){
//         cout<<-1;
//     }
//     else{
//         cout<<len;
//     }
//     return 0;
// }
//kmp algorithm
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="ABCDEABCD";
//     vector<int>lps(s.size(),0);
//     int pre=0,suff=1;
//     while(suff<s.size()){
//         if(s[pre]==s[suff]){
//             lps[suff]=pre+1;
//             pre++;
//             suff++;
//         }
//         else
//         {
//             if(pre==0){
//                 suff++;
//             }
//             else{
//                 pre=lps[pre-1];
//             }
//         }
//     }
//     cout<<lps[lps.size()-1];
// }
//add min chars to make it palindrome and the chars
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="ROORSP";
//     string temp=s;
//     s+='$';
//     reverse(temp.begin(),temp.end());
//     s+=temp;
//     vector<int>lps(s.size(),0);
//     int pre=0,suff=1;
//     while(suff<s.size()){
//         if(s[pre]==s[suff]){
//             lps[suff]=pre+1;
//             suff++;
//             pre++;
//         }
//         else{
//             if(pre==0)
//             suff++;
//             else
//             pre=lps[pre-1];
//         }
//     }
//     cout<<temp.size()-lps[lps.size()-1];
//     int count=temp.size()-lps[lps.size()-1];
//     string ans="";
//     while(count--){
//         ans+=temp[count];
//     }
//     reverse(ans.begin(),ans.end());
//     cout<<ans;
// }
//circular pattern matching 
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="cdeabroab";
//     string f="abcde";
//     s+=s;
//     vector<int>lps(f.size(),0);
//     int pre=0,suff=1;
//     while(suff<f.size()){
//         if(f[pre]==f[suff]){
//             lps[suff]=pre+1;
//             pre++;
//             suff++;
//         }
//         else{
//             if(pre==0)
//             suff++;
//             else
//             pre=lps[pre-1];
//         }
//     }
//     int first=0,second=0;
//     while(first<s.size()&&second<f.size()){
//         if(s[first]==f[second]){
//             first++,second++;
//         }
//         else
//         {
//             if(second==0)
//             first++;
//             else
//             second=lps[second-1];
//         }
//     }
//     if(second==f.size()){
//         cout<<"Matched";
//     }
//     else{
//         cout<<"Not Matched";
//     }
//     return 0;
// }
//repeated string match
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s="abcd";
//     string s1="cdabcdab";
//     while(s.size()<=s1.size()){
//         s+=s;
//     }
//     vector<int>lps(s1.size(),0);
//     int pre=0,suff=1;
//     while(suff<s1.size()){
//         if(s1[pre]==s1[suff]){
//             lps[suff]=pre+1;
//             pre++,suff++;
//         }
//         else{
//             if(pre==0)
//             suff++;
//             else
//             pre=lps[pre-1];
//         }
//     }
//     int first=0,second=0;
//     while(first<s.size()&&second<s1.size()){
//         if(s[first]==s1[second]){
//             first++,second++;
//         }
//         else{
//             if(second==0)
//             first++;
//             else
//             second=lps[second-1];
//         }
//     }
//     if(second==s1.size()){
//         cout<<"Found";
//     }
//     else
//     cout<<"Not Found";
//     return 0;
// }
//pointers in c++
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int a=10;
//     int* ptr=&a;
//     //reference operator
//     cout<<ptr;
//     //derefrence operator
//     cout<<*ptr;
// }
//
//point array using pointers
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int * ptr=arr;
//     for(int i=0;i<n;i++){
//         cout<<*(ptr+i)<<" ";
//     }
// }
//chars
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     char arr[n];
//     char *ptr =arr;
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Eleemnt: ";
//         cin>>*(ptr+i);
//     }
//     for(int i=0;i<n;i++){
//         cout<<*(ptr+i)<<" ";
//     }    
// }
//2d array using pointers
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     cout<<"Entre The No of Rows and Colm: ";
//     cin>>n>>m;
//     int **ptr=new int*[n];
//     for(int i=0;i<n;i++){
//         *(ptr+i)=new int[m];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<"Entre The Element: ";
//             cin>>*(*(ptr+i)+j);
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<*(*(ptr+i)+j)<<" ";
//         }
//     }
// }
//3d array using pointers
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m,h;
//     cout<<"Entre The Row and colm and height: ";
//     cin>>n>>m>>h;
//     int ***arr=new int**[n];
//     for(int i=0;i<n;i++){
//         arr[i]=new int*[m];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             *(*(arr+i)+j)=new int[h];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             for(int k=0;k<h;k++){
//                 cout<<"Entre The Element: ";
//                 cin>>*(*(*(arr+i)+j)+k);
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             for(int k=0;k<h;k++){
//                 cout<<*(*(*(arr+i)+j)+k);
//             }
//         }
//     }
// }
//4d pointers 
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m,h,l;
//     cout<<"Entre Four Values: ";
//     cin>>n>>m>>h>>l;
//     int ****ptr=new int***[n];
//     for(int i=0;i<n;i++){
//         ptr[i]=new int**[m];
//         for(int j=0;j<m;j++){
//             *(*(ptr+i)+j)=new int*[h];
//             for(int k=0;k<h;k++){
//                 *(*(*(ptr+i)+j)+k)=new int[l];
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             for(int k=0;k<h;k++){
//                 for(int p=0;p<l;p++){
//                     cout<<"Entre the Element: ";
//                     cin>>*(*(*(*(ptr+i)+j)+k)+p);
//                 }
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             for(int k=0;k<h;k++){
//                 for(int p=0;p<l;p++){
//                     cout<<*(*(*(*(ptr+i)+j)+k)+p)<<" ";
//                 }
//             }
//         }
//     }
// }
//recursion
// #include<bits/stdc++.h>
// using namespace std;
// void fun(int n)
// {
//     if(n==0){
//     cout<<"Happy Birthday"<<endl;
//     return;
//     }
//     cout<<n<<"Days left for birthday"<<endl;
//     fun(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre Days Left: ";
//     cin>>n;
//     fun(n);
// }
//print numbers
// #include<bits/stdc++.h>
// using namespace std;
// void numbers(int n)
// {
//     if(n==0)
//     return;
//     cout<<n<<endl;
//     numbers(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The number: ";
//     cin>>n;
//     numbers(n);
// }
//print 1 to n even numbers
//#include<bits/stdc++.h>
// using namespace std;
// void printeven(int n,int i)
// {
//     if(i==n+1)
//     return;
//     if(i%2==0)
//     cout<<i<<endl;
//     printeven(n,i+1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The num: ";
//     cin>>n;
//     printeven(n,1);
// }
//factorial
// #include<bits/stdc++.h>
// using namespace std;
// int factorial(int n)
// {
//     if(n==1)
//     return n;
//     return n*factorial(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The num: ";
//     cin>>n;
//     cout<<factorial(n);
// }
//sum of n natural number
// #include<bits/stdc++.h>
// using namespace std;
// int sums(int n)
// {
//     if(n==1)
//     return n;
//     return n+sums(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The num: ";
//     cin>>n;
//     cout<<sums(n);
// }
//power of 2
// #include<bits/stdc++.h>
// using namespace std;
// int power(int n)
// {
//     if(n==1)
//     return 2;
//     return 2*power(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The power: ";
//     cin>>n;
//     cout<<power(n);
// }
//sum of square of n numbers
// #include<bits/stdc++.h>
// using namespace std;
// int sumofsq(int n)
// {
//     if(n==1)
//     return n*n;
//     return n*n+sumofsq(n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The nth trem: ";
//     cin>>n;
//     cout<<sumofsq(n);
// }
//fibonacci
// #include<bits/stdc++.h>
// using namespace std;
// int fibonachi(int n)
// {
//     if(n<2)
//     return n;
//     return fibonachi(n-1)+fibonachi(n-2);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The nth term: ";
//     cin>>n;
//     cout<<fibonachi(n);
// }
//nth stair 
// #include<bits/stdc++.h>
// using namespace std;
// int totalways(int n)
// {
//     if(n<=1)
//     return 1;
//     return totalways(n-1)+totalways(n-2);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The nth term: ";
//     cin>>n;
//     cout<<totalways(n);
// }
//gcd of 2 number
// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int a,int b)
// {
//     if(b==0)
//     return a;
//     return gcd(b,a%b);
// }
// int main()
// {
//     int a,b;
//     cout<<"Entre The numbers: ";
//     cin>>a>>b;
//     cout<<gcd(a,b);
// }
//recursion in array
// #include<bits/stdc++.h>
// using namespace std;
// void recursioninarr(int arr[],int n,int i)
// {
//     if(i==n)
//     return;
//     cout<<arr[i]<<" ";
//     recursioninarr(arr,n,i+1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     recursioninarr(arr,n,0);
// }
//sum of all element
// #include<bits/stdc++.h>
// using namespace std;
// int sum(int arr[],int n)
// {
//     if(n==0)
//     return arr[n];
//     return arr[n]+sum(arr,n-1);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     cout<<sum(arr,n-1);
// }
//min eleemnt
// #include<bits/stdc++.h>
// using namespace std;
// int findmin(int arr[],int n)
// {
//     if(n==0)
//     return arr[n];
//     return min(arr[n],findmin(arr,n-1));
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     cout<<findmin(arr,n-1);
// }
//check palindrome
// #include<bits/stdc++.h>
// using namespace std;
// bool checkpal(int end,int arr[],int start)
// {
//     if(start>=end)
//     return 1;
//     if(arr[start]!=arr[end])
//     return 0;
//     return checkpal(end-1,arr,start+1); 
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     cout<<checkpal(n-1,arr,0);
// }
//count vowels
// #include<bits/stdc++.h>
// using namespace std;
// int countvowels(char arr[],int n,int count)
// {
//     if(n==-1)
//     return count;
//     if(arr[n]=='a'||arr[n]=='e'||arr[n]=='i'||arr[n]=='o'||arr[n]=='u')
//     return countvowels(arr,n-1,count+1);
//     return countvowels(arr,n-1,count); 
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     char arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elemnt: ";
//         cin>>arr[i];
//     }
//     cout<<countvowels(arr,n-1,0);
// }
//reverse a string
// #include<bits/stdc++.h>
// using namespace std;
// string reverse(string &s,int start,int end)
// {
//     if(start>=end)
//     return s;
//     swap(s[start],s[end]);
//     return reverse(s,start+1,end-1);
// }
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     cout<<reverse(s,0,s.size()-1);
// }
//lowercase to uppercase
// #include<bits/stdc++.h>
// using namespace std;
// void lowercasetoupper(string s,int n)
// {
//     if(n==-1)
//     return;
//     int m=s[n]-'a';
//     char c='A'+m;
//     cout<<c<<" ";
//     lowercasetoupper(s,n-1);
    
// }
// int main()
// {
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     lowercasetoupper(s,s.size()-1);
// }
//linear search
// #include<bits/stdc++.h>
// using namespace std;
// bool linearsearch(int arr[],int n,int x)
// {
//     if(n==-1)
//     return 0;
//     if(arr[n]==x)
//     return 1;
//     return linearsearch(arr,n-1,x);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Element to Find: ";
//     cin>>x;
//     cout<<linearsearch(arr,n-1,x);
// }
//binary search
// #include<bits/stdc++.h>
// using namespace std;
// bool binarysearch(int arr[],int start,int end,int x)
// {
//     if(start>=end)
//     return 0;
//     int mid=start+(end-start)/2;
//     if(arr[mid]==x)
//     return 1;
//     else if(arr[mid]>x)
//     return binarysearch(arr,start,mid-1,x);
//     else
//     return binarysearch(arr,mid+1,end,x);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element:";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Element to find: ";
//     cin>>x;
//     cout<<binarysearch(arr,0,n-1,x);
// }
// //merge sort
// #include<bits/stdc++.h>
// using namespace std;
// void merge(int arr[],int start,int end,int mid)
// {
//     vector<int>temp(end-start+1);
//     int left=start;
//     int right=mid+1;
//     int index=0;
//     while(left<=mid&&right<=end){
//         if(arr[left]>arr[right]){
//             temp[index]=arr[right];
//             index++,right++;
//         }
//         else{
//             temp[index]=arr[left];
//             left++,index++;
//         }
//     }
//     while(left<=mid){
//         temp[index]=arr[left];
//         index++,left++;
//     }
//     while(right<=end){
//         temp[index]=arr[right];
//         index++,right++;
//     }
//     index=0;
//     while(start<=end){
//         arr[start]=temp[index];
//         start++,index++;
//     }
// }
// void mergesort(int arr[],int start,int end)
// {
//     if(start>=end)
//     return;
//     int mid=start+(end-start)/2;
//     mergesort(arr,start,mid);
//     mergesort(arr,mid+1,end);
//     merge(arr,start,end,mid);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elment: ";
//         cin>>arr[i];
//     }
//     mergesort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
//quick sort 
// #include<bits/stdc++.h>
// using namespace std;
// int partition(vector<int>&arr,int start,int end)
// {
//     int pos=start;
//     for(int i=start;i<=end;i++){
//         if(arr[i]<=arr[end]){
//             swap(arr[pos],arr[i]);
//             pos++;
//         }
//     }
//     return pos-1;
// }
// void quicksort(vector<int>&arr,int start,int end)
// {
//     if(start>=end)
//     return ;
//     int pivot=partition(arr,start,end);
//     quicksort(arr,start,pivot-1);
//     quicksort(arr,pivot+1,end);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elements: ";
//         cin>>arr[i];
//     }
//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     quicksort(arr,0,n-1);
//     for(int i=0;i<arr.size();i++){
//         cout<<arr[i]<<" ";
//     }
// }
//subsequence
// #include<bits/stdc++.h>
// using namespace std;
// void subsequence(vector<int>&arr,int i,vector<int>&temp,vector<vector<int>>&ans)
// {
//     if(i==arr.size()){
//         ans.push_back(temp);
//         return;
//     }
//     temp.push_back(arr[i]);
//     subsequence(arr,i+1,temp,ans);
//     temp.pop_back();
//     subsequence(arr,i+1,temp,ans);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     vector<int>temp;
//     vector<vector<int>>ans;
//     subsequence(arr,0,temp,ans);
// }
//string subsequence
// #include<bits/stdc++.h>
// using namespace std;
// void stringsubsequence(string s,int i,string temp,vector<string>&ans)
// {
//     if(i==s.size()){
//         ans.push_back(temp);
//         return;
//     }
//     stringsubsequence(s,i+1,temp,ans);
//     temp.push_back(s[i]);
//     stringsubsequence(s,i+1,temp,ans);
//     temp.pop_back();
// }
// int main(){
//     string s;
//     cout<<"Entre The String: ";
//     cin>>s;
//     string temp;
//     vector<string>ans;
//     stringsubsequence(s,0,temp,ans);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
// }
//generate parenthesis
// #include<bits/stdc++.h>
// using namespace std;
// void generateparenthesis(int n,int left,int right,string &temp,vector<string>&ans)
// {
//     if(left+right==2*n){
//         ans.push_back(temp);
//         return;
//     }
//     if(left<n){
//         temp.push_back('(');
//         generateparenthesis(n,left+1,right,temp,ans);
//         temp.pop_back();
//     }
//     if(right<left){
//         temp.push_back(')');
//         generateparenthesis(n,left,right+1,temp,ans);
//         temp.pop_back();
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The num: ";
//     cin>>n;
//     vector<string>ans;
//     string temp;
//     generateparenthesis(n,0,0,temp,ans);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
// }
//subsets sums
// #include<bits/stdc++.h>
// using namespace std;
// void subsetsums(vector<int>arr,int sums,int i,vector<int>&ans)
// {
//     if(i==arr.size()){
//         ans.push_back(sums);
//         return;
//     }
//     subsetsums(arr,sums,i+1,ans);
//     subsetsums(arr,sums+=arr[i],i+1,ans);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     vector<int>ans;
//     subsetsums(arr,0,0,ans);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
// }
//target sum(approach 1)
// #include<bits/stdc++.h>
// using namespace std;
// bool targetsum(vector<int>arr,int i,int sum,int x)
// {
//     if(sum==x)
//     return 1;
//     if(i==arr.size()||sum>x)
//     return 0;
//     return targetsum(arr,i+1,sum,x)||targetsum(arr,i+1,sum+arr[i],x);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Element to find: ";
//     cin>>x;
//     cout<<targetsum(arr,0,0,x);
// }
//target sum (approach 2)
// #include<bits/stdc++.h>
// using namespace std;
// bool targetsums(vector<int>arr,int i,int x)
// {
//     if(x==0)
//     return 1;
//     if(i==arr.size()||x<0)
//     return 0;
//     return targetsums(arr,i+1,x)||targetsums(arr,i+1,x-arr[i]);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elements: ";
//         cin>>arr[i];
//     }
//     int x;
//     cout<<"Entre The Element To Find: ";
//     cin>>x;
//     cout<<targetsums(arr,0,x);
// }
//permutations(elements are dintinct)
// #include<bits/stdc++.h>
// using namespace std;
// void permutation(vector<int>&arr,vector<bool>&visited,vector<int>&temp,vector<vector<int>>&ans)
// {
//     if(temp.size()==arr.size())
//     {
//         ans.push_back(temp);
//         return;
//     }
//     for(int i=0;i<visited.size();i++){
//         if(visited[i]==0){
//             visited[i]=1;
//             temp.push_back(arr[i]);
//             permutation(arr,visited,temp,ans);
//             temp.pop_back();
//             visited[i]=0;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     vector<bool>count(arr.size(),0);
//     vector<int>temp;
//     vector<vector<int>>ans;
//     permutation(arr,count,temp,ans);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//permutation(space complexity O(1))
// #include<bits/stdc++.h>
// using namespace std;
// void permute(vector<vector<int>>&ans,vector<int>&arr,int j)
// {
//     if(j==arr.size())
//     {
//         ans.push_back(arr);
//         return;
//     }
//     for(int i=j;i<arr.size();i++){
//         swap(arr[i],arr[j]);
//         permute(ans,arr,j+1);
//         swap(arr[i],arr[j]);
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elemnt: ";
//         cin>>arr[i];
//     }
//     vector<vector<int>>ans;
//     permute(ans,arr,0);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//permutations
//where elements are rangeing from -10 to 10 are finite 
// #include<bits/stdc++.h>
// using namespace std;
// void permute(vector<vector<int>>&ans,vector<int>&arr,int j)
// {
//     if(j==arr.size()){
//         ans.push_back(arr);
//         return;
//     }
//     vector<bool>count(21,0);
//     for(int i=j;i<arr.size();i++){
//         if(count[arr[i]+10]==0){
//             swap(arr[i],arr[j]);
//             permute(ans,arr,j+1);
//             swap(arr[i],arr[j]);
//             count[arr[i]+10]=1;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     vector<vector<int>>ans;
//     permute(ans,arr,0);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//ways to sum n
// #include<bits/stdc++.h>
// using namespace std;
// int waystosum(vector<int>&arr,int sum)
// {
//     if(sum==0)
//     return 1;
//     if(sum<0)
//     return 0;
//     int ans=0;
//     for(int i=0;i<arr.size();i++){
//         ans+=waystosum(arr,sum-arr[i]);
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Eleemnt: ";
//         cin>>arr[i];
//     }
//     int m;
//     cout<<"Entre The Sum: ";
//     cin>>m;
//     cout<<waystosum(arr,m);
// }
//tower of hanoi
// #include<bits/stdc++.h>
// using namespace std;
// void TOH(int n,int source,int helper,int dest)
// {
//     if(n==1){
//         cout<<"Move disk"<<n<<"from"<<source<<"to"<<dest<<endl;
//         return;
//     }
//     TOH(n-1,source,dest,helper);
//     cout<<"Move disk"<<n<<"From"<<source<<"to"<<dest<<endl;
//     TOH(n-1,helper,source,dest);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Disk: ";
//     cin>>n;
//     TOH(n,1,2,3);
// }
//josephus problem (1st approach) space complexity(O(n))
// #include<bits/stdc++.h>
// using namespace std;
// int Findthewinner(vector<bool>&person,int n,int k,int pl,int in)
// {
//     if(pl==1){
//         for(int i=0;i<person.size();i++){
//             if(person[i]==0)
//             return i+1;
//         }
//     }
//     int kill=(k-1)%pl;
//     while(kill--){
//         in=(in+1)%n;
//         while(person[in]==1)
//         in=(in+1)%n;
//     }
//     person[in]=1;
//     while(person[in]==1)
//     in=(in+1)%n;
//     return Findthewinner(person,n,k,pl-1,in);
// }
// int main()
// {
//     int n,k;
//     cout<<"Entre The No of people: ";
//     cin>>n;
//     cout<<"Entre The kth term: ";
//     cin>>k;
//     vector<bool>count(n,0);
//     cout<<Findthewinner(count,n,k,n,0);
// }
//josephus problem(2nd approach) space complexity(O(1))
// #include<bits/stdc++.h>
// using namespace std;
// int findthewinner(int n,int k)
// {
//     if(n==1)
//     return 0;
//     return (findthewinner(n-1,k)+k)%n;
// }
// int main()
// {
//     int n,k;
//     cout<<"Entre The nth term: ";
//     cin>>n;
//     cout<<"Entre The kth term: ";
//     cin>>k;
//     cout<<findthewinner(n,k)+1;
// }
//rat in a maze
//only move to the matrix where its value is 1
// #include<bits/stdc++.h>
// using namespace std;
// int row[4]={-1,1,0,0};
// int col[4]={0,0,-1,1};
// string dir="UDLR";
// bool valid(int i,int j,int n)
// {
//     return i>=0&&j>=0&&i<n&&j<n;
// }
// void maze(vector<vector<int>>&mat,vector<vector<bool>>&vis,int i,int j,string &temp,vector<string>&ans,int n)
// {
//     if(i==n-1&&j==n-1){
//         ans.push_back(temp);
//         return;
//     }
//     vis[i][j]=1;
//     for(int k=0;k<4;k++){
//         if(valid(i+row[k],j+col[k],n)&&mat[i+row[k]][j+col[k]]&&!vis[i+row[k]][j+col[k]]){
//             temp.push_back(dir[k]);
//             maze(mat,vis,i+row[k],j+col[k],temp,ans,n);
//             temp.pop_back();
//         }
//     }
//     vis[i][j]=0;
// }
// vector<string> ratiinmaze(vector<vector<int>>&mat)
// {
//     int n=mat.size();
//     vector<string>ans;
//     string temp;
//     vector<vector<bool>>vis(n,vector<bool>(n,0));
//     if(mat[0][0]==0&&mat[n-1][n-1]==0){
//         ans.push_back("-1");
//         return ans;
//     }
//     maze(mat,vis,0,0,temp,ans,n);
//     return ans;
// }
// int main()
// {
//     vector<vector<int>>mat(4,vector<int>(4));
//     mat={{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
//     vector<string>ans=ratiinmaze(mat);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<endl;
//     }
// }
//nbit binary numbers
// #include<bits/stdc++.h>
// using namespace std;
// void nbitbn(vector<vector<int>>&ans,vector<int>&arr,int one,int zero,int i,int n)
// {
//     if(i==n){
//         ans.push_back(arr);
//         return;
//     }
//     if(one<n){
//         arr.push_back(1);
//         nbitbn(ans,arr,one+1,zero,i+1,n);
//         arr.pop_back();
//     }
//     if(zero<one){
//         arr.push_back(0);
//         nbitbn(ans,arr,one,zero+1,i+1,n);
//         arr.pop_back();
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Entre The No. of bits: ";
//     cin>>n;
//     vector<vector<int>>ans;
//     vector<int>arr;
//     nbitbn(ans,arr,0,0,0,n);
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
//object oriented programing 
//with constructor
// #include<bits/stdc++.h>
// using namespace std;
// class customer
// {
//     int balance;
//     string name;
//     public:
//     customer(string name,int balance)
//     {
//         this->name=name;
//         this->balance=balance; 
//     }
//     void printdet()
//     {
//         cout<<name;
//         cout<<balance;
//     }
// };
// int main()
// {
//     customer* c1=new customer("jishu",100);
//     c1->printdet();
// }
//oops
//with default constructor
// #include<bits/stdc++.h>
// using namespace std;
// class customer
// {
//     int balance;
//     string name;
//     public:
//     void setname(string s)
//     {
//         this->name=s;
//     }
//     void setbalance(int b)
//     {
//         this->balance=b;
//     }
//     void printdet()
//     {
//         cout<<balance<<endl;
//         cout<<name<<endl;
//     }
// };
// int main()
// {
//     customer c1,c2;
//     c1.setbalance(100);
//     c2.setname("Jishu");
//     c1.printdet();
//     c2.printdet();
// }
//constructor overloading
// #include<bits/stdc++.h>
// using namespace std;
// class customer
// {
//     int balance;
//     int min_balance;
//     string name;
//     public:
//     customer()
//     {
//         cout<<"Default Constructor is called"<<endl;
//     }
//     customer(string name,int balance)
//     {
//         cout<<"2 parameterized constructor is called"<<endl;
//         this->name=name;
//         if(balance>0)
//         this->balance=balance;
//         else
//         cout<<"Entre a valid Balance"<<endl;
//     }
//     customer(string name,int balance,int min_balance)
//     {
//         cout<<"3 parameterized constructor is called"<<endl;
//         this->name=name;
//         if(balance>0)
//         this->balance=balance;
//         else
//         cout<<"Entre A Valid balance"<<endl;
//         if(min_balance>0)
//         this->min_balance=min_balance;
//         else
//         cout<<"Entre a Valid Min Balance"<<endl;
//     }
//     void mini_balance(int n)
//     {
//         if(n>0){
//             this->min_balance=n;
//         }
//     }
// };
// int main()
// {
//     customer *c1=new customer("Jishu",-783);
//     customer *c2=new customer("Jishu",9000,-20);
//     customer *c3=new customer();
// }
//
//static data member
// #include<bits/stdc++.h>
// using namespace std;
// class customer
// {
//     int balance;
//     int account_no;
//     //static data member
//     static int totalc;
//     string name; 
//     public:
//     customer(string name,int balance,int account_no)
//     {
//         this->name=name;
//         this->balance=balance;
//         this->account_no=account_no;
//         totalc++;
//     }
//     //static data function
//     static void print()
//     {
//         cout<<totalc<<endl;
//     }
// };
// int customer::totalc=0;
// int main()
// {
//     customer *c1=new customer("Jishu",900,1200);
//     customer *c2=new customer("Soumyadeep",90000,322);
//     c1->print();
// }
//inheritance
//single inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class human
// {
//     protected:
//     int age;
//     string name;
//     static int count;
//     public:
//     human()
//     {

//     }
//     human(int a,string b)
//     {
//         this->age=a;
//         this->name=b;
//         count++;
//     }
//     void print()
//     {
//         cout<<"The Name is: "<<name<<endl;
//         cout<<"The Age is: "<<age<<endl;
//         cout<<"Total Human Exist: "<<count<<endl;
//     }

// };
// class student:public human
// {
//     int grade;
//     int roll;
//     string div;
//     public:
//     student(string name,int age,int grade,int roll,string div)
//     {
//         this->name=name;
//         this->age=age;
//         this->grade=grade;
//         this->roll=roll;
//         this->div=div;
//         count++;
//     }
//     void prints()
//     {
//         cout<<name<<age<<grade<<roll<<div<<endl;
//     }
// };
// int human::count=0;
// int main()
// {
//     human *h1=new human(20,"Jishu");
//     human *h2=new human(20,"Soumyadeep");
//     student *s1=new student("Koushik",23,2,12,"CSE");
//     student *s2=new student("panda",23,2,22,"TT");
//     h1->print();
//     h2->print();
//     h1->print();
//     s1->prints();
//     s2->prints();
//     s1->print();
//     s2->print();
// }
//multilevel inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class human
// {
//     protected:
//     int age;
//     string name;
//     public:
//     human()
//     {

//     }
//     human(string name,int age)
//     {
//         this->age=age;
//         this->name=name;
//     }
//     void prints()
//     {
//         cout<<name<<age<<endl;  
//     }
// };
// class adress:public human
// {
//     protected:
//     int pincode;
//     string addr;
//     public:
//     adress()
//     {
//     }
//     adress(string name,int age,int pincode)
//     {
//         this->age=age;
//         this->name=name;
//         this->pincode=pincode;
//     }
// };
// class nationality:public adress
// {
//     string counttry;
//     public:
//     nationality(string n,int a,int p,string c)
//     {
//         name=n;
//         age=a;
//         pincode=p;
//         counttry=c;
//     }
//     void prints()
//     {
//         cout<<name<<age<<pincode<<counttry<<endl;
//     }
// };
// int main()
// {
//     nationality *n1=new nationality("Jishu",20,741223,"INDIAN");
//     n1->prints();
//     n1->prints();
// }
//multiple inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class Human
// {
//     protected:
//     int age;
//     string name;
//     public:
//     inline Human(){};
//     Human(string name,int age)
//     {
//         this->name=name;
//         this->age=age;
//     }
// };
// class Engineer
// {
//     protected:
//     int cgpa;
//     string dept;
//     public:
//     inline Engineer(){};
//     inline Engineer(int c,string d):cgpa(c),dept(d){};
//     void prints()
//     {
//         cout<<cgpa<<dept<<endl;
//     }

// };
// class codeteacher:public Engineer,private Youtuber,public Human
// {

//     int package;
//     public:
//     codeteacher(string name,int age,int cgpa,string dept,int views,int subs,int package)
//     {
//         this->name=name;
//         this->age=age;
//         this->cgpa=cgpa;
//         this->dept=dept;
//         this->subs=subs;
//         this->views=views;
//         this->package=package;
//     }
//     void printsall()
//     {
//         cout<<name<<age<<cgpa<<dept<<subs<<views<<package<<endl;
//     }
// };
// class Youtuber
// {
//     protected:
//     int views;
//     int subs;
//     public:
//     inline Youtuber(){};
//     inline Youtuber(int v,int s):views(v),subs(s){};
//     void prints()
//     {
//         cout<<views<<subs<<endl;
//     }
// };
// int main()
// {
//     codeteacher *c1=new codeteacher("Jishu",20,7,"CSE",2,1,10);
//     c1->printsall();
// }
//heiarchiral inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class human
// {
//     protected:
//     int age;
//     string name;
//     public:
//     inline human(){};
//     human(string n,int a)
//     {
//         this->name=n;
//         this->age=a;
//     }
//     void prints()
//     {
//         cout<<name<<" "<<age<<endl;
//     }
// };
// class youtuber:public human
// {
//     int view;
//     int subs;
//     public:
//     youtuber(string n,int a,int v,int s)
//     {
//         this->name=n;
//         this->age=a;
//         this->view=v;
//         this->subs=s;
//     }
//     void prints()
//     {
//         cout<<name<<" "<<age<<" "<<view<<" "<<subs<<endl;
//     }
// };
// class teacher:public human
// {
//     int salary;
//     public:
//     teacher(string n,int a,int s)
//     {
//         this->name=n;
//         this->age=a;
//         this->salary=s;
//     }
//     void prints()
//     {
//         cout<<name<<" "<<age<<" "<<salary<<endl;
//     }
// };
// int main()
// {
//     youtuber *y1=new youtuber("Jishu",20,2,1);
//     y1->prints();
//     teacher *t1=new teacher("soumyadeep",20,23000);
//     t1->prints();
// }
//hybrid inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class male
// {
//     protected:
//     int salary;
//     public:
//     inline male(){};
//     inline male(int s):salary(s){};
// };
// class female
// {
//     protected:
//     int salarys;
//     public:
//     inline female(){};
//     inline female(int s):salarys(s){};
// };
// class Boy:public male
// {
//     protected:
//     int heights;
//     public:
//     inline Boy(){};
//     inline Boy(int h):heights(h){};
// };
// class girl:public female
// {
//     protected:
//     int height;
//     public:
//     inline girl(){};
//     inline girl(int h):height(h){};
// };
// class student:public virtual Boy,public virtual girl
// {
//     int grade;
//     string name;
//     string dept;
//     public:
//     student(string n,string d,int g,int salary,int height)
//     {
//         this->name=n;
//         this->dept=d;
//         this->grade=g;
//         this->height=height;
//         this->salary=salary;
//     }
//     void print()
//     {
//         cout<<name<<" "<<dept<<" "<<grade<<" "<<height<<" "<<salary<<endl;
//     }
// };
// int main()
// {
//     student *s1=new student("Jishu","CSE",2,0,6);
//     s1->print();
// }
//multipath inheritance
// #include<bits/stdc++.h>
// using namespace std;
// class human
// {
//     protected:
//     int age;
//     string name;
//     public:
//     inline human(){};
//     inline human(string n,int a):name(n),age(a){};
// };
// class engineer:public virtual human
// {
//     protected:
//     float cgpa;
//     string dept;
//     public:
//     inline engineer(){};
//     inline engineer(string d,float c):cgpa(c),dept(d){};
// };
// class youtuber:public virtual human
// {
//     protected:
//     int views;
//     int subs;
//     public:
//     inline youtuber(){};
//     inline youtuber(int v,int s):views(v),subs(s){};
// };
// class teacher:public engineer,public youtuber
// {
//     int salary;
//     public:
//     inline teacher(){};
//     teacher(string n,int a,float cg,string d,int v,int sub,int salary)
//     {
//         this->name=n;
//         this->age=a;
//         this->cgpa=cg;
//         this->dept=d;
//         this->views=v;
//         this->subs=sub;
//         this->salary=salary;
//     }
//     void prints()
//     {
//         cout<<name<<" "<<age<<" "<<cgpa<<" "<<dept<<" "<<views<<" "<<subs<<" "<<salary<<endl;
//     }
// };
// int main()
// {
//     teacher *t1=new teacher("jishu",20,6.75,"CSE",30,3,10);
//     t1->prints();
// }
//compile time polymorphism
//function overloading
// #include<bits/stdc++.h>
// using namespace std;
// class area
// {
//     public:
//     int calculatearea(int r)
//     {
//         return 3.14*r*r;
//     }
//     int calculatearea(int l,int b)
//     {
//         return l*b;
//     }
// };
// int main()
// {
//     area a1;
//     cout<<a1.calculatearea(2)<<endl;
//     cout<<a1.calculatearea(2,3);
// }
//operator overloading
// #include<bits/stdc++.h>
// using namespace std;
// class complexi
// {
//     public:
//     int real;
//     int img;
//     public:
//     inline complexi(){};
//     complexi(int real,int img)
//     {
//         this->real=real;
//         this->img=img;
//     }
//     complexi operator + (complexi &c)
//     {
//         complexi ans;
//         ans.real=real+c.real;
//         ans.img=img+c.img;
//         return ans;
//     }
//     void print()
//     {
//         cout<<real<<"+i"<<img<<endl;
//     }
// };
// int main()
// {
//     complexi c1;
//     c1.real=2;
//     c1.img=3;
//     c1.print();
//     complexi c2;
//     c2.real=5;
//     c2.img=7;
//     c2.print();
//     complexi c3=c1+c2;
//     c3.print();
// }
//runtime polymorphism
// #include<bits/stdc++.h>
// using namespace std;
// class Animal
// {
//     public:
//virtual matlab uske value ko yiha define mat karo isko runtime me define karo
//     virtual void speak()
//     {
//         cout<<"hu hu"<<endl;
//     }
//     void bath()
//     {
//         cout<<"2 days in a week"<<endl;
//     }
// };
// class Dog:public Animal
// {
//     public:
//     void speak()
//     {
//         cout<<"bauuu bauuuu"<<endl;
//     }
// };
// int main()
// {
//     Animal *a1;
//     a1=new Dog();
//     a1->speak();
//     a1->bath();
// }
//runtime polymorphism
// #include<bits/stdc++.h>
// using namespace std;
// class Animals
// {
//     public:
//     virtual void speak()
//     {
//         cout<<"hu hu"<<endl;
//     }
// };
// class Dog:public Animals
// {
//     public:
//     void speak()
//     {
//         cout<<"bou bou"<<endl;
//     }
//     void roti()
//     {
//         cout<<"2 roti in a day"<<endl;
//     }
// };
// int main()
// {
//     Animals *a1;
//     a1=new Dog();
//     a1->speak();
//     //not work bcoz a1 is initialized as Animal and roti funtion will not 
//     //work bcoz roti although is not intialize in a1 and speak function is
//     //present in both classes so speak will work 
//     a1->roti();
// }
//exception handling
// #include<bits/stdc++.h>
// using namespace std;
// class Bank
// {
//     int balance;
//     string name;
//     public:
//     Bank(string name,int balance)
//     {
//         this->name=name;
//         this->balance=balance;
//     }
//     void deposit(int amount)
//     {
//         if(amount>0){
//             balance+=amount;
//         }
//         else
//         throw "invalid amount";
//     }
//     void withdraw(int amount){
//         if(amount<0){
//             throw "invalid amount";
//         }
//         else if(amount>balance)
//         throw "Withdraw Amount should be less than balance";
//         else{
//             balance-=amount;
//         }
//     }
// };
// int main()
// {
//     Bank *b1=new Bank("Jishu",200);
//     try{
//         b1->deposit(-100);
//         b1->withdraw(600);
//     }
//     catch (const char*c){
//         cout<<"Exception Ocuured "<<c<<endl;
//     }
// }
//exception handlings
//needed to work again
// #include<bits/stdc++.h>
// using namespace std;
// class InvalidAmountError:public runtime_error
// {
//     public:
//     InvalidAmountError(const string &msg):runtime_error(msg){};
// };
// int main()
// {
//     try{
//         int p[100000000000];
//         cout<<"memory allocation is succesfull"<<endl;
//         delete []p;
//     }
//     catch(const exception &c){
//         cout<<"Exception occured: "<<c.what()<<endl;
//     }
// }
//file handling in c++
// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     //read only
//     ifstream fin;
//     fin.open("/home/grey/Documents/zoom.txt");
//     //read and remove space and EOL
//     char c;
//     fin>>c;
//     while(!fin.eof()){
//         cout<<c;
//         fin>>c;
//     }
// }
//read with space and EOL
// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     ifstream fin;
//     fin.open("/home/grey/Documents/zoom.txt");
//     char c;
//     c=fin.get();
//     while(!fin.eof()){
//         cout<<c;
//         c=fin.get();
//     }
// }
//write file
// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     ofstream fout;
//     fout.open("/home/grey/Documents/zoom.txt");
//     fout<<"Muh  me choco";
//     fout.close();
//     ifstream fin;
//     fin.open("/home/grey/Documents/zoom.txt");
//     char c;
//     c=fin.get();
//     while(!fin.eof()){
//         cout<<c;
//         c=fin.get();
//     }
//     fin.close();
// }
//append
// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     ofstream fout;
//     fout.open("/home/grey/Documents/zoom.txt",ios::app);
//     fout<<"hello There";
//     fout.close();
//     ifstream fin;
//     fin.open("/home/grey/Documents/zoom.txt");
//     char c;
//     c=fin.get();
//     while(!fin.eof()){
//         cout<<c;
//         c=fin.get();
//     }
// }
//read and write
// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     vector<string>arr(4);
//     for(int i=0;i<4;i++){
//         cout<<"Entre The String: ";
//         cin>>arr[i];
//     }
//     ofstream fout;
//     fout.open("./filehand.txt",ios::app);
//     for(int i=0;i<arr.size();i++){
//         fout<<arr[i];
//     }
//     fout.close();
//     ifstream fin;
//     fin.open("./filehand.txt");
//     char c;
//     c=fin.get();
//     while(!fin.eof()){
//         cout<<c;
//         c=fin.get();
//     }
//     fin.close();
// }
//linked list
//insertion at start
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     public:
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertionatstart(vector<int>arr,int i,int n,Node* pre)
// {
//     if(i==n){
//         return pre;
//     }
//     Node* temp=new Node(arr[i]);
//     temp->next=pre;
//     return insertionatstart(arr,i+1,n,temp);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* node;
//     Node* pre;
//     int i=0;
//     while(i<n){
//         if(i==0){
//             node=new Node(arr[i]);
//             pre=node;
//         }
//         else{
//             node=new Node(arr[i]);
//             node->next=pre;
//             pre=node;
//         }
//         i++;
//     }
//     Node* head=insertionatstart(arr,0,n,NULL);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//linked list
//insertion at end
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertionatend(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=insertionatend(arr,i+1);
//     return temp;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elements: ";
//         cin>>arr[i];
//     }
//     Node* head=insertionatend(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//insert at particular pos
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertionatend(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=insertionatend(arr,i+1);
//     return temp;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elemnt: ";
//         cin>>arr[i];
//     }
//     Node* head=insertionatend(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     cout<<endl;
//     int pos,el;
//     cout<<"Entre The pos: ";
//     cin>>pos;
//     cout<<"Entre The Value: ";
//     cin>>el;
//     if(pos==1){
//         Node* temp=new Node(el);
//         temp->next=head;
//         head=temp;
//     }
//     pos--;
//     Node* temp=head;
//     while(--pos){
//         temp=temp->next;
//     }
//     Node* tempn=new Node(el);
//     tempn->next=temp->next;
//     temp->next=tempn;
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//deletion at start
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertionatend(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=insertionatend(arr,i+1);
//     return temp;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size; ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element; ";
//         cin>>arr[i];
//     }
//     Node* head=insertionatend(arr,0);
//     Node* temp=head;
//     head=head->next;
//     delete temp;
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//deletion at end
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* insertionatend(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=insertionatend(arr,i+1);
//     return temp;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* head=insertionatend(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     cout<<endl;
//     Node* temp=head;
//     Node* pre;
//     while(temp->next!=NULL){
//         pre=temp;
//         temp=temp->next;
//     }
//     pre->next=NULL;
//     delete temp;
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//deletion at particular pos
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* createlinked(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=createlinked(arr,i+1);
//     return temp;
// }
// Node* deleteatpos(Node* head,int pos)
// {
//     if(pos==1){
//         Node* temp=head;
//         head=head->next;
//         delete temp;
//         return head;
//     }
//     pos--;
//     Node* temp=head;
//     while(--pos){
//         temp=temp->next;
//     }
//     Node* tempn=temp->next;
//     temp->next=temp->next->next;
//     return head;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* head=createlinked(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     int pos;
//     cout<<"Entre The Pos: ";
//     cin>>pos;
//     head=deleteatpos(head,pos);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//delete last node using recursion
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* createnode(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=createnode(arr,i+1);
//     return temp;
// }
// void deleteatlast(Node* head,Node* pre)
// {
//     if(!head->next){
//         pre->next=NULL;
//         delete head;
//         return; 
//     }
//     deleteatlast(head->next,head);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* head=createnode(arr,0);
//     deleteatlast(head,NULL);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//reverse a linked list
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* createlinked(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=createlinked(arr,i+1);
//     return temp;
// }
// Node* reverselinked(Node* head)
// {
//     Node* curr=head;
//     Node* pre=NULL;
//     while(curr){
//         Node* fut=curr->next;
//         curr->next=pre;
//         pre=curr;
//         curr=fut;
//     }
//     return pre;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Element: ";
//         cin>>arr[i];
//     }
//     Node* head=createlinked(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     head=reverselinked(head);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//revserse a linked list by recursive approach
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* createlinked(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=createlinked(arr,i+1);
//     return temp;
// }
// Node* reverselinked(Node* head,Node* pre)
// {
//     if(head==NULL)
//     return pre;
//     Node* fut=head->next;
//     head->next=pre;
//     return reverselinked(fut,head);
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elemnt: ";
//         cin>>arr[i];
//     }
//     Node* head=createlinked(arr,0);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
//     cout<<endl;
//     head=reverselinked(head,NULL);
//     for(Node* i=head;i!=NULL;i=i->next){
//         cout<<i->data<<" ";
//     }
// }
//middle of the linked list
// #include<bits/stdc++.h>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node* next;
//     Node(int data)
//     {
//         this->data=data;
//         this->next=NULL;
//     }
// };
// Node* createlinked(vector<int>arr,int i)
// {
//     if(i==arr.size())
//     return NULL;
//     Node* temp=new Node(arr[i]);
//     temp->next=createlinked(arr,i+1);
//     return temp;
// }
// int main()
// {
//     int n;
//     cout<<"Entre The Size: ";
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cout<<"Entre The Elemnt: ";
//         cin>>arr[i];
//     }
//     Node* head=createlinked(arr,0);
//     int count=0;
//     for(Node* i=head;i!=NULL;i=i->next)
//     count++;
//     count/=2;
//     if(count%2)
//     count++;
//     Node* temp=head;
//     while(--count){
//         temp=temp->next;
//     }
//     cout<<temp->data<<" ";
// }
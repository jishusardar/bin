//suru se surur karte hain
//print a to z
#include<iostream>
using namespace std;
int main()
{
    cout<<"The Small Letters";
    for(int i=0;i<26;i++){
        char c='a'+i;
        cout<<c<<" ";
    }
    cout<<endl;
    for(int i=0;i<26;i++){
        char c='A'+i;
        cout<<c<<" ";
    }
}
//print 10 to 1 in reverse
#include<iostream>
using namespace std;
int main(){
for(int i=10;i>0;i--){
    cout<<i<<" ";
}
}
//table of any number
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre THe Number: ";
    cin>>n;
    for(int i=0;i<10;i++){
        cout<<n<<"  ";
    }
    cout<<endl;
    for(int i=1;i<=10;i++){
        cout<<i<<"  ";
    }
    cout<<endl;
    for(int i=1;i<=10;i++){
        cout<<n*i<<"  ";
    }
}
//power of any number
#include<iostream>
using namespace std;
int main()
{
    int n;
    int m;
    cout<<"Entre THe Number: ";
    cin>>n;
    cout<<"Entre Any Power: ";
    cin>>m;
    for(int i=0;i<m-1;i++){
        n*=n;
    }
    cout<<n<<" ";
}
//sum of n natural numbers
//iterative approach
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum<<" ";
}
//recursive approach
#include<iostream>
using namespace std;
int sumof(int n)
{
    if(n==1)
    return 1;
    return n+sumof(n-1);
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    cout<<sumof(n);
}
//factorial of an number
//iterative approach
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int mul=1;
    for(int i=1;i<=n;i++){
        mul*=i;
    }
    cout<<mul<<" ";
}
//iterative approach
#include<iostream>
using namespace std;
int facto(int n)
{
    if(n==1)
    return 1;
    return n*facto(n-1);
}
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    cout<<facto(n);
}
//prime no
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    bool p=1;
    for(int i=2;i<n;i++){
        if(n%i==0){
        p=0;
        }
    }
    if(p==1)
    cout<<"The num is prime\n";
    else
    cout<<"The num is not prime\n";
}
//prime no
#include<iostream>
using namespace std;
bool prime(int n,int i)
{
    if(i<2)
    return 1;
    else if(n%i==0)
    return 0;
    return prime(n,i-1);
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    if(prime(n,n-1))
    cout<<"No is Prime";
    else
    cout<<"No is Not prime";
}
//fibonacchi series
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The N-th Term: ";
    cin>>n;
    int first=0;
    int second=1;
    if(n<=2)
    {
        if(n==1)
        cout<<first;
        else
        cout<<second;
    }
    int third;
    for(int i=2;i<n;i++){
        third=first+second;
        first=second;
        second=third;
    }
    cout<<third<<" ";
}
//fibonachi series recursive
#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n<2)
    return n;
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    cout<<"Entre The Nth Term: ";
    cin>>n;
    cout<<fibo(n);
}
//pattern printing 1
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 2
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}
//pattern printing 3
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        {
            cout<<5-i<<" ";
        }
        cout<<endl;
    }
}
//pattern printing 4
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(j+1)*(j+1)<<" ";
        }
        cout<<endl;
    }
}
//pattern printing 5
#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char c='a'+j;
            cout<<c<<" "; 
        }
        cout<<endl;
    }
}
//pattern printing 6
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            char c='a'+i;
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
//pattern printing 7
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 8
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}
//pattern printing 9
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1;
        }
        cout<<endl;
    }
}
//pattern printing 10
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=i+1;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}    
//pattern printing 11
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        char c='a'+i;
        for(int j=0;j<=i;j++){
            cout<<c;
        }
        cout<<endl;
    }
}
//pattern printing 12
#include<iostream>
using namespace std;
int main()
{
    for(int i=5;i>=1;i--){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 13
#include<iostream>
using namespace std;
int main()
{
    for(int i=5;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}
//pattern printing 14
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            cout<<5-j;
        }
        cout<<endl;
    }
}
//pattern printing 15
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 16
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<i+1;
        }
        cout<<endl;
    }
}
//pattern printing 17
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<k+1;
        }
        cout<<endl;
    }
}
//pattern printing 18
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            char c='A'+k;
            cout<<c;
        }
        cout<<endl;
    }
}
//pattern printing 19
#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<(i+1)-k;
        }
        cout<<endl;
    }
}
//pyramid
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth term: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<"*";
        }
        for(int l=0;l<i;l++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 20
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Nth term: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<k+1;
        }
        for(int l=i;l>=1;l--){
            cout<<l;
        }
        cout<<endl;
    }
}
//pattern printing 21
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth Term: ";
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<"*";
        }
        for(int l=0;l<i-1;l++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 22
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth term: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int k=0;k<2*i;k++){
            cout<<" ";
        }
        for(int l=0;l<n-i;l++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int k=0;k<2*(n-i-1);k++){
            cout<<" ";
        }
        for(int l=0;l<=i;l++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 23
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth Term: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        for(int k=0;k<2*(n-i-1);k++){
            cout<<" ";
        }
        for(int l=0;l<=i;l++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-i-1);j++){
            cout<<"*";
        }
        for(int j=0;j<2*(i+1);j++){
            cout<<" ";
        }
        for(int k=0;k<(n-i-1);k++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//pattern printing 24
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth Term: ";
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=0;j<n-i;j++){
            cout<<" ";
        }
        for(int k=0;k<i;k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
//decimal to binary
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int ans=0;
    int mul=1;
    while(n){
        int rem=n%2;
        n/=2;
        ans+=rem*mul;
        mul*=10;
    }
    cout<<ans<<" ";
}
//binary to decimal
#include<iostream>
using namespace std;
int main()
{
    int n;
    int ans=0,mul=1;
    cout<<"Entre The number: ";
    cin>>n;
    while(n){
        int rem=n%10;
        n/=10;
        ans+=rem*mul;
        mul*=2;
    }
    cout<<ans<<" ";
}
//add digits
#include<iostream>
using namespace std;
int main()
{
    int n,ans=0;
    cout<<"Entre The Number: ";
    cin>>n;
    while(n>9){
        int ans=0;
        while(n){
            int rem=n%10;
            n/=10;
            ans+=rem;
        }
        n=ans;
    }
    cout<<n;
}
//leap year
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Year: ";
    cin>>n;
    if(n%4==0&&n%100!=0)
    cout<<"leap year";
    else if(n%400==0)
    cout<<"leap Year";
    else
    cout<<"Not a leap year";
}
//reverve integer
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int ans=0;
    while(n){
        int rem=n%10;
        n/=10;
        ans=ans*10+rem;
    }
    cout<<ans;
}
//powerof 2
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The power: ";
    cin>>n;
    int ans=1;
    while(n--){
        ans*=2;
    }
    cout<<ans;
}
//sqrt of x
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number : ";
    cin>>n; 
    int start=1,end=n;
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid==n/mid){
            ans=mid;
        break;
        }
        else if(mid>n/mid){
            end=mid-1;
        }
        else{
        start=mid+1;
        ans=mid;
        }
    }
    cout<<ans;
}
//pallindrome
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int ans=0;
    int temp=n;
    while(n){
        int rem=n%10;
        n/=10;
        ans=ans*10+rem;
    }
    if(temp==ans){
        cout<<"its a pallindrome";
    }
    else
    cout<<"its not a pallindrome";
}
//compliment of a number
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Number: ";
    cin>>n;
    int ans=0;
    int mul=1;
    while(n){
        int rem=n%2;
        rem^=1;
        n/=2;
        ans+=rem*mul;
        mul*=2;
    }
    cout<<ans;
}
//convert small to capital
#include<iostream>
using namespace std;
int main()
{
    char c='a'-32;
    for(int i=0;i<26;i++){
        char d=c+i;
        cout<<d<<" ";
    }
}
//armstrong number
#include<iostream>
#include<math.h>
using namespace std;
int digits(int n)
{
    int ans=0;
    while(n){
        n/=10;
        ans++;
    }
    return ans;
}
bool armstrong(int n,int m)
{
    int temp=n;
    int ans=0;
    while(n){
      int rem=n%10;
      n/=10;
      ans+=pow(rem,m);
    }
    if(temp==ans)
    return 1;
    return 0;
}
int main()
{
    int n;
    cout<<"Entre The number: ";
    cin>>n;
    int m=digits(n);
    if(armstrong(n,m))
    cout<<"The No is armstrong";
    else
    cout<<"its not ";
}
//bishop move
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Entre The pos: ";
    cin>>n>>m;
    int ans=min(n-1,m-1)+min(8-n,m-1)+min(n-1,8-m)+min(8-n,8-m);
    cout<<ans;
}
//reverse elements
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Element: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The element: ";
        cin>>arr[i];
    }
    int start=0,end=n-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++,end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//find second max
#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]!=maxi){
            ans=max(ans,arr[i]);
        }
    }   
}
//missing number
#include<bits/stdc++.h>
using namespace std;
int missing_num(vector<int>v)
{
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        maxi=max(maxi,v[i]);
    }
    maxi=maxi*(maxi+1)/2;
    return maxi-sum;
}
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The num: ";
        cin>>v[i];
    }
    cout<<missing_num(v);
}
//fibonacci series(iterative)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The nth: ";
    cin>>n;
    if(n<2){
        cout<<n;
    }
    int res;
    int pre=0;
    int curr=1;
    for(int i=2;i<=n;i++){
        res=curr+pre;
        pre=curr;
        curr=res;
    }
    cout<<res;
}
//fibonacci (recursive)
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n)
{
    if(n<2)
    return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cout<<"Entre The Nth: ";
    cin>>n;
    cout<<fibonacci(n);
}
//rotate array by 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Number: ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int temp=arr[arr.size()-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
//sorting 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //selection sorting
    for(int i=0;i<n-1;i++){
        int index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[index])
            index=j;
        }
        swap(arr[i],arr[index]);
    }
    cout<<"After Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//bubble sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    cout<<"After Sorting"<<endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
//insertion sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The element: ";
        cin>>arr[i];
    }
}
//sqrt
#include<bits/stdc++.h>
using namespace std;
int sqrt(int x)
{
    int ans;
    int start=1,end=x-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid*mid==x)
        return mid;
        else if(mid*mid>x)
        end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int x;
    cout<<"Entre The Num: ";
    cin>>x;
    cout<<sqrt(x);
}
//peak index in mountain array
#include<bits/stdc++.h>
using namespace std;
int peakindex(vector<int>arr)
{
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
        return mid;
        else if(arr[mid]>arr[mid-1])
        start=mid+1;
        else
        end=mid-1;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<peakindex(arr);
}
//search inert position (the element is not present if present what will be its position)
#include<bits/stdc++.h>
using namespace std;
int insertpos(vector<int>arr,int x)
{
    int ans;
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[mid]>x){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The ELement: ";
        cin>>arr[i];
    }
    cout<<insertpos(arr,5);
}
//find minimum in roated array
#include<bits/stdc++.h>
using namespace std;
int findmini(vector<int>arr)
{
    int ans;
    int start=0,end=arr.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>=arr[0]){
            start=mid+1;
        }
        else{
            ans=mid;
            end=mid-1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<findmini(arr);
}
//search in rotated array
#include<bits/stdc++.h>
using namespace std;
int searchinrotated(vector<int>arr,int x)
{
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[mid]>=arr[0]){
            if(arr[mid]>x&&arr[start]<=x)
            end=mid-1;
            else
            start=mid+1;
        }
        else{
            if(arr[mid]>x&&arr[end]>=x)
            end=mid-1;
            else
            start=mid+1;
        }
    }
    return -1;
}
int seatchinrot(vector<int>arr,int target)
{
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        return mid;
        else if(arr[mid]>=arr[0]){
            if(arr[mid]>target&&arr[start]<=target)
            end=mid-1;
            else
            start=mid+1;
        }
        else{
            if(arr[mid]>target&&arr[end]>=target)
            end=mid-1;
            else
            start=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int x;
    cout<<"Entre The Element tofind: ";
    cin>>x;
    cout<<searchinrotated(arr,x);
    cout<<seatchinrot(arr,x);
}
//kth missing positive number
#include<bits/stdc++.h>
using namespace std;
int kthmissing(vector<int>arr,int k)
{
    int ans;
    int start=0,end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]-mid-1>=k){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans+k;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int k;
    cout<<"Entre The Kth Element: ";
    cin>>k;
    cout<<kthmissing(arr,k);
}
//book allocation
#include<bits/stdc++.h>
using namespace std;
int bookallocation(vector<int>arr,int s)
{
    int ans=-1;
    int start=INT_MIN,end=0;
    for(int i=0;i<arr.size();i++){
        start=max(start,arr[i]);
        end+=arr[i];
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        int pos=arr[0],count=1;
        for(int i=1;i<arr.size();i++){
            pos+=arr[i];
            if(pos>mid){
                pos=arr[i];
                count++;
            }
        }
        if(count<=s){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<bookallocation(arr,2);
}
//painter allocation
#include<bits/stdc++.h>
using namespace std;
int painterpartition(vector<int>arr,int p)
{
    int ans=-1;
    int start=INT_MIN,end=0;
    for(int i=0;i<arr.size();i++){
        start=max(start,arr[i]);
        end+=arr[i];
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        int wall=arr[0],paint=1;
        for(int i=1;i<arr.size();i++){
            wall+=arr[i];
            if(wall>mid){
                wall=arr[i];
                paint++;
            }
        }
        if(paint<=p){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<painterpartition(arr,3);
}
//ship packages
#include<bits/stdc++.h>
using namespace std;
int shippack(vector<int>arr,int s)
{
    int ans=-1;
    int start=INT_MIN;
    int end=0;
    for(int i=0;i<arr.size();i++){
        start=max(start,arr[i]);
        end+=arr[i];
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        int pack=arr[0],ship=1;
        for(int i=1;i<arr.size();i++){
            pack+=arr[i];
            if(pack>mid){
                pack=arr[i];
                ship++;
            }
        }
        if(ship<=s){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<shippack(arr,3);
}
//split array in largest sum
#include<bits/stdc++.h>
using namespace std;
int largestsum(vector<int>arr,int n)
{
    int ans=-1;
    int start=INT_MIN;
    int end=0;
    for(int i=0;i<arr.size();i++){
        start=max(arr[i],start);
        end+=arr[i];
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        int sum=arr[0],m=1;
        for(int i=1;i<arr.size();i++){
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                m++;
            }
        }
        if(m<=n){
            ans=mid;
            end=mid-1;
        }
        else
        start=mid+1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int sum;
    cout<<"Entre The sum: ";
    cin>>sum;
    cout<<largestsum(arr,sum);
}
//aggresive cows
#include<bits/stdc++.h>
using namespace std;
int agressivecows(vector<int>arr,int n)
{
    sort(arr.begin(),arr.end());
    int start=1,end=arr[arr.size()-1]-arr[0],ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        int pos=arr[0],count=1;
        for(int i=1;i<arr.size();i++){
            if(pos+mid<=arr[i]){
                count++;
                pos=arr[i];
            }
        }
        if(count<n)
        end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int cows;
    cout<<"Entre The No Of Cows: ";
    cin>>cows;
    cout<<agressivecows(arr,cows);
}
//koko eating banana
#include<bits/stdc++.h>
using namespace std;
int kokoeating(vector<int>piles,int h)
{
    int start=0;
    int end=INT_MIN;
    int ans=0;
    for(int i=0;i<piles.size();i++){
        start+=piles[i];
        end=max(end,piles[i]);
    }
    start/=h;
    while(start<=end){
        int mid=start+(end-start)/2;
        int time=0;
        for(int i=0;i<piles.size();i++){
            time+=piles[i]/mid;
            if(piles[i]%mid)
            time++;
        }
        if(time==h)
        return mid;
        else if(time>h){
            ans=mid;
            start=mid+1;
        }
        else
        end=mid-1;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Elemnts: ";
        cin>>arr[i];
    }
    int h;
    cout<<"Entre The Waiting Time: ";
    cin>>h;
    cout<<kokoeating(arr,h);
}
//two pointer
segregate 0 and 1
#include<bits/stdc++.h>
using namespace std;
void segregate(vector<int>&arr)
{
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]==1){
            if(arr[j]==0)
            swap(arr[i],arr[j]);
            else
            j--;
        }
        else{
            if(arr[j]==0)
            i++;
            else
            i++,j--;
        }
    }
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Elemnt: ";
        cin>>arr[i];
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    segregate(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
//two sums
#include<bits/stdc++.h>
using namespace std;
vector<int> twosums(vector<int>arr,int sum)
{
    vector<int>ans(2,-1);
    int i=0,j=arr.size()-1;
    sort(arr.begin(),arr.end());
    while(i<j){
        if(arr[i]+arr[j]==sum){
            ans[0]=arr[i];
            ans[1]=arr[j];
            return ans;
        }
        else if(arr[i]+arr[j]>sum){
            j--;
        }
        else
        i++;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    int sum;
    cout<<"Entre The Sum: ";
    cin>>sum;
    vector<int>ans=twosums(arr,sum);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
//pair with given difference
#include<bits/stdc++.h>
using namespace std;
vector<int> pairwithdiff(vector<int>arr,int diff)
{
    sort(arr.begin(),arr.end());
    vector<int>ans(2,-1);
    int i=0,j=1;
    while(j<arr.size()){
        if(abs(arr[i]-arr[j])==diff){
            ans[0]=arr[i];
            ans[1]=arr[j];
            return ans;
        }
        else if(abs(arr[i]-arr[j])>diff){
            i++;
        }
        else
        j++;
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre TheElement: ";
        cin>>arr[i];
    }
    int d;
    cout<<"Entre The Difference: ";
    cin>>d;
    vector<int>ans=pairwithdiff(arr,d);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
//prefix and suffix
#include<bits/stdc++.h>
using namespace std;
int prefixandsuffix(vector<int>arr)
{
    vector<int>prefix(arr.size());
    vector<int>suffix(arr.size());
    prefix[0]=arr[0];
    suffix[suffix.size()-1]=arr[arr.size()-1];
    for(int i=1;i<arr.size();i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    for(int i=arr.size()-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
    if(prefix[prefix.size()-1]==suffix[0])
    return suffix[0];
    return -1;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<prefixandsuffix(arr);
}
//kadane alogorithm
#include<bits/stdc++.h>
using namespace std;
int kadanealgo(vector<int>arr)
{
    int prefix=0;
    for(int i=0;i<arr.size();i++){
        prefix+=arr[i];
        if(prefix<0)
        prefix=0;
    }
    return prefix;
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<kadanealgo(arr);
}
//max diff between 2elements
#include<bits/stdc++.h>
using namespace std;
int maxdiff(vector<int>arr)
{
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1]-arr[0];
}
int main()
{
    int n;
    cout<<"Entre The Size: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Entre The Element: ";
        cin>>arr[i];
    }
    cout<<maxdiff(arr);
}
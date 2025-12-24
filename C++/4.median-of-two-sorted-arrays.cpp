/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        vector<int>arr(nums1.size()+nums2.size());
        int j=0;
        for(int i=0;i<nums1.size();i++){
            arr[j]=nums1[i];
            j++;
        }
        for(int i=0;i<nums2.size();i++){
            arr[j]=nums2[i];
            j++;
        }
        sort(arr.begin(),arr.end());
        if(arr.size()%2){
            ans=arr[arr.size()/2];
            return ans;
        }
        int start=0,end=arr.size()-1;
        int mid=start+(end-start)/2;
        ans=arr[mid]+arr[mid+1];
        return ans/2;
    }
};
// @lc code=end


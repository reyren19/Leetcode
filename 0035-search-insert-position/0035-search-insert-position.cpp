class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans =-1, l=0, r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) return mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
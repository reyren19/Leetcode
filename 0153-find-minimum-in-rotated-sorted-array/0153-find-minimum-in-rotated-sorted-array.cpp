class Solution {
public:
    int findMin(vector<int>& nums) {
        // first check which half is sorted and eliminate it by storing min ele of sorted half in ans
        int left=0,right=nums.size()-1,ans=INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            // left sorted
            if(nums[left]<=nums[mid]){
                ans = min(ans,nums[left]);
                left=mid+1;
            }
            else{
                ans=min(nums[mid],ans);
                right=mid-1;
            }
        }
        return ans;
    }
};
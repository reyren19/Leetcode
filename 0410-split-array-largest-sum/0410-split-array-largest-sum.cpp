class Solution {
public:
    bool canSplit(vector<int> nums, int largest, int k){
        int subarray = 0, currSum=0;
        //greedy method to find number of subarrays that have sum <= largest (mid)
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            if(currSum>largest){
                subarray++;
                currSum=nums[i];
            }
        }
        // doesnt matter if it is less we can just split a subarray to make it equal to k
        return subarray+1<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans = r;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(canSplit(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
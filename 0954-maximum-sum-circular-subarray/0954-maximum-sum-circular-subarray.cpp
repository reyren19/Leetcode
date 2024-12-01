class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // find maxsum of linear subarray using kadanes
        // find maxsum of warped subarray by doing totalSum - minSum
        // return max(maxsum, totalSum-minSum)
        int n = nums.size();
        // step 1
        int currSum=0;
        int maxSum=INT_MIN;
        for(int i=0; i<n;i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(maxSum, currSum);
        }
        int totalSum = 0;
        currSum =0;
        int minSum = INT_MAX;
        for(int i=0; i<n; i++){
            currSum = min(nums[i], currSum+nums[i]);
            minSum = min(minSum, currSum);
            totalSum += nums[i];
        }

        // if all integers negative
        if(maxSum<0) return maxSum;

        return max(maxSum, totalSum-minSum);
    }
};
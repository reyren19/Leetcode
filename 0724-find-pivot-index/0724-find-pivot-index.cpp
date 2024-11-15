class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int preSum = 0;
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        for(int i=0; i<nums.size(); i++){
            if(preSum== totalSum-preSum-nums[i]){
                return i;
            }
            preSum += nums[i];            
        }
        return -1;
    }
};
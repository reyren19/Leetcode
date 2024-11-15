class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // instead of checking for k, check for prefixSum-k, as it will be easier to look for in the hashmap
        unordered_map<int,int> mpp;
        mpp[0]=1; // storing to make sure 0 is not ommited if encountered
        int preSum = 0;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum]++;
        }
        return cnt;
    }
};
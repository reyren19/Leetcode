class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 1; // initially there will be atleast 1 sequence
        int maxCount = 0;
        if(n==0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i]==nums[i-1]+1){
                    count++;
                }
                else{
                    maxCount = max(maxCount, count);
                    count = 1;
                }
            }
        }
        return max(maxCount, count);
    }
};
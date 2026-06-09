class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int currSum = 0;
        int cnt = INT_MAX;
        while(j<nums.size()){
            currSum += nums[j];
            while(currSum >= target){
                cnt = min(cnt, j-i+1);
                currSum -= nums[i];
                i++;
            }
            j++;
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        int prevEnd = nums[0][1];
        // iterate thru the array and check if the start val of curr is less then end val, if it is cnt++

        for(int i=1;i<n;i++){
            if(nums[i][0]>=prevEnd){
                prevEnd = nums[i][1];
            }
            else {
                count++;
                prevEnd = min(prevEnd, nums[i][1]);
            }
        }
        return count;
        
    }
};
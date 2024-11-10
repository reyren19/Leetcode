class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Convert value to index
            
            // If the value at nums[index] is negative, it means we've encountered it before
            if (nums[index] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                // Mark the index as visited by negating the value at nums[index]
                nums[index] = -nums[index];
            }
        }
        
        return ans;
    }
};

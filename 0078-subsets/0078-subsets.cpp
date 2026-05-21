class Solution {
public:
    void helper(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr){
        if(ind==nums.size()){
            ans.push_back(curr);
            return; // stop since we dont want to go out of bounds
        }
        curr.push_back(nums[ind]);
        // take phase
        helper(ind+1, nums, ans, curr);
        curr.pop_back();
        helper(ind+1, nums, ans, curr);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, nums, ans, curr);
        return ans;        
    }
};

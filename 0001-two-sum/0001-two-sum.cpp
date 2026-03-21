class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]=i;
        }
        for(int i=0; i<n; i++){
            auto it = mpp.find(target-nums[i]);
            if(it != mpp.end() && it->second != i){
                return {i, it->second};
            }
        }
        return {-1,-1};
    }
};
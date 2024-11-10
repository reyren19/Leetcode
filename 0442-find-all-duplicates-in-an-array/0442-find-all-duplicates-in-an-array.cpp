class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> v(n+1,0);
        for(int i=0; i<n; i++){
            if(v[nums[i]]==1){
                ans.push_back(nums[i]);
            }
            v[nums[i]]=1;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,-1);
        vector<int> ans;
        for(int i=0; i<n; i++){
            int correctedIndex = nums[i]-1;
            v[correctedIndex] = nums[i];
        }
        for(int i=0; i<v.size(); i++){
            if(v[i]==-1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
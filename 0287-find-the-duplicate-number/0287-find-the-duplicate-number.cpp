class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        for(int i=0; i<n; i++){
            if(v[nums[i]]==1){
                return nums[i];
            }
            v[nums[i]]=1;
        }
        return -1;
    }
};
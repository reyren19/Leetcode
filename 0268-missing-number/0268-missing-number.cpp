class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1,-1);
        for(int i=0; i<n; i++){
            int correctIndex = nums[i];
            v[correctIndex] = nums[i];
        }
        for(int i=0; i<n+1; i++){
            if(v[i]==-1){
                return i;
            }
        }
        return -1;
    }
};
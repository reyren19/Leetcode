class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        bool foundNge = false;
        for(int i=0; i<n; i++){
            for(int j=(i+1)%n; j!=i; j = (j + 1) % n){
                if(nums[j]>nums[i]){
                    v.push_back(nums[j]);
                    foundNge=true;
                    break;
                }
            }
            if(foundNge==false){
                v.push_back(-1);
            }
            foundNge=false;
        }
        return v;
    }
};
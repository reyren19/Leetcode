class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int carry = 0;
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]+carry;
            carry = nums[i];
        }
        return nums;
    }
};
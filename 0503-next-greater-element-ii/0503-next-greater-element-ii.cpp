class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> v(n,-1);
        // run through the array twice
        for(int i=0; i<2*n; i++){
            while(!s.empty() && nums[s.top()]<nums[i%n]){
                v[s.top()]=nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return v;
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> v(n,-1);
        // run through the array twice
        for(int i=0; i<2*n; i++){
            /* check if the top of the array is less than the current element, if yes then put the current element as nge 
            for index at the top */
            while(!s.empty() && nums[s.top()]<nums[i%n]){
                v[s.top()]=nums[i%n];
                s.pop();
            }
            /* push current element as its nge hasnt been found */
            s.push(i%n);
        }
        return v;
    }
};
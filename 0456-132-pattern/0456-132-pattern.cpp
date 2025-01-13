class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // num1<num3<num2
        int num3=INT_MIN;
        int num2=INT_MIN;
        int n=nums.size();
        stack<int>st;
        for(int i=n-1; i>=0; --i){
            if(nums[i]<num3){
                return true;
            }
            // this while loop keeps track of both the largest and second       largest elements
            while(!st.empty() && st.top()<nums[i]){
                num3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
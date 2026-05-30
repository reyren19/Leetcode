class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        vector<int> postfix(n+1,0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        for(int i=n-1; i>=0; i--){
            postfix[i] = postfix[i+1]+nums[i];
        }

        // compare values and return the index where they are equal 
        for(int i=0; i<n; i++){
            if(prefix[i]==postfix[i+1]){
                return i;
            }
        }
        return -1;
    }
};
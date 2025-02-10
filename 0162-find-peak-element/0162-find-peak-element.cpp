class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m = l +(r-l)/2;
            // decreasing array
            if(m>0 && nums[m]<nums[m-1]){
                r=m-1;
            }
            else if(m<nums.size()-1 && nums[m]<nums[m+1]){
                l=m+1;
            }
            else{
                // middle is greater than both left and right 
                return m;
            }
        }
        return -1;
    }
};
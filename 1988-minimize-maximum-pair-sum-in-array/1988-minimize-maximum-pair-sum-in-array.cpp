class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int left = 0, right = nums.size() - 1; // Two pointers
        int maxPairSum = 0;
        
        while (left < right) {
            int pairSum = nums[left] + nums[right]; // Pair smallest and largest
            maxPairSum = max(maxPairSum, pairSum); // Track the largest pair sum
            left++;
            right--;
        }
        
        return maxPairSum; // Return the minimized maximum pair sum
    }
};

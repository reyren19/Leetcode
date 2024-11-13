class NumArray {
private:
    vector<int> prefixSum;

public:
    // Constructor to initialize the NumArray with the given nums array
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0);  // Create a prefixSum array with size n+1
        
        // Populate the prefixSum array
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    // Function to return the sum of elements between indices left and right
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

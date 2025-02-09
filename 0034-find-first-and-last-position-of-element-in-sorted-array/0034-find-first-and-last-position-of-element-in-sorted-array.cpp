class Solution {
public:
int getFirstOcc(vector<int>& nums, int target){
    int leftMost = -1, low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {  // Ensure we're moving towards the first occurrence
            if (nums[mid] == target) leftMost = mid;
            high = mid - 1;  // Move left
        } else {
            low = mid + 1;
        }
    }
    return leftMost;
}

int getLastOcc(vector<int>& nums, int target){
    int rightMost = -1, low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {  // Ensure we're moving towards the last occurrence
            if (nums[mid] == target) rightMost = mid;
            low = mid + 1;  // Move right
        } else {
            high = mid - 1;
        }
    }
    return rightMost;
}
  
    vector<int> searchRange(vector<int>& nums, int target) {
        /* 
        1 Find first occ
        2 Find last occ
        3 Add in vector and return
        */
        vector<int>ans;
        ans.push_back(getFirstOcc(nums,target));
        ans.push_back(getLastOcc(nums,target));
        return ans;
    }
};
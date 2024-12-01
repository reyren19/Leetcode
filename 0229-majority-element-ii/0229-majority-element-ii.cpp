class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> elements;
        int count1 = 0, count2 = 0; // Track counts for two candidates
        int candidate1 = 0, candidate2 = 0;
        int n = nums.size();

        // First pass: Identify potential candidates
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1 = 1;
            } else if (count2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                count2 = 1;
            } else if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        // Second pass: Validate the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        if (count1 > n / 3) elements.push_back(candidate1);
        if (count2 > n / 3) elements.push_back(candidate2);

        return elements;
    }
};

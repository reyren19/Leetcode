class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // define a min heap
        priority_queue<int,vector<int>,greater<int>>minHeap;
        // keep adding to the heap till size > k
        for(int i=0; i<nums.size(); i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        // now we have our minHeap ready, return the top
        return minHeap.top();
    }
};
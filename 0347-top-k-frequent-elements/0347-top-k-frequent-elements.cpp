class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        // make a minheap so we can eliminate the least ones 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto it: freq){
            minHeap.push({it.second, it.first}); // since greater<> compares the first of the element first
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
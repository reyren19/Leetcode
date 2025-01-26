class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>mh;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            mh.push({it.second, it.first});
            if(mh.size()>k){
                mh.pop();
            }
        }
        while(!mh.empty()){
            v.push_back(mh.top().second);
            mh.pop();
        }
        return v;
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++){
            if(ans.size()==0 || intervals[i].front()>ans.back().back()){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back().back()=max(ans.back().back(), intervals[i].back());
            }
        }
        return ans;
    }
};
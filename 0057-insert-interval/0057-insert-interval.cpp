class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        int n = arr.size();
        vector<vector<int>> ans;
        int i=0;
        // Loop for insertion of all elements before the newInterval 
        while(i<n && arr[i][1]<newInterval[0]){
            ans.push_back(arr[i]);
            i++;
        }
        // Loop to merge the overallping elements with new interval, see how many intervals newInterval can absorb
        while(i<n && arr[i][0]<=newInterval[1]){
            newInterval[0] = min(arr[i][0], newInterval[0]);
            newInterval[1] = max(arr[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }
};
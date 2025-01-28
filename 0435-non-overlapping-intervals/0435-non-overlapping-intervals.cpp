class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevEnd = intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(intervals[i][0]>=prevEnd){
                prevEnd = intervals[i][1];
            }
            else{
                count++;
                // to make sure that earliest ending interval is taken to minimize overlaps
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            i++;
        }
        return count;
    }
};

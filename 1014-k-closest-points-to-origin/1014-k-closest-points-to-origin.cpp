class Solution {
public:
    int calculateDistance(int x, int y){
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,vector<int>>>pq;
        for(int i=0; i<points.size(); i++){
            pq.push({calculateDistance(points[i][0], points[i][1]), points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
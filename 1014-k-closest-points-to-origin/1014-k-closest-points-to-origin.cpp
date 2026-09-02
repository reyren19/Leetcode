class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            int da = a[0]*a[0] + a[1]*a[1];
            int db = b[0]*b[0] + b[1]*b[1];
            return da < db; // gives the larger among the 2 points in heap
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>maxHeap(cmp); // maxheap so we can eliminate farthest
        for(int i=0; i<points.size(); i++){
            maxHeap.push(points[i]);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return ans;
    }
};
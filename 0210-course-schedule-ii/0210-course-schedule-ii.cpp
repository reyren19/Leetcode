class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n,0);
        vector<int> courseOrder;
        for(auto e: edges){
            int a = e[1];
            int b = e[0];
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(--indegree[it]==0){
                    q.push(it);
                }
            }
            courseOrder.push_back(node);
        }
        if(courseOrder.size()==n) return courseOrder;
        return {};
    }
};
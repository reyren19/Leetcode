class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> dist(n,1e9);
        // {stops, {src, distance}}
        queue<pair<int,pair<int,int>>> q;
        for(auto f: flights){
            // u = [{v,distance from src}];
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(cost+edgeW < dist[adjNode] && k>=stops){
                    dist[adjNode] = cost+edgeW;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};
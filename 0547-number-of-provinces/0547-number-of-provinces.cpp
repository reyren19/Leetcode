class Solution {
public:
    void dfs(unordered_map<int, vector<int>> adj, int starting, vector<int> &visited){
        visited[starting] =1;
        for(int &v: adj[starting]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        int count = 0;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if((i!=j) && (isConnected[i][j]==1)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};
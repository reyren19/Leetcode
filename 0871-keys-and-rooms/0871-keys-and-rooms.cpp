class Solution {
public:
    void dfs(vector<vector<int>> rooms, int u, vector<bool> &vis){
        vis[u] = true;
        for(auto it: rooms[u]){
            if(!vis[it]){
                dfs(rooms, it, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<bool> vis(V,false);
        dfs(rooms, 0, vis);
       for(int i=0; i<vis.size(); i++){
        if(!vis[i]){
            return false;
        }
       }
       return true;
    }
};
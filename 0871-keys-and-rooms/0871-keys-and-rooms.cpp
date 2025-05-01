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
        // begin at 0, pick up its keys, move to those rooms, pick up their keys, etc
        dfs(rooms, 0, vis);
       for(int i=0; i<vis.size(); i++){
        if(!vis[i]){
            return false;
        }
       }
       return true;
    }
};
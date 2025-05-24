class Solution {
public:
    bool check(int start,vector<vector<int>> graph, vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                //iterate over neighbors, if no color assigned assign the opposing color
                if(color[it]==-1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if color same as parent, return false as graph cant be bipartite
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V,-1);
        for(int i=0; i<V; i++){
            // if color is -1 that means it is unvisited 
            if(color[i]==-1){
                if(check(i,graph,color)==false){
                return false;
                }
            }
        }
        return true;
    }
};
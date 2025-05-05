class Solution {
public:
    void dfs(int sr, int sc, int color, int sColor, vector<vector<int>>& image, vector<vector<int>>& vis){
        int n = image.size();
        int m = image[0].size();
        vis[sr][sc]=1;
        image[sr][sc]=color;

        int dRow[] = {-1, 0, 1,  0};
        int dCol[] = { 0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int adjRow = sr+dRow[i];
            int adjCol = sc+dCol[i];
            if(adjRow>=0 && adjRow < n && adjCol >= 0 && adjCol <m && !vis[adjRow][adjCol] && image[adjRow][adjCol]==sColor){
                dfs(adjRow, adjCol, color, sColor, image, vis);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        dfs(sr,sc,color,image[sr][sc],image,vis);
        return image;
    }
};
class Solution {
private:
        void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m = grid[0].size();
        // check if the cell isnt invalid
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1){
            return;
        }
        if(grid[i][j]!=1){
            return;
        }
        int dR[4]={-1,0,1,0};
        int dC[4]={0,-1,0,1};
        grid[i][j]=2;
        vis[i][j]=1;
        for(int x=0; x<4; x++){
            dfs(i+dR[x], j+dC[x], grid, vis);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        // running dfs on all the borders to convert O to Xs
        for(int i=0; i<n; i++){
            // first cell of each row
            dfs(i, 0, grid, vis);
            // last cell of each row
            dfs(i, m-1, grid, vis);
        }

        for(int j=0; j<m; j++){
            // that column cell in the first row
            dfs(0,j, grid, vis);

            // that column cell in the last row
            dfs(n-1, j, grid, vis);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    cnt++;
                }
                else if(grid[i][j]==2){
                    grid[i][j]=1;
                }
            }
        }
        return cnt;
    }
};
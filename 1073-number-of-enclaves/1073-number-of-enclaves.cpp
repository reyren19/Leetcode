class Solution {
private:
        void dfs(int i, int j, vector<vector<int>>& grid){
        int n=grid.size();
        int m = grid[0].size();
        // check if the cell isnt invalid
        if(i<0 || i>=n || j<0 || j>=m){
            return;
        }
        if(grid[i][j]!=1){
            return;
        }
        int dR[4]={-1,0,1,0};
        int dC[4]={0,-1,0,1};
        grid[i][j]=2;
        for(int x=0; x<4; x++){
            dfs(i+dR[x], j+dC[x], grid);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        // running dfs on all the borders to convert 1 to 2
        for(int i=0; i<n; i++){
            // first cell of each row
            dfs(i, 0, grid);
            // last cell of each row
            dfs(i, m-1, grid);
        }

        for(int j=0; j<m; j++){
            // that column cell in the first row
            dfs(0,j, grid);

            // that column cell in the last row
            dfs(n-1, j, grid);
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
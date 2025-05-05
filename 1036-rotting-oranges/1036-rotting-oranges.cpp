class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int mins =0;
        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dR[4]={-1,0,1,0}, dC[4]={0,1,0,-1};
        // bfs type loop to check for neighboring oranges and rot them, using fresh>0 to make sure mins++ only happens if any rotting is happening
        while(!q.empty() && fresh>0){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nR = r+dR[i];
                    int nC = c+dC[i];
                    if(nR >= 0 && nR<n && nC>=0 && nC<m && grid[nR][nC]==1){
                        grid[nR][nC]=2;
                        fresh--;
                        q.push({nR,nC});
                    }
                }
            }
            mins++;
        }
        return (fresh==0?mins:-1);
    }
};
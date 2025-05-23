class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n=board.size();
        int m = board[0].size();
        // check if the cell isnt invalid
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1){
            return;
        }
        if(board[i][j]!='O'){
            return;
        }
        int dR[4]={-1,0,1,0};
        int dC[4]={0,-1,0,1};
        board[i][j]='#';
        vis[i][j]=1;
        for(int x=0; x<4; x++){
            dfs(i+dR[x], j+dC[x], board, vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        // running dfs on all the borders to convert O to Xs
        for(int i=0; i<n; i++){
            // first cell of each row
            dfs(i, 0, board, vis);
            // last cell of each row
            dfs(i, m-1, board, vis);
        }

        for(int j=0; j<m; j++){
            // that column cell in the first row
            dfs(0,j, board, vis);

            // that column cell in the last row
            dfs(n-1, j, board, vis);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
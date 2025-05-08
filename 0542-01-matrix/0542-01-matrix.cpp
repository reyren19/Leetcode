class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        // Initialize queue with all zero cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dR[4] = {-1, 0, 1,  0};
        int dC[4] = { 0, 1, 0, -1};

        // BFS
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int row = front.first.first;
            int col = front.first.second;
            int d   = front.second;

            dist[row][col] = d;

            for (int i = 0; i < 4; i++) {
                int nr = row + dR[i];
                int nc = col + dC[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        return dist;
    }
};

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n, vector<int>(n,1e9));
        for(auto e:edges){
            int u = e[0];
            int w = e[1];
            int wt = e[2];
            matrix[u][w] = wt;
            matrix[w][u]=wt;
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix.size(); j++){
                if(i==j) matrix[i][j]=0;
            }
        }

        // applying floyd warshall
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j]=min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                }
            }
        }

        unordered_map<int,int> cnts;
        int bestCount=INT_MAX;
        int answer = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=distanceThreshold){
                    cnts[i]++;
                }
            }
        }

        for(int i=0; i<cnts.size(); i++){
            if(cnts[i]<bestCount || (cnts[i]==bestCount && i>answer)){
                bestCount = cnts[i];
                answer = i;
            }
        }
        return answer;
    }
};
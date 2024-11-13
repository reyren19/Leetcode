class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // columns
        bool isFirstRowZero = false; // extra space so that overlap doesnt happen 
        // loop for marking which rows and columns have to be set to zero
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(matrix[i][j]==0){
                    // set its column value to zero 
                    matrix[0][j] = 0;

                    // set its row value to zero
                    if(i>0){
                        matrix[i][0]=0;
                    }
                    else{
                        isFirstRowZero = true;
                    }
                }
            }
        }

        // setting all rows and columns marked from 1 to n to zero
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    // set to zero
                    matrix[i][j]=0;
                }
            }
        }

        // finally checking for the first row and column
        if(matrix[0][0]==0){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }

        if(isFirstRowZero){
            for(int i=0; i<m; i++){
                matrix[0][i]=0;
            }
        }
        
    }
};
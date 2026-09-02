class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /* construct tuple pq
        push first element of each row 
        process those elements (pop+push next element from that row)
        repeat until u get the kth element */
        // minheap of {value,row,col}
        int n = matrix.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq;
        for(int r=0; r<min(n,k); r++){ pq.push({matrix[r][0], r, 0});} // seeding with first col
        int cnt = 0;
        while(true){
            auto[val,row,col] = pq.top();
            pq.pop();
            cnt++;
            if(cnt==k) return val;
            // adding next from col
            if(col+1 <n) {
                pq.push({matrix[row][col+1], row, col+1});
            }
        }
        return INT_MAX;
    }
};
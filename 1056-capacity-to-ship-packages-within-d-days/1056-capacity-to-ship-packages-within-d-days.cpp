class Solution {
public:
    bool canShip(vector<int> weights, int D, int cap){
        int days = 1;
        int currWt = 0;
        for(int wt: weights){
            if(currWt+wt>cap){
                days++;
                currWt=0;
            }
            currWt += wt;
        }
        return days <= D;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        // max of this will be the sum of all weights 
        int right = accumulate(weights.begin(), weights.end(),0); 
        while(left<right){
            int mid = left+(right-left)/2;

            if(canShip(weights, days, mid)){
                // search for a lighter weight
                right = mid;
            }
            else{
                // search for a heavier weight
                left=mid+1;
            }
        }
        return left;
    }
};
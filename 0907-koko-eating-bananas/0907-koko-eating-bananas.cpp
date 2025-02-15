class Solution {
public:
    bool canEat(vector<int> arr, int n, int h){
        int totalHours = 0;
        for(int i=0; i<arr.size(); i++){
            totalHours += ceil((double)arr[i]/n);
            if(totalHours>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(canEat(piles,mid,h)){
                ans = mid;
                right = mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
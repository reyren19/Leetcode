class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int minHeight = INT_MAX;
        int l=0,h=height.size()-1;
        while(l<h){
            minHeight = min(height[l], height[h]);
            maxWater = max(maxWater, minHeight*abs(h-l));
            if(height[h]<height[l]){
                h--;
            }
            else{
                l++;
            }
        }
        return maxWater;
    }
};
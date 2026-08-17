class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int area = INT_MIN;
        while(j>i){
        int length = min(height[i], height[j]);
        int breadth = j-i;
        area = max(length*breadth, area);
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
        }
        return area;
    }
};
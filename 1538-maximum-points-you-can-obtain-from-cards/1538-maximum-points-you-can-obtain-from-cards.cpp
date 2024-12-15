class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // Thought process- remove the minsum of n-k subarray and you will have the max score
        int totalScore = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        int windowSize = n-k;
        int currSum = 0;
        int minSum = INT_MAX;
        int i=0,j=0;
        while(j<n){
            currSum += cardPoints[j];
            if(j-i+1>windowSize){
                currSum -= cardPoints[i];
                i++;
            }
            if(j-i+1==windowSize){
                minSum = min(currSum,minSum);
            }
            j++;
        }
        return totalScore-minSum;
    }
};
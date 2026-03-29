class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], profit = INT_MIN;
        for(int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i]-minPrice);
        }
        return profit;
    }
};
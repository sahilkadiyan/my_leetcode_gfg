class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int profit = 0;
        for(int i = 1; i < size(prices); i++)
            if(prices[i] > prices[i-1])              // yesterday was valley, today is peak
                profit += prices[i] - prices[i-1];   // buy yesterday, sell today
        return profit;
        
    }
};
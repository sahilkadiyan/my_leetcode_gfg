class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minimum=prices[0];
        for(int i=1;i<prices.size();i++){
           profit=max(profit,prices[i]-minimum);//5
           minimum=min(minimum,prices[i]); //minimum=1
        }
        return profit;
    }
};
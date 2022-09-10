class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+2,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=k;j>=0;j--){
                for(int l=1;l>=0;l--){
                    if(l){
                        dp[i][j][1]=max(dp[i+1][j+1][0]+prices[i],dp[i+1][j][1]);
                    }
                    else{
                        dp[i][j][0]=max(dp[i+1][j][1]-prices[i],dp[i+1][j][0]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};
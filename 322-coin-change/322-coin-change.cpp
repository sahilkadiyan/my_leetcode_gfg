class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        

       int dp[amount+1];
        //because there is no way to amount to 0
        for(int i=0;i<=amount;i++){
            dp[i]=amount+1;
        }
         dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                  int sub_res=dp[i-coins[j]];
                    if(sub_res!=amount+1)
                        dp[i]=min(dp[i],sub_res+1);
                    }
                    
                }
                
            }
        
     return dp[amount] > amount ? -1 : dp[amount];
    }
};
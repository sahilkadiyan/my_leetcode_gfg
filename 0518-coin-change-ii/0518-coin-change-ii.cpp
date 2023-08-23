class Solution {
public:
    int recursion(int index,int amount,vector<int> &coins){
        if(index==0){
            return (amount%coins[0]==0);
        }
        int notTake=recursion(index-1,amount,coins);
        int take=0;
        if(coins[index]<=amount) take=recursion(index,amount-coins[index],coins);
        return notTake+take;
    }
    
      int memo(int index,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(index==0){
            return (amount%coins[0]==0);
        }
          if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=recursion(index-1,amount,coins);
        int take=0;
        if(coins[index]<=amount) take=recursion(index,amount-coins[index],coins);
        return dp[index][amount]=notTake+take;
    }
    
    int tabu(int amount , vector<int> &coins,vector<vector<int>> &dp){
        int n=coins.size();
        for(int i=0;i<=amount;i++){
            dp[0][i]=(i%coins[0]==0);    
        }
        
        for(int index=1;index<n;index++){
            for(int t=0;t<=amount;t++){
                int notTake=dp[index-1][t];
                int take=0;
                if(coins[index]<=t) take=dp[index][t-coins[index]];
                dp[index][t]=notTake+take;
            }
        }
        
        return dp[n-1][amount];
        
    }
    
 
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // return memo(n-1,amount,coins,dp);
        // return recursion(n-1,amount,coins);
        return tabu(amount,coins,dp);
    }
};
class Solution {
public:
    
    //recursion 
//     int helper(int amount,int n,vector<int> & coins){
//           if(amount==0) return 1;
//         if(n==0) return 0;
//         int res=helper(amount,n-1,coins);
//         //when we include the last coin here we don't reduce n to n-1 because we have unlimited supply of coins 
        
//         if(coins[n-1]<=amount)
//             res=res+helper(amount-coins[n-1],n,coins);
//         return res;
        
//     }
//     int change(int amount, vector<int>& coins) {
//       if(coins.size()==0) return 0;
//         if(amount==0) return 1;
        
//      int n=coins.size();
//         return helper(amount,n,coins);
//     }
    
    
    //tabulation method
    int helper(int amount,int n,vector<int> & coins){
        int dp[amount+1][n+1];
        //the entry corresponding to dp[i][j] corresponds to the number of combinations or the number of ways that we can make to choose the coins that sums equal to that amount 
        //amount corresponds to the row and n corresponds to the column 
        //so when amount is equal to zero then there is one way i.e don't pick any coin so there is 1 way so fill the first row by 1 value each 
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }
        //and when n is equal to 0 then there is no way to pick any coin 
        //fill the column zero with 0 values each
        for(int i=0;i<=amount;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=amount;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1]; 
                //when we don't include the jth coin the simply put this value equal to dp[i][j];
                if(coins[j-1]<=i){
                    dp[i][j]+=dp[i-coins[j-1]][j]; //when we include the coin so we need to subtract that value from the sum that we are taking in and do not decrement j because we have unlimited supply of coins 
                }
            }
        }
        return dp[amount][n];
        
    }
    
    
     int change(int amount, vector<int>& coins) {
//       if(coins.size()==0) return 0;
//         if(amount==0) return 1;
        
     int n=coins.size();
        return helper(amount,n,coins);
    }
    
    
};
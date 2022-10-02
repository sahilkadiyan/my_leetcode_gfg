class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>>dp(2,vector<int>(target+1,0));
        for( int face =1; face <=min(k,target); face++)
          dp[0][face] = 1;

        for(int dice = 2; dice <=n;dice ++) {
            for(int face = 1; face <=k; face++) {
                for( int i = face; i<= target;i++) {
                        dp[1][i] += dp[0][i-face];
                        dp[1][i]%=mod;
                }
            }
            swap(dp[0],dp[1]);
            fill(dp[1].begin(),dp[1].end(),0);
        }

        return dp[0][target];
    }
};
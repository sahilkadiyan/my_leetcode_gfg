class Solution {
public:
    int f(int i,int j,vector<vector<int>>& triangle,int m,vector<vector<int> > &dp){
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i==m-1) return triangle[i][j];
        int down=triangle[i][j]+f(i+1,j,triangle,m,dp);
        int diagonal=triangle[i][j]+f(i+1,j+1,triangle,m,dp);
        return dp[i][j]=min(down,diagonal);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        return f(0,0,triangle,m,dp);
        
    }
};